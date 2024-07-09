#pragma once
#include "ozPhoto.h"

#include <QImage>

#include <QQPoint.h>
#include <QQSize.h>

class OZPHOTO_EXPORT BasePhoto
{
public: // types
    enum Type
    {
        $null           = QImage::Format_Invalid,
        Grey            = QImage::Format_Grayscale8,
        Color           = QImage::Format_ARGB32,
        Index           = QImage::Format_Indexed8,
        $startNonQImage,
        YPlane,
        CrPlane,
        CbPlane,
        $max
    };

public: // ctors
    BasePhoto();
    BasePhoto(const BasePhoto &other);

public: // const
    QImage baseImage() const;
    QQPoint center() const;
    QQSize size() const;
    BasePhoto scaledCrop(const QQSize aCropSize,
        const unsigned minScale=4, const unsigned maxScale=4);

public: // non-const
    void set(const BasePhoto &rhs);
    QImage & baseImage();
    void scale(const signed aRatio);

public: // virtual const
    virtual Type type() const;
    virtual bool isPlanar() const;

public: // static
    static bool isPlanar(const Type aType);

private:
    Type mType=$null;
    QImage mBaseImage;
};

inline QImage BasePhoto::baseImage() const { return mBaseImage; }
inline QImage & BasePhoto::baseImage() { return mBaseImage; }
inline BasePhoto::Type BasePhoto::type() const { return mType; }
