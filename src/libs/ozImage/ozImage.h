#ifndef OZIMAGE_H
#define OZIMAGE_H

#include "ozImage_global.h"

#include "SupportedFormats.h"

class OZIMAGE_EXPORT ozImage
{
public:
    ozImage();

public: // static
    SupportedFormats readFormats();
    SupportedFormats writeFormats();

private: // static
};

#endif // OZIMAGE_H
