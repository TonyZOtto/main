#include "PixmapStack.h"

#include <QPainter>

#include <QQRect.h>

PixmapStack::PixmapStack() {}

PixmapStack::PixmapStack(const QQSize aImageSize,
                         const Qt::AspectRatioMode aQARM)
    : mImageSize(aImageSize), mQARM(aQARM) {;}

Count PixmapStack::count() const
{
    return rawCount() - User;
}

Count PixmapStack::rawCount() const
{
    return mStack.count();
}

bool PixmapStack::isValid() const
{
    return mImageSize.isValid() && mImageSize.notEmpty();
}

bool PixmapStack::isEmpty() const
{
    return mStack.isEmpty();
}

QPixmap PixmapStack::back() const
{
    QPixmap result;
    if (count() > BackImage)
        result = mStack[BackImage];
    return result;
}

QPixmap PixmapStack::at(const Index ix) const
{
    return rawAt(ix + User);
}

QPixmap PixmapStack::rawAt(const Index ix) const
{
    QPixmap result;
    if (isValidIndex(ix))
        result = mStack[ix];
    return result;
}

BasePhoto PixmapStack::at(const Index ix, const Photo::Type aType) const
{
    return BasePhoto(aType, at(ix));
}

QPixmap PixmapStack::resolve() const
{
    QPixmap result(imageSize());
    QPainter tPainter(&result);
    tPainter.fillRect(QQRect(imageSize()), Qt::black);
    for (Index ix = 0; ix < Index(rawCount()); ++ix)
        tPainter.drawPixmap(0, 0, rawAt(ix));
    tPainter.end();
    return result;
}

void PixmapStack::set(const QQSize aImageSize, const Qt::AspectRatioMode aQARM)
{
    set(aImageSize);
    set(aQARM);
}

void PixmapStack::back(const QColor aColor)
{
    mBackColor = aColor;
    QPixmap tFillPixmap(mImageSize);
    tFillPixmap.fill(mBackColor);
    if (isEmpty())
        mStack.push(tFillPixmap);
    else
        mStack[BackColor] = tFillPixmap;
}

bool PixmapStack::isValidIndex(const Index ix) const
{
    return ix >= 0 && ix < Index(count());
}
