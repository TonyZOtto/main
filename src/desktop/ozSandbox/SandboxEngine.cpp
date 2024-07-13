#include "SandboxEngine.h"

#include <QColor>

#include <QQSize.h>

#include "SandboxApplication.h"
#include "SandboxScene.h"

SandboxEngine::SandboxEngine(SandboxApplication *parent)
    : QObject(parent)
    , mpApplication(parent)
{
    qInfo() << Q_FUNC_INFO;
    setObjectName("SandboxEngine");
}

void SandboxEngine::initialize()
{
    qInfo() << Q_FUNC_INFO;

}

void SandboxEngine::setup()
{
    qInfo() << Q_FUNC_INFO;
    setupColorTable();
    setSubjectPhoto(mSubjectPhoto);
}

void SandboxEngine::setSubjectPhoto(const ColorPhoto &aCP)
{
    qInfo() << Q_FUNC_INFO;
    mSubjectPhoto.set(aCP.baseImage().copy(scene()->viewRect().toQRect()));
    mGrey16Photo = Grey16Photo(mSubjectPhoto);
    BrightnessContrast tBC = processHistogram(mGrey16Photo);
    mIndexPhoto = IndexPhoto(mGrey16Photo, tBC);
    mIndexPhoto.baseImage().setColorTable(mColorTable);
//    scene()->set(SandboxScene::OldSubject, mIndexPhoto);
    scene()->set(SandboxScene::OldSubject, mSubjectPhoto);
}

SandboxScene *SandboxEngine::scene()
{
    return app()->scene();
}

QObject *SandboxEngine::object()
{
    return parent();
}

BrightnessContrast SandboxEngine::processHistogram(const Grey16Photo aGrey16Photo)
{
    qInfo() << Q_FUNC_INFO;
    BrightnessContrast result;

    // Gather Histogram
    WORD * pGrey16Data = (WORD *)aGrey16Photo.baseImage().constBits();
    const Count nPixel = QQSize(aGrey16Photo.baseImage().size()).area();
    Count kPixel = 0;
    do
    {
        const WORD cGrey16Pixel = *pGrey16Data++;
        mGrey8Histogram.add(cGrey16Pixel >> 8);
    } while (++kPixel < nPixel);

    // Trim tails from histogram
    const Count cTailBinCount = nPixel / 16;
    const Index cAllBinCount = mGrey8Histogram.binCount();
    Count tTailCount = 0;
    Index tBinIndex = 0;
    while (tTailCount < cTailBinCount && tBinIndex < cAllBinCount)
        tTailCount += mGrey8Histogram[tBinIndex++];
    const BYTE tLoBin = tBinIndex;

    tTailCount = 0;
    tBinIndex = cAllBinCount - 1;
    while (tTailCount < cTailBinCount && tBinIndex > 0)
        tTailCount += mGrey8Histogram[tBinIndex--];
    const BYTE tHiBin = tBinIndex;

    result.set(tLoBin, tHiBin);
    return result;
}

void SandboxEngine::setupColorTable()
{
    mColorTable.fill(QColor(Qt::transparent).rgba(), 256);
    setupColorTableLinear(  0,  15, 240, /* Bronze */
        QQColor(0x99, 0x5F, 0x22), QQColor(0xFF, 0x9F, 0x42));
    setupColorTableLinear(120, 135, 240, /* Silver */
        QQColor(0x90, 0x90, 0x90), QQColor(0xF0, 0xF0, 0xF0));
    setupColorTableLinear(240, 255, 240, /* Gold */
        QQColor(0xC0, 0xA6, 0x00), QQColor(0xFF, 0xFF, 0x3F));
    setupColorTableBilinear( 16, 119, 160, /* Sand */
                            QQColor(0xD6, 0xB0, 0x69),
                            QQColor(0xEC, 0xCC, 0xA2),
                            QQColor(0xFF, 0xF0, 0xDB));
    setupColorTableBilinear(136, 239, 80, /* Water */
                            QQColor(0x00, 0x80, 0x80),
                            QQColor(0x00, 0x00, 0xB0),
                            QQColor(0xB6, 0xD0, 0xE2));
}

void SandboxEngine::setupColorTableLinear(const BYTE aFrom,
                                          const BYTE aTo,
                                          const BYTE aOpacity,
                                          const QQColor aLoColor,
                                          const QQColor aHiColor)
{
    QColor tColor;
    tColor.setAlpha(aOpacity);
//    const QQColor cColorDelta = aHiColor.subtracted(aLoColor);
    const float cIxDeltaF = aTo - aFrom;
    const float cRedLo = aLoColor.redF(),   cRedHi = aHiColor.redF();
    const float cGrnLo = aLoColor.greenF(), cGrnHi = aHiColor.greenF();
    const float cBluLo = aLoColor.blueF(),  cBluHi = aHiColor.blueF();
    const float cRedDelta = cRedHi - cRedLo;
    const float cGrnDelta = cGrnHi - cGrnLo;
    const float cBluDelta = cBluHi - cBluLo;
    for (Index ix = aFrom, ixd = 0; ix <= aTo; ++ix, ++ixd)
    {
        const float cDltF = float(ixd) * cIxDeltaF;
        const float cRedF = cRedLo + cDltF * cRedDelta;
        const float cGrnF = cGrnLo + cDltF * cGrnDelta;
        const float cBluF = cBluLo + cDltF * cBluDelta;
        tColor.setRedF(cRedF), tColor.setGreenF(cGrnF), tColor.setBlueF(cBluF);
        const QRgb cRgba = tColor.rgba();
        mColorTable[ix] = cRgba;
    }
}

void SandboxEngine::setupColorTableBilinear(const BYTE aFrom,
                                            const BYTE aTo,
                                            const BYTE aOpacity,
                                            const QQColor aLoColor,
                                            const QQColor aMidColor,
                                            const QQColor aHiColor)
{
    const BYTE cMidIx = aFrom + aTo / 2;
    setupColorTableLinear(aFrom, cMidIx, aOpacity, aLoColor, aMidColor);
    mColorTable[cMidIx] = qRgba(aMidColor.red(), aMidColor.green(),
                                aMidColor.blue(), aOpacity);
    setupColorTableLinear(aTo, cMidIx, aOpacity, aHiColor, aMidColor);
}

