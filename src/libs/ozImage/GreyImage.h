#pragma once
#include "ozImage.h"

#include "BaseImage.h"

class OZIMAGE_EXPORT GreyImage : public BaseImage
{
public:
    GreyImage();
    GreyImage(const BaseImage &other);

public: // virtual const
    virtual bool isPlanar() const;

};
