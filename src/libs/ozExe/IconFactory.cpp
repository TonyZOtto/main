#include "IconFactory.h"

#include <QFileInfo>

#include <Success.h>

IconFactory::IconFactory(QObject *parent)
    : QObject{parent}
{
    setObjectName("ozExe:IconFactory");
}

void IconFactory::createIcon(const Key &aIconKey, const QQSize aSize)
{
    Q_UNUSED(aIconKey); Q_UNUSED(aSize);
    Q_ASSERT(!"MUSTDO"); // MUSTDO create(key)
}
/*
bool IconFactory::baseDir(const QDir &aBaseDir)
{
    Success success;
    mBaseDir.nullify();
    QQDir tBaseDir = aBaseDir;
    if (tBaseDir.isNull())
    {
        success = false;
    }
    else if (tBaseDir.notExists())
    {
        success.expect(tBaseDir.mkpath("."));
        if (success.test()) success.expect(tBaseDir.cd("."));
        QFileInfo tBaseFI(tBaseDir.toQDir(), "");
        if (success.test()) success.expect(tBaseFI.isWritable());
    }
    if (success)
        mBaseDir = tBaseDir;
    return success;
}
*/
/*
    QIcon result;
    QQSize cSize = aKey.square();
    const int cWidth = cSize.width();
    const int cHeight = cSize.height();
    QPixmap tBasePixmap(cSize);
    QRect tBaseRect(QPoint(0,0), cSize);
    QPainterPath tBasePath;
    tBasePath.moveTo(6,  2);
    tBasePath.lineTo(cWidth - 6,  2);
    tBasePath.arcTo(cWidth - 10, 2, 4, 4, 90, -90);
    tBasePath.lineTo(cWidth - 6, cHeight - 6);
    tBasePath.arcTo(cWidth - 10, cHeight - 10, 4, 4, 0, -90);
    tBasePath.lineTo(6, cHeight - 6);
    tBasePath.arcTo(2, cHeight - 10, 4, 4, 270, -90);
    tBasePath.lineTo(2, 6);
    tBasePath.arcTo(2, 2, 4, 4, 180, -90);
    QBrush tTransparentBrush(Qt::transparent);
    QBrush tBaseBrush(Qt::darkGray);
    QPen tBlackPen(Qt::black);
    QPainter tBasePainter(&tBasePixmap);
    tBasePainter.fillRect(tBaseRect, tTransparentBrush);
    tBasePainter.setPen(tBlackPen);
    tBasePainter.setBrush(tBaseBrush);
    tBasePainter.drawPath(tBasePath);
    tBasePainter.end();
    result.addPixmap(tBasePixmap);
    return result;
*/
