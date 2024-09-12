#pragma once
#include "ozWidgets.h"

#include <QSharedDataPointer>

class ImageGalleryDataData;

class OZWIDGETS_EXPORT ImageGalleryData
{
public:
    ImageGalleryData();
    ImageGalleryData(const ImageGalleryData &);
    ImageGalleryData &operator=(const ImageGalleryData &);
    ~ImageGalleryData();

private:
    QSharedDataPointer<ImageGalleryDataData> data;
};
