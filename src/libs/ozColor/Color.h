#pragma once
#include "ozColor.h"

#include <QColor>
#include <QObject>

#include <Types.h>

class OZCOLOR_EXPORT Color
{
    Q_GADGET
public: // types
    enum Component
    {
        $nullCC = 0,
        OpacityCC,
        GreyCC,
        RedCC,
        GreenCC,
        BlueCC,
        CyanCC,
        MagentaCC,
        YellowCC,
        BlackCC,
        HueCC,
        SaturationCC,
        ValueCC,
        YccCC,
        CrCC,
        CbCC,
        $maxComponent
    };

public: // ctor
    Color();

public: // static
    static QColor complement(const QColor qc);
};

