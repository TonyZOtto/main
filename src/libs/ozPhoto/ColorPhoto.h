#pragma once
#include "ozPhoto.h"

#include "BasePhoto.h"

class OZPHOTO_EXPORT ColorPhoto : public BasePhoto
{
public:
    ColorPhoto();

public: // virtual const
    virtual bool isPlanar() const;

};
