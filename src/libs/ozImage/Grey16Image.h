#pragma once
#include "ozImage.h"

#include "BaseImage.h"

class OZIMAGE_EXPORT Grey16Image : public BaseImage
{
public:
    Grey16Image();
    Grey16Image(const BaseImage &other);

public: // virtual const
    virtual bool isPlanar() const;

};
