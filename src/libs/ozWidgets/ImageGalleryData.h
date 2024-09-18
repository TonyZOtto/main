#pragma once
#include "ozWidgets.h"

#include <QSharedDataPointer>

class ImageGalleryDataData;

class OZWIDGETS_EXPORT ImageGalleryData
{
public: // const

public: // non-const
    void viewPixelSize(const QQSize sz);

public: // QSharedDataPointer
    ImageGalleryData();
    ImageGalleryData(const ImageGalleryData &);
    ImageGalleryData &operator=(const ImageGalleryData &);
    ~ImageGalleryData();
private:
    QSharedDataPointer<ImageGalleryDataData> data;
};
