#pragma once
#include "ozPhoto.h"

#include "BasePhoto.h"

class OZPHOTO_EXPORT GreyPhoto : public BasePhoto
{
public:
    GreyPhoto();

public: // virtual const
    virtual bool isPlanar() const;

};
