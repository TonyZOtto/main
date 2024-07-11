#pragma once
#include "ozGui.h"

#include <QColor>

#include <Types.h>

class OZGUI_EXPORT QQColor : public QColor
{
public: // ctors
    QQColor();
    QQColor(int r, int g, int b, int a = 255);
    QQColor(Qt::GlobalColor color);

public: // const
    QQColor subtracted(const QQColor rhs) const;

public: // non-const
    QQColor subtract(const QQColor rhs);
    QQColor operator - (const QQColor rhs) { return subtract(rhs); }

public: // static
    static void grey16fromRgba32(WORD * pGrey16, QRgb * pRgba32, Count nPixel);
};

