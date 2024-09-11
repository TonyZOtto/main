#include "ImageGalleryData.h"

#include <SCRect.h>

class ImageGalleryDataData : public QSharedData
{
public:
    SCRect              dSceneRect;
    SCRect              dOriginViewRect;
    SCRect              dCurrentViewRect;
    QQSize              dViewPixelSize;

};

ImageGalleryData::ImageGalleryData()
    : data(new ImageGalleryDataData)
{}

ImageGalleryData::ImageGalleryData(const ImageGalleryData &rhs)
    : data{rhs.data}
{}

ImageGalleryData &ImageGalleryData::operator=(const ImageGalleryData &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

ImageGalleryData::~ImageGalleryData() {}
