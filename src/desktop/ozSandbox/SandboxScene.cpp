#include "SandboxScene.h"


SandboxScene::SandboxScene(QObject *parent)
    : QGraphicsScene{parent}
{
    setObjectName("SandboxScene");
}

void SandboxScene::set(const Layer aLayer, const QImage &aImage)
{
    const QPixmap cPixmap = QPixmap::fromImage(aImage);
    set(aLayer, cPixmap);
}

void SandboxScene::set(const Index aDisplayIndex, const QImage &aImage)
{
    set(DisplayBase + aDisplayIndex, aImage);
}

QGraphicsPixmapItem * SandboxScene::set(const Index aItemIndex, const QPixmap &aPixmap)
{
    QGraphicsPixmapItem * result = nullptr;
    if (aItemIndex < 0) return result;
    while (aItemIndex >= mPixmapItems.count())
        mPixmapItems.append(new QGraphicsPixmapItem());
    QGraphicsPixmapItem * pOldItem = mPixmapItems[aItemIndex];
    QGraphicsPixmapItem * pNewItem = new QGraphicsPixmapItem(aPixmap);
    removeItem(pOldItem);
    pNewItem->setVisible(true);
    pNewItem->setZValue(aItemIndex);
    addItem(pNewItem);
    result = pNewItem;
    return result;
}
