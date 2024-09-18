#pragma once
#include "ozWidgets.h"

#include <Ident.h>
#include <Key.h>
#include <QQSize.h>
#include <SCRect.h>
#include <VariableProperty.h>
#include <VariableSet.h>

#define GALLERYINTERNAL_VARPROPS(TKD) \
    TKD(SCRect, sceneRect, SCRect()) \
    TKD(QQSize, viewPixelSize, QQSize()) \
    TKD(SCRect, originViewRect, SCRect()) \
    TKD(SCRect, currentViewRect, SCRect()) \
    TKD(QQSize, viewCellSize, QQSize()) \

class OZWIDGETS_EXPORT ImageGalleryInternal : public VariableSet
{
public: // ctors
    ImageGalleryInternal(const Key &setKey) : VariableSet(Ident(setKey)) { ctor(); }
    DEFINE_VARPROPS(GALLERYINTERNAL_VARPROPS);

public: // const

private:
    void ctor();
};

