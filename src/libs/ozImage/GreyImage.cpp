#include "GreyImage.h"

GreyImage::GreyImage() {;}
GreyImage::GreyImage(const BaseImage &other) : BaseImage(other) {;}

bool GreyImage::isPlanar() const
{
    return true;
}


