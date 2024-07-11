#pragma once
#include "ozPhoto.h"

#include <QImage>

#include <QQPoint.h>
#include <QQSize.h>

#include "Photo.h"

class OZPHOTO_EXPORT BasePhoto
{
public: // ctors
    BasePhoto();
    BasePhoto(const Photo::Type aType, const QImage &aQImage);
    BasePhoto(const BasePhoto &other);

public: // const
    QImage baseImage() const;
    QQPoint center() const;
    QQSize size() const;
    BasePhoto scaledCrop(const QQSize aCropSize,
        const unsigned minScale=4, const unsigned maxScale=4);

public: // non-const
    void set(const BasePhoto &rhs);
    void set(const QImage &aQImage);
    QImage & baseImage();
    void scale(const signed aRatio);

public: // virtual const
    virtual Photo::Type type() const;
    virtual bool isPlanar() const;


private:
    Photo::Type mType=Photo::$null;
    QImage mBaseImage;
};

inline QImage BasePhoto::baseImage() const { return mBaseImage; }
inline QImage & BasePhoto::baseImage() { return mBaseImage; }
inline Photo::Type BasePhoto::type() const { return mType; }
