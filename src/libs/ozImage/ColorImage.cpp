#include "ColorImage.h"

ColorImage::ColorImage() {}
ColorImage::ColorImage(const BaseImage &other)  : BaseImage(other) {;}

bool ColorImage::isPlanar() const
{
    return false;
}
