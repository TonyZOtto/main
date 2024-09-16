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
    TKD(QQSize, viewPixelSize, QQSize()) \
    TKD(QColor, backColor, QColor("steelblue")) \
    TKD(QColor, blankColor, QColor(Qt::darkGray)) \
    TKD(Qt::Orientations, scrollOrientations, 0) \

class OZWIDGETS_EXPORT ImageGalleryConfig : public VariableSet
{
public: // ctors
    ImageGalleryConfig(const Key &setKey) : VariableSet(Ident(setKey)) { ctor(); }
    DEFINE_VARPROPS(GALLERYCONFIG_VARPROPS);

public: // const

private:
    void ctor();
};

