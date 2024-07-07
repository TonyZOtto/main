#pragma once
#include "ozPhoto.h"

#include <QImage>

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

public: // virtual const
    virtual Type type() const;
    virtual bool isPlanar() const = 0;


private:
    Type mType=$null;
    QImage mBaseImage;
};

inline BasePhoto::Type BasePhoto::type() const { return mType; }
