#pragma once
#include "ozPhoto.h"

#include "BasePhoto.h"

class OZPHOTO_EXPORT ColorPhoto : public BasePhoto
{
public: // ctors
    ColorPhoto();
    ColorPhoto(const BasePhoto &other);

public: // virtual const
    virtual bool isPlanar() const;

};
