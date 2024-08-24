#pragma once
#include "ozImage.h"

#include <BrightnessContrast.h>

#include "BaseImage.h"
#include "Grey16Photo.h"

class OZIMAGE_EXPORT IndexedImage : public BaseImage
{
public:
    IndexedImage();
    IndexedImage(const QImage aIndexImage);
    IndexedImage(const BaseImage &other);
    IndexedImage(const Grey16Image &aGrey16,
               const BrightnessContrast aBC);

public: // non-const
    void set(const Grey16Image &aGrey16,
             const BrightnessContrast aBC);

public: // virtual const
    virtual bool isPlanar() const;

};
