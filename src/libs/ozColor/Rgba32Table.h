#pragma once
#include "ozColor.h"

#include <QList>
#include <QRgb>

class OZCOLOR_EXPORT Rgba32Table : public QList<QRgb>
{
public:
    Rgba32Table();
};
