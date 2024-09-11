#include "ImageGalleryItem.h"

Seq ImageGalleryItem::smCurrentSeq = 0;

// QSharedData
ImageGalleryItem::ImageGalleryItem()
    : data(new ImageGalleryItemData)
{}

ImageGalleryItem::ImageGalleryItem(const ImageGalleryItem &rhs)
    : data{rhs.data}
{}

ImageGalleryItem &ImageGalleryItem::operator=(const ImageGalleryItem &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

ImageGalleryItem::~ImageGalleryItem() {}
