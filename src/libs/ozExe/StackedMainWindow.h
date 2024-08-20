#pragma once
#include "ozExe.h"

#include "BaseMainWindow.h"

#include <QStackedLayout>

class OZEXE_EXPORT StackedMainWindow : public BaseMainWindow
{
public:
    StackedMainWindow(WidgetApplication *wapp);

private:
    QWidget * mpMainStackWidget=nullptr;
    QStackedLayout * mpMainStack=nullptr;
};
