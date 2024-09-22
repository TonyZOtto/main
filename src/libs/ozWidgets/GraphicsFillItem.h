#pragma once

#include <QGraphicsPixmapItem>

#include <QColor>
#include <QPixmap>

#include <QQSize.h>

class GraphicsFillItem : public QGraphicsPixmapItem
{
public:
    GraphicsFillItem(QGraphicsItem * parent=nullptr);
    GraphicsFillItem(const QQSize sz, const QColor col, QGraphicsItem * parent=nullptr);
};
