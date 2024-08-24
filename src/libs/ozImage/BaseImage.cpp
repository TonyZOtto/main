#include "BaseImage.h"

#include <SCRect.h>

BaseImage::BaseImage() : mType(Image::$null) {;}
BaseImage::BaseImage(const Image::Type aType, const QImage &aQImage)
    : mType(aType)
    , mBaseImage(aQImage.convertedTo(Image::qformat(type()))) {;}
BaseImage::BaseImage(const Image::Type aType, const QPixmap &aPixmap)
    : mType(aType)
    , mBaseImage(aPixmap.toImage().convertedTo(Image::qformat(type()))) {;}
BaseImage::BaseImage(const BaseImage &other)
    : mType(other.type())
    , mBaseImage(other.baseImage().convertedTo(Image::qformat(type()))) {;}

QQPoint BaseImage::center() const
{
    return baseImage().rect().center();
}

QQSize BaseImage::size() const
{
    return baseImage().size();
}

BaseImage BaseImage::scaledCrop(const QQSize aCropSize,
    const unsigned int minScale, const unsigned int maxScale)
{
    BaseImage result(*this);
    if (size() == aCropSize) return result;             /*===\*/

    signed tRatio = size().factor(aCropSize);
    if (0 == tRatio)
    {
        const SCRect cCropRect(aCropSize, center());
        result.baseImage() = result.baseImage().copy(cCropRect.toQRect());
        return result;                                  /*===\*/
    }

    QQSize tResize;
    if (tRatio < 0)
        tRatio = qMax(tRatio, - (signed)minScale);
    else
        tRatio = qMin(tRatio, (signed)maxScale);
    result.scale(tRatio);
    return result;
}

void BaseImage::set(const BaseImage &rhs)
{
    mType = rhs.type();
    mBaseImage = rhs.baseImage();
}

void BaseImage::set(const QImage &aQImage)
{
    mBaseImage = aQImage.convertedTo(Image::qformat(type()));
}

void BaseImage::scale(const signed int aRatio)
{
    QQSize tNewSize = size();
    if (aRatio < 0)
        tNewSize /= ( - aRatio);
    else if (aRatio > 0)
        tNewSize *= aRatio;
    baseImage() = baseImage().scaled(tNewSize);
}

bool BaseImage::isPlanar() const
{
    return Image::isPlanar(mType);
}

