#include "Boolean.h"


bool Boolean::is(const bool aValue) const
{
    return (valid() && (value() == aValue));
}

bool Boolean::isTrue() const
{
    return is(true);
}

bool Boolean::notTrue() const
{
    return is(false);
}

bool Boolean::isNull() const
{
    return ( ! value() && ! valid());
}

bool Boolean::notNull() const
{
    return ! isNull();
}

bool Boolean::isInvalid() const
{
    return value() && ! valid();
}

bool Boolean::notInvalid() const
{
    return ! isInvalid();
}

void Boolean::set()
{
    value(true), valid(true);
}

void Boolean::set(const bool aValue)
{
    value(aValue), valid(true);
}

void Boolean::set(const bool aValue, const bool aValid)
{
    value(aValue), valid(aValid);
}

void Boolean::reset()
{
    value(false), valid(true);
}

void Boolean::nullify()
{
    value(false), valid(false);
}

void Boolean::invalidate()
{
    value(true), valid(false);
}
