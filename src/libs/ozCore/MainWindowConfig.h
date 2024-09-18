#pragma once
#include "ozCore.h"

#include <VariableProperty.h>
#include <VariableSet.h>
#include <Ident.h>
#include <Key.h>

#include <QColor>

#include <QQSize.h>

#define MAINWINCONFIG_VARPROPS(TKD) \
    TKD(bool, maximized, false) \

class OZCORE_EXPORT MainWindowConfig : public VariableSet
{
public: // ctors
    MainWindowConfig(const Key &setKey) : VariableSet(Ident(setKey)) { ctor(); }
    DEFINE_VARPROPS(MAINWINCONFIG_VARPROPS);

public: // const

private:
    void ctor();
};
