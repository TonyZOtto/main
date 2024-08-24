#pragma once

#include <QSharedDataPointer>

class ImageGalleryConfigData;

class ImageGalleryConfig
{
public:
    ImageGalleryConfig();
    ImageGalleryConfig(const ImageGalleryConfig &);
    ImageGalleryConfig &operator=(const ImageGalleryConfig &);
    ~ImageGalleryConfig();

private:
    QSharedDataPointer<ImageGalleryConfigData> data;
};
