#include "SandboxScene.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsView>

#include <BasePhoto.h>

#include "SandboxMainWindow.h"

SandboxScene::SandboxScene(SandboxMainWindow *parent)
    : QGraphicsScene{parent}
    , mpMainWindow(parent)
    , mViewRect(QQSize(512, 512), QQPoint(0, 0))
{
    qInfo() << Q_FUNC_INFO;
    setObjectName("SandboxScene");
}

SandboxScene::~SandboxScene()
{
    qInfo() << Q_FUNC_INFO;
    foreach (QGraphicsPixmapItem * pItem, mPixmapItems)
    {
        removeItem(pItem);
        delete pItem;
    }
}

void SandboxScene::initialize()
{
    qInfo() << Q_FUNC_INFO;
    mpView = new QGraphicsView(this);


}

void SandboxScene::setup()
{
    qInfo() << Q_FUNC_INFO;
    view()->setMinimumSize(viewRect().size());
    widget()->setMinimumSize(viewRect().size());
}

void SandboxScene::set(const Layer aLayer, const QColor &aFillColor)
{
    qInfo() << Q_FUNC_INFO << aLayer;
    QPixmap tPixmap(viewRect().size());
    tPixmap.fill(aFillColor);
    set(aLayer, tPixmap);
}

void SandboxScene::set(const Layer aLayer, const BasePhoto &aPhoto)
{
    qInfo() << Q_FUNC_INFO << aLayer;
    set(aLayer, aPhoto.baseImage());
}

void SandboxScene::set(const Layer aLayer, const QImage &aImage)
{
    qInfo() << Q_FUNC_INFO << aLayer;
    set(aLayer, QPixmap::fromImage(aImage));
}

void SandboxScene::set(const Layer aLayer, const QPixmap &aPixmap)
{
    qInfo() << Q_FUNC_INFO << aLayer;
    if (mPixmapItems.isEmpty())
        mPixmapItems.fill(nullptr, Layer::$max);
    QGraphicsPixmapItem * pOldItem = mPixmapItems[aLayer];
    QGraphicsPixmapItem * pNewItem = new QGraphicsPixmapItem(aPixmap);
    if (pOldItem)
    {
        removeItem(pOldItem);
        delete pOldItem;
    }
    pNewItem->setVisible(true);
    pNewItem->setZValue(aLayer);
    addItem(pNewItem);
}

QWidget *SandboxScene::widget()
{
    return view()->viewport();
}


