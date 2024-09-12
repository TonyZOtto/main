#include "ImageGalleryWidget.h"

ImageGalleryWidget::ImageGalleryWidget(QWidget *parent)
    : QWidget(parent)
//    , mpConfig(new ImageGalleryConfig(this))
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
    calculate();
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

void ImageGalleryWidget::select(const QQPoint cellPoint)
{
    Q_ASSERT(!"MUSTDO"); // MUSTDO ImageGalleryWidget::select(pt)
    Q_UNUSED(cellPoint);

}

void ImageGalleryWidget::deselect()
{
    Q_ASSERT(!"MUSTDO"); // MUSTDO ImageGalleryWidget::deselect(all)

}

void ImageGalleryWidget::deselect(const QQPoint cellPoint)
{
    Q_ASSERT(!"MUSTDO"); // MUSTDO ImageGalleryWidget::deselect(pt)
    Q_UNUSED(cellPoint);

}

void ImageGalleryWidget::calculate()
{
    calculateViewGeometry();
}

void ImageGalleryWidget::calculateViewGeometry()
{
    //if (config()->ViewPixelSize().isEmpty())
    {

    }
}


