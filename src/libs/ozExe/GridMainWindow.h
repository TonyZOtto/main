#pragma once
#include "ozExe.h"

#include "BaseMainWindow.h"

class BaseGridLayout;

class OZEXE_EXPORT GridMainWindow : public BaseMainWindow
{
    Q_OBJECT
public:
    GridMainWindow(WidgetApplication *wapp);
    GridMainWindow(BaseGridLayout * pGrid,
                   WidgetApplication *wapp);

private:
    BaseGridLayout * mpGridLayout=nullptr;
};
