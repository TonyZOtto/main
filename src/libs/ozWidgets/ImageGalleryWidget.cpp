#include "ImageGalleryWidget.h"

ImageGalleryWidget::ImageGalleryWidget(const ImageGalleryConfig &cfg,
                                       QWidget *parent)
{
    setObjectName("ImageGalleryWidget:" + cfg.title());
}

void ImageGalleryWidget::add(const ImageGalleryItem &item)
{
    Q_ASSERT(!"MUSTDO"); // MUSTDO ImageGalleryWidget::add()
    Q_UNUSED(item);
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

void ImageGalleryWidget::setup()
{
    Q_ASSERT(!"MUSTDO"); // MUSTDO ImageGalleryWidget::setup()

}
