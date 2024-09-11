#pragma once

#include <QSharedDataPointer>

class ImageGalleryDataData;

class ImageGalleryData
{
public:
    ImageGalleryData();
    ImageGalleryData(const ImageGalleryData &);
    ImageGalleryData &operator=(const ImageGalleryData &);
    ~ImageGalleryData();

private:
    QSharedDataPointer<ImageGalleryDataData> data;
};
