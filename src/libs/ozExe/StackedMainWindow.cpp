#include "StackedMainWindow.h"

StackedMainWindow::StackedMainWindow(WidgetApplication *wapp)
    : BaseMainWindow(wapp)
    , mpMainStack(new QStackedLayout())
{
    setObjectName("StackedMainWindow");
    Q_ASSERT(mpMainStack);
    mpMainStack->setObjectName("StackedMainWindow:MainStack");
}
