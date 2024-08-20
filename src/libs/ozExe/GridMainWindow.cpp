#include "GridMainWindow.h"

#include <BaseGridLayout.h>

GridMainWindow::GridMainWindow(WidgetApplication *wapp)
    : BaseMainWindow(wapp)
    , mpGridLayout(new BaseGridLayout())
{
    setObjectName("GridMainWindow");
    Q_ASSERT(mpGridLayout);
    mpGridLayout->setObjectName("BaseGridLayout:" + objectName());
}

GridMainWindow::GridMainWindow(BaseGridLayout *pGrid,
                               WidgetApplication *wapp)
    : BaseMainWindow(wapp)
    , mpGridLayout(pGrid)
{
    setObjectName("GridMainWindow");
}
