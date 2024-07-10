#pragma once
#include "ozPhoto.h"

#include "BasePhoto.h"

class OZPHOTO_EXPORT IndexPhoto : public BasePhoto
{
public:
    IndexPhoto();
    IndexPhoto(const BasePhoto &other);

public: // virtual const
    virtual bool isPlanar() const;

};
