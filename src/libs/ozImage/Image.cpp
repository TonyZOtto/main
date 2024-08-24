#include "Image.h"

Image::Image(QObject *parent) : QObject{parent} {;}


QImage::Format Image::qformat(const Image::Type aType)
{
    QImage::Format result = QImage::Format_Invalid;
    switch (aType)
    {
    case Grey:      result = QImage::Format_Grayscale8;     break;
    case Grey16:    result = QImage::Format_Grayscale16;    break;
    case Color:     result = QImage::Format_ARGB32;         break;
    case Index:
    case YPlane:
    case CrPlane:
    case CbPlane:   result = QImage::Format_Indexed8;       break;
    case $null:
    case $startNonQImage:
    case $max:      /* leave _Invalid */                    break;
    };
    return result;
}

// static
bool Image::isPlanar(const Image::Type aType)
{
    bool result = false;
    if (aType == Grey)          result = true;
    if (aType == Grey16)        result = true;
    if (aType == Index)         result = true;
    if (aType == YPlane)        result = true;
    if (aType == CrPlane)       result = true;
    if (aType == CbPlane)       result = true;
    return result;
}
