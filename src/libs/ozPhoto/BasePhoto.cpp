#include "BasePhoto.h"

#include <SCRect.h>

BasePhoto::BasePhoto() : mType(Photo::$null) {;}
BasePhoto::BasePhoto(const Photo::Type aType, const QImage &aQImage)
    : mType(aType)
    , mBaseImage(aQImage.convertedTo(Photo::qformat(type()))) {;}
BasePhoto::BasePhoto(const Photo::Type aType, const QPixmap &aPixmap)
    : mType(aType)
    , mBaseImage(aPixmap.toImage().convertedTo(Photo::qformat(type()))) {;}
BasePhoto::BasePhoto(const BasePhoto &other)
    : mType(other.type())
    , mBaseImage(other.baseImage().convertedTo(Photo::qformat(type()))) {;}

QQPoint BasePhoto::center() const
{
    return baseImage().rect().center();
}

QQSize BasePhoto::size() const
{
    return baseImage().size();
}

BasePhoto BasePhoto::scaledCrop(const QQSize aCropSize,
    const unsigned int minScale, const unsigned int maxScale)
{
    BasePhoto result(*this);
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

void BasePhoto::set(const BasePhoto &rhs)
{
    mType = rhs.type();
    mBaseImage = rhs.baseImage();
}

void BasePhoto::set(const QImage &aQImage)
{
    mBaseImage = aQImage.convertedTo(Photo::qformat(type()));
}

void BasePhoto::scale(const signed int aRatio)
{
    QQSize tNewSize = size();
    if (aRatio < 0)
        tNewSize /= ( - aRatio);
    else if (aRatio > 0)
        tNewSize *= aRatio;
    baseImage() = baseImage().scaled(tNewSize);
}

bool BasePhoto::isPlanar() const
{
    return Photo::isPlanar(mType);
}

