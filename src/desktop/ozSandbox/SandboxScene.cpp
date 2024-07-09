#include "SandboxScene.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsView>

#include <BasePhoto.h>

SandboxScene::SandboxScene(QObject *parent)
    : QGraphicsScene{parent}
    , mViewRect(QQSize(512, 512), QQPoint(0, 0))
{
    setObjectName("SandboxScene");
}

SandboxScene::~SandboxScene()
{
    foreach (QGraphicsPixmapItem * pItem, mPixmapItems)
    {
        removeItem(pItem);
        delete pItem;
    }
}

void SandboxScene::initialize()
{
    mpView = new QGraphicsView(this);


}

void SandboxScene::setup()
{
}

void SandboxScene::set(const Layer aLayer, const QColor &aFillColor)
{
    QPixmap tPixmap(viewRect().size());
    tPixmap.fill(aFillColor);
    set(aLayer, tPixmap);
}

void SandboxScene::set(const Layer aLayer, const BasePhoto &aPhoto)
{
    set(aLayer, aPhoto.baseImage());
}

void SandboxScene::set(const Layer aLayer, const QImage &aImage)
{
    const QPixmap cPixmap = QPixmap::fromImage(aImage);
    set(aLayer, cPixmap);
}

void SandboxScene::set(const Layer aLayer, const QPixmap &aPixmap)
{
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


