#pragma once

#include <QObject>

#include <Types.h>

class Color
{
    Q_GADGET
public: // types
    enum Component
    {
        $nullComponent = 0,
        Opacity,
        Grey,
        Red,
        Green,
        Blue,
        Cyan,
        Magenta,
        Yellow,
        Black,
        Hue,
        Saturation,
        Value,
        Y,
        Cr,
        Cb,
        $maxComponent
    };

public: // ctor
    Color();
};

