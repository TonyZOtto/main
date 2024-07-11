#include "GreyPhoto.h"

GreyPhoto::GreyPhoto() {;}
GreyPhoto::GreyPhoto(const BasePhoto &other) : BasePhoto(other) {;}

bool GreyPhoto::isPlanar() const
{
    return true;
}


