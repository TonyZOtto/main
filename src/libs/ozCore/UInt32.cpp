#include "UInt32.h"

AText UInt32::hex(const bool usePrefix) const
{
    AText result(NibbleSize, 'F');
    QByteArray tBytes((const char *)(&mU32), sizeof(Type));
    result.setRight(tBytes.toHex());
    result.setUpper();
    if (usePrefix) result.prepend("0x");
    return result;
}
