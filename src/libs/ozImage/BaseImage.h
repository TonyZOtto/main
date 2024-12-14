#pragma once
#include "ozImage.h"

#include <QImage>
#include <QPixmap>

#include <QQPoint.h>
#include <QQSize.h>

#include "Image.h"

class OZIMAGE_EXPORT BaseImage
{
public: // ctors
    BaseImage();
    BaseImage(const Image::Type aType, const QImage &aQImage);
    BaseImage(const Image::Type aType, const QPixmap &aPixmap);

public: // const
    QImage baseImage() const;
    QQPoint center() const;
    QQSize size() const;
    BaseImage scaledCrop(const QQSize aCropSize,
        const unsigned minScale=4, const unsigned maxScale=4);

public: // non-const
    void set(const BaseImage &rhs);
    void set(const QImage &aQImage);
    QImage & baseImage();
    void scale(const signed aRatio);

public: // virtual const
    virtual Image::Type type() const;
    virtual bool isPlanar() const;


private:
    Image::Type mType=Image::$null;
    QImage mBaseImage;
};

inline QImage BaseImage::baseImage() const { return mBaseImage; }
inline QImage & BaseImage::baseImage() { return mBaseImage; }
inline Image::Type BaseImage::type() const { return mType; }
