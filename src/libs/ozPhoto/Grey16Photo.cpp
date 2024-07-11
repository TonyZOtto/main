#include "Grey16Photo.h"
#include "ozPhoto.h"

Grey16Photo::Grey16Photo() {}
Grey16Photo::Grey16Photo(const BasePhoto &other) : BasePhoto(other) {;}

bool OZPHOTO_EXPORT Grey16Photo::isPlanar() const
{
    return true;
}

