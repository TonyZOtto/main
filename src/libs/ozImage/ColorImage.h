#pragma once
#include "ozImage.h"

#include "BaseImage.h"

class OZIMAGE_EXPORT ColorImage : public BaseImage
{
public: // ctors
    ColorImage();
    ColorImage(const BaseImage &other);

public: // virtual const
    virtual bool isPlanar() const;

};
