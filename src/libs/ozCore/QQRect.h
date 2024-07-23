#pragma once
#include "ozCore.h"

#include <QRect>

#include "QQSize.h"

class OZCORE_EXPORT QQRect : public QRect
{
public: // ctors
    QQRect();
    QQRect(const QQSize aSize);

public: // const
};
