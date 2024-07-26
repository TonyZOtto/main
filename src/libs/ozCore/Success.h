//!file {ottoZcode}/src/libs/ozCore/Success.h Successful operation
#pragma once
#include "ozCore.h"

#include "Boolean.h"

/* Use Case
 *
 *  bool doThings()
 *  {
 *      Success success;
 *      success.expect(doThing1());
 *      if (success.test())     success.expect(doThing2());
 *      if (success.test())     success.expect(doThing3());
 *      return success;
 *  }
 *
 */

class OZCORE_EXPORT Success : public Boolean
{
public: // ctors
    Success();  // invalid
    operator = (const bool aIs);

public: // const
    bool test() const;
    operator bool () const { return isTrue(); }

public: // non-const
    bool expect(const bool aIs);
    bool expect(const Success aSuccess);
};
