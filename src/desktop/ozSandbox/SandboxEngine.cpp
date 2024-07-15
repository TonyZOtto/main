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
}

void SandboxEngine::setSubjectPhoto(const ColorPhoto &aCP)
{
    qInfo() << Q_FUNC_INFO;
    const QImage cColorImage
        = aCP.baseImage().copy(scene()->viewRect().toQRect());
    mSubjectPhoto.set(cColorImage);
    QMultiMap<WORD, QQPoint> mGreyPointMMap;
    SCRect cImageRect(cColorImage.rect());
    QQSize cImageSize = cImageRect.size();
    Count cPixelCount = cImageSize.area();
    QImage tIndexImage(cImageSize, QImage::Format_Indexed8);
    tIndexImage.setColorTable(mColorTable);
    QRgb * pRgbPixel = (QRgb *)cColorImage.constBits();
    Q_CHECK_PTR(pRgbPixel);
    for (Index ix = 0; ix < Index(cPixelCount); ++ix)
    {
        const QQPoint cPt(cImageSize, ix);
        const QRgb cRgb = *pRgbPixel++;
        const float cGreyF = ((float(qRed(cRgb))   / 255.0) * 0.2989)
                           + ((float(qGreen(cRgb)) / 255.0) * 0.5870)
                           + ((float(qBlue(cRgb))  / 255.0) * 0.1140);
        tIndexImage.setPixel(cPt, qRound(255.0 * cGreyF));
    }
    qInfo() << "Saving IndexImage.png:"
            << tIndexImage.save("IndexImage.png");
    mIndexPhoto = IndexPhoto(tIndexImage);
    scene()->set(SandboxScene::OldSubject, mIndexPhoto);
//    scene()->set(SandboxScene::OldSubject, mSubjectPhoto);
}

SandboxScene *SandboxEngine::scene()
{
    return app()->scene();
}

QObject *SandboxEngine::object()
{
    return parent();
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
#if 1
    setupColorTableLinear( 16, 119, 255, /* Sand */
                            QQColor( 72,  72,  16),
                            QQColor( 72,  72, 119));
#else
    setupColorTableBilinear( 16, 119, 160, /* Sand */
                            QQColor(0x00, 0x20, 0x20),
                            QQColor(0x00, 0x50, 0x50),
                            QQColor(0x50, 0x70, 0x70));
#endif
#if 1
    setupColorTableLinear(136, 239, 255, /* Water */
                            QQColor(136, 180, 180),
                            QQColor(239, 180, 180));
#else
    setupColorTableBilinear(136, 239, 80, /* Water */
                            QQColor(0xD6, 0xB0, 0x69),
                            QQColor(0xEC, 0xCC, 0xA2),
                            QQColor(0xFF, 0xF0, 0xDB));
#endif
#if 1
    for (Index ix = 0; ix < 255; ix += 8)
        qDebug() << Qt::dec << ix << Qt::hex
                 << mColorTable[ix+0] << mColorTable[ix+1]
                 << mColorTable[ix+2] << mColorTable[ix+3]
                 << mColorTable[ix+4] << mColorTable[ix+5]
                 << mColorTable[ix+6] << mColorTable[ix+7];
#endif
}

void SandboxEngine::setupColorTableLinear(const BYTE aFrom,
                                          const BYTE aTo,
                                          const BYTE aOpacity,
                                          const QQColor aLoColor,
                                          const QQColor aHiColor)
{
    QColor tColor;
    tColor.setAlpha(aOpacity);
    const float cIxDeltaF = aTo - aFrom,
                cRedLo = aLoColor.redF(),   cRedHi = aHiColor.redF(),
                cGrnLo = aLoColor.greenF(), cGrnHi = aHiColor.greenF(),
                cBluLo = aLoColor.blueF(),  cBluHi = aHiColor.blueF();
    const float cRedDelta = (cRedHi - cRedLo) / cIxDeltaF,
                cGrnDelta = (cGrnHi - cGrnLo) / cIxDeltaF,
                cBluDelta = (cBluHi - cBluLo) / cIxDeltaF;
    float tDltF = 0.0;
    for (Index ix = aFrom; ix <= aTo; ++ix)
    {
        const float cRedF = cRedLo + tDltF * cRedDelta,
                    cGrnF = cGrnLo + tDltF * cGrnDelta,
                    cBluF = cBluLo + tDltF * cBluDelta;
        tColor.setRedF(cRedF), tColor.setGreenF(cGrnF), tColor.setBlueF(cBluF);
        const QRgb cRgba = tColor.rgba();
        mColorTable[ix] = cRgba;
        tDltF += 1.0;
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
    setupColorTableLinear(aFrom,  cMidIx, aOpacity, aLoColor, aMidColor);
    setupColorTableLinear(cMidIx, aTo,    aOpacity, aMidColor, aHiColor);
    mColorTable[cMidIx] = aMidColor.rgb();
}

#if 0
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
#endif
