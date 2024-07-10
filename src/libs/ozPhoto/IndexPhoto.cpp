#include "IndexPhoto.h"

IndexPhoto::IndexPhoto() {}
IndexPhoto::IndexPhoto(const BasePhoto &other) : BasePhoto(other) {;}

bool IndexPhoto::isPlanar() const
{
    return true;
}
