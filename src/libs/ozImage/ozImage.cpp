#include "ozImage.h"

#include <QImageReader>
#include <QImageWriter>

ozImage::ozImage() {;}

SupportedFormats ozImage::readFormats()
{
    return SupportedFormats(SupportedFormats::Read,
                            QImageReader::supportedImageFormats());
}

SupportedFormats ozImage::writeFormats()
{
    return SupportedFormats(SupportedFormats::Write,
                            QImageWriter::supportedImageFormats());
}



