#include "GraphicsFillItem.h"

GraphicsFillItem::GraphicsFillItem(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {;}

GraphicsFillItem::GraphicsFillItem(const QQSize sz,
                                   const QColor col,
                                   QGraphicsItem *parent)
    : QGraphicsPixmapItem(QPixmap(sz), parent)
{
    pixmap().fill(col);
}

