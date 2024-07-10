#include "BasePhoto.h"

#include <SCRect.h>

BasePhoto::BasePhoto() : mType($null) {;}
BasePhoto::BasePhoto(const Type aType, const QImage &aQImage)
    : mType(aType)
    , mBaseImage(aQImage.convertedTo(qformat(type()))) {;}
BasePhoto::BasePhoto(const BasePhoto &other)
    : mType(other.type())
    , mBaseImage(other.baseImage().convertedTo(qformat(type()))) {;}

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
    mBaseImage = aQImage.convertedTo(qformat(type()));
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
    return isPlanar(mType);
}

QImage::Format BasePhoto::qformat(const Type aType)
{
    QImage::Format result = QImage::Format_Invalid;
    switch (aType)
    {
    case Grey:      result = QImage::Format_Grayscale8; break;
    case Color:     result = QImage::Format_ARGB32;     break;
    case Index:
    case YPlane:
    case CrPlane:
    case CbPlane:   result = QImage::Format_Indexed8;   break;
    case $null:
    case $startNonQImage:
    case $max:      /* leave _Invalid */                break;
    };
    return result;
}

// static
bool BasePhoto::isPlanar(const Type aType)
{
    bool result = false;
    if (aType == Grey)          result = true;
    if (aType == Index)         result = true;
    if (aType == YPlane)        result = true;
    if (aType == CrPlane)       result = true;
    if (aType == CbPlane)       result = true;
    return result;
}
