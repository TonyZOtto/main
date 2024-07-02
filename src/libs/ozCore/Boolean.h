//!file {Eclipse6}/root/src/libs/eirBase6/Boolean.h Tri-value bool
#pragma once
#include "ozCore.h"

class OZCORE_EXPORT Boolean
{
/*
 *      Result:     mValue  mValid
 *                  false   false       null
 *                  true    false       invalid
 *                  false   true        false
 *                  true    true        true
 */
public:
    Boolean() { nullify(); }
    Boolean(const bool aValue) { set(aValue); }
    Boolean(const bool aValue, const bool aValid) { set(aValue, aValid); }

public: // const
    bool value() const;
    bool valid() const;
    bool is(const bool aValue) const;
    bool isTrue() const;
    bool notTrue() const;
    bool isNull() const;
    bool notNull() const;
    bool isInvalid() const;
    bool notInvalid() const;


public: // non-const
    void value(const bool aValue);
    void valid(const bool aValid);
    void set();
    void set(const bool aValue);
    void set(const bool aValue, const bool aValid);
    void reset();
    void nullify();
    void invalidate();

private:
    bool mValue=false;
    bool mValid=false;
};

inline bool Boolean::value() const { return mValue; }
inline bool Boolean::valid() const { return mValid; }
inline void Boolean::value(const bool aValue) { mValue = aValue; }
inline void Boolean::valid(const bool aValid) { mValid = aValid; }
