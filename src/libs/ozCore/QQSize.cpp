#include "QQSize.h"


int QQSize::area() const
{
    return isValid() ? (width() * height()) : -1;
}
