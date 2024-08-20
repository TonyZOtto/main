#pragma once
#include "ozExe.h"

#include "BaseMainWindow.h"

class QMdiArea;

class OZEXE_EXPORT MdiMainWindow : public BaseMainWindow
{
    Q_OBJECT
public:
    MdiMainWindow(WidgetApplication *wapp = nullptr);

private:
    QMdiArea * mpMdiArea=nullptr;
};
