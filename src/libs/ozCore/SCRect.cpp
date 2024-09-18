#include "SCRect.h"

SCRect::SCRect(const int aDim) : mSize(aDim), mCenter(0, 0) {;}
SCRect::SCRect(const QSize aSize) : mSize(aSize), mCenter(0, 0) {;}
SCRect::SCRect(const QRect aRect) : mSize(aRect.size()), mCenter(aRect.center()) {;}
SCRect::SCRect(const QSize aSize, const QPoint aCenter) : mSize(aSize), mCenter(aCenter) {;}

bool SCRect::isNull() const
{
    return size().isNull() || center().isNull();
}

int SCRect::width() const
{
    return size().width();
}

int SCRect::height() const
{
    return size().height();
}

QVariant SCRect::toQVariant() const
{
    return QVariant(toQRect());
}

QRect SCRect::toQRect(const Anchor aAnchor) const
{
    QPoint tTopLeft;
    switch (aAnchor)
    {
    case TopLeft:   tTopLeft = QPoint(0, 0);                        break;
    case Center:    tTopLeft = QPoint(width() / 2, height() / 2);   break;
    }
    QRect result(tTopLeft, size());
    return result;
}


