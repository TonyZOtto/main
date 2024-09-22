#include "ImageGalleryWidget.h"

#include <QGridLayout>
#include <QLabel>


#include "GraphicsFillItem.h"

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
    calculate();

}

void ImageGalleryWidget::setup()
{
    QGridLayout * pGridLayout = new QGridLayout();
    mpScene = new QGraphicsScene(internal().sceneRect().toQRectF(), this);
    mpView = new QGraphicsView(mpScene, this);
    GraphicsFillItem * pGFI = new GraphicsFillItem(internal().viewPixelSize(),
                                                  config().backColor());
    mpScene->addItem(pGFI);
    pGridLayout->addWidget(mpView, 0, 0, 1, 1);
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
//    const QQSize cThumbPixelSize = mConfig.get("thumbPixelSize");
    const int cGapWidth = int(mConfig.get("GapWidth").value());
    const QQSize cViewPixelSize = QQSize(mConfig.get("viewPixelSize").value());
    mSceneRect.set(QQPoint( - cGapWidth / 2,  - cGapWidth / 2), cViewPixelSize);
    internal().sceneRect(mSceneRect);
    internal().viewPixelSize(cViewPixelSize);
}


