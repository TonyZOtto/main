#include "ImageGalleryWidget.h"

ImageGalleryWidget::ImageGalleryWidget(QWidget *parent)
    : QWidget(parent)
{
    setObjectName("ImageGalleryWidget");
}

void ImageGalleryWidget::initialize()
{

}

void ImageGalleryWidget::configure()
{

}

void ImageGalleryWidget::setup()
{

}

void ImageGalleryWidget::add(const ImageGalleryItem &item)
{
    Q_ASSERT(!"MUSTDO"); // MUSTDO ImageGalleryWidget::add()
    Q_UNUSED(item);
}


QQPoint ImageGalleryWidget::append(const ThumbImage aThumb)
{
    Q_ASSERT(!"MUSTDO"); // MUSTDO ImageGalleryWidget::add()
    Q_UNUSED(aThumb);
    return QQPoint();
}

void ImageGalleryWidget::select(const QQPoint pt)
{
    Q_ASSERT(!"MUSTDO"); // MUSTDO ImageGalleryWidget::select(pt)
    Q_UNUSED(pt);

}

void ImageGalleryWidget::deselect()
{
    Q_ASSERT(!"MUSTDO"); // MUSTDO ImageGalleryWidget::deselect(all)

}

void ImageGalleryWidget::deselect(const QQPoint pt)
{
    Q_ASSERT(!"MUSTDO"); // MUSTDO ImageGalleryWidget::deselect(pt)
    Q_UNUSED(pt);

}


