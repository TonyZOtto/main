#pragma once
#include "ozWidgets.h"

#include <VariableProperty.h>
#include <VariableSet.h>
#include <Ident.h>
#include <Key.h>

#include <QColor>

#include <QQSize.h>

#define GALLERYCONFIG_VARPROPS(TKD) \
    TKD(QQSize, thumbPixelSize, QQSize(128)) \
    TKD(QQSize, viewCellSize, QQSize()) \
    TKD(QQSize, viewPixelSize, QQSize()) \
    TKD(QColor, backColor, QColor("steelblue")) \
    TKD(QColor, blankColor, QColor(Qt::darkGray)) \
    TKD(Qt::Orientations, scrollOrientations, 0) \
    TKD(int, gapWidth, 7) \

class OZWIDGETS_EXPORT ImageGalleryConfig : public VariableSet
{
public: // ctors
    ImageGalleryConfig(const Key &setKey=Key())
        : VariableSet(Ident(setKey)) { ctor(); }
    ImageGalleryConfig(const ImageGalleryConfig &other)
        : VariableSet(other) { ctor(); }
    DEFINE_VARPROPS(GALLERYCONFIG_VARPROPS);

public: // const


private:
    void ctor() { DECLARE_DEFALT_VARPROPS(GALLERYCONFIG_VARPROPS); }
};

