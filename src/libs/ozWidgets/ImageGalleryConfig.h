#pragma once

#include <QSharedDataPointer>

class ImageGalleryConfigData;

class ImageGalleryConfig
{
public: // const
    QString title() const;

public: // QSharedDataPointer
    ImageGalleryConfig();
    ImageGalleryConfig(const ImageGalleryConfig &);
    ImageGalleryConfig &operator=(const ImageGalleryConfig &);
    ~ImageGalleryConfig();

private:
    QSharedDataPointer<ImageGalleryConfigData> data;
};
