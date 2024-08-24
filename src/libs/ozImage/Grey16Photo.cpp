#include "Grey16Photo.h"
#include "ozImage.h"

Grey16Image::Grey16Image() {}
Grey16Image::Grey16Image(const BaseImage &other) : BaseImage(other) {;}

bool OZIMAGE_EXPORT Grey16Image::isPlanar() const
{
    return true;
}

