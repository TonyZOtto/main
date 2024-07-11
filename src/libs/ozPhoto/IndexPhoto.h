#pragma once
#include "ozPhoto.h"

#include <BrightnessContrast.h>

#include "BasePhoto.h"
#include "Grey16Photo.h"

class OZPHOTO_EXPORT IndexPhoto : public BasePhoto
{
public:
    IndexPhoto();
    IndexPhoto(const BasePhoto &other);
    IndexPhoto(const Grey16Photo &aGrey16,
               const BrightnessContrast aBC);

public: // non-const
    void set(const Grey16Photo &aGrey16,
             const BrightnessContrast aBC);

public: // virtual const
    virtual bool isPlanar() const;

};
