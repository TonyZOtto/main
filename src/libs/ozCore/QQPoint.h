#pragma once
#include "ozCore.h"

#include <QPoint>

class OZCORE_EXPORT QQPoint : public QPoint
{
public:
    QQPoint();
    QQPoint(const QPoint other);
    QQPoint(const int aX, const int aY);
};
