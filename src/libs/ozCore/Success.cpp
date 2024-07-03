#include "Success.h"

Success::Success()
{
    invalidate();
}

Success::operator =(const bool aIs)
{
    set(aIs);
    return isTrue();
}

bool Success::test() const
{
    return isInvalid() || isTrue();
}

bool Success::expect(const bool aIs)
{
    if (aIs) Boolean::set(aIs);
    return test();
}
