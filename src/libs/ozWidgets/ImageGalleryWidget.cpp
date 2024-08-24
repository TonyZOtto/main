#include "ImageGalleryWidget.h"

ImageGalleryWidget::ImageGalleryWidget(const ImageGalleryConfig &cfg,
                                       QWidget *parent)
{
    setObjectName("ImageGalleryWidget:" + cfg.data->d_title);
}

void ImageGalleryWidget::setup()
{

}
