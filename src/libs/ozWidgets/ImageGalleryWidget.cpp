#include "ImageGalleryWidget.h"

#include <QGridLayout>
#include <QLabel>

ImageGalleryWidget::ImageGalleryWidget(QWidget *parent)
    : QWidget(parent)
{
    setObjectName("ImageGalleryWidget");
}

ImageGalleryWidget::ImageGalleryWidget(QWidget *viewWidget,
                                       QWidget *parent)
    : QWidget(parent)
    , mpViewWidget(viewWidget)
{
// TODO    refData().viewPixelSize(mpViewWidget->size());
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
    QLabel * pLabel = new QLabel("ImageGalleryWidget");
    pLabel->setFrameShape(QFrame::Panel);
    QGridLayout * pGridLayout = new QGridLayout();
    pGridLayout->addWidget(pLabel, 0, 0, Qt::AlignCenter | Qt::AlignHCenter);
    setLayout(pGridLayout);
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

void ImageGalleryWidget::config(const ImageGalleryConfig cfg)
{
    mConfig.clear();
    foreach (const Variable var, cfg.list())
        mConfig.set(var);
    qInfo() << Q_FUNC_INFO << mConfig.toDebugStrings();
}

void ImageGalleryWidget::calculate()
{
    calculateViewGeometry();
}

void ImageGalleryWidget::calculateViewGeometry()
{
    //if (config()->ViewPixelSize().isEmpty())
}


