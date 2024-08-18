#pragma once
#include "ozCore.h"

#include <QPoint>

#include "QQSize.h"
#include "Types.h"

class OZCORE_EXPORT QQPoint : public QPoint
{
public:
    QQPoint();
    QQPoint(const QPoint other);
    QQPoint(const QQSize aSize, const Index ix);
    QQPoint(const int aX, const int aY);
    QQPoint(const int aX, const int aY, const float aScaleF);

public: // const
    int x() const { return QPoint::x(); } // TODO Why?
    int y() const { return QPoint::y(); }
    QQPoint up() const;


public: // non-const
    void x(const int aX) { setX(aX); }
    void y(const int aY) { setY(aY); }
};
