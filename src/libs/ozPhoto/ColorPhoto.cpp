#include "ColorPhoto.h"

ColorPhoto::ColorPhoto() {}
ColorPhoto::ColorPhoto(const BasePhoto &other)  : BasePhoto(other) {;}

bool ColorPhoto::isPlanar() const
{
    return false;
}
