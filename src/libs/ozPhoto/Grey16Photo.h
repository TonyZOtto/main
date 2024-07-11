#pragma once
#include "ozPhoto.h"

#include "BasePhoto.h"

class OZPHOTO_EXPORT Grey16Photo : public BasePhoto
{
public:
    Grey16Photo();
    Grey16Photo(const BasePhoto &other);

public: // virtual const
    virtual bool isPlanar() const;

};
