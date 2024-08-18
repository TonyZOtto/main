#include "GridMainWindow.h"

#include <BaseGridLayout.h>

GridMainWindow::GridMainWindow(QWidget *parent)
    : BaseMainWindow(parent)
    , mpGridLayout(new BaseGridLayout(this))
{
    setObjectName("GridMainWindow");
    Q_ASSERT(mpGridLayout);
    mpGridLayout->setObjectName("BaseGridLayout:" + objectName());
}

GridMainWindow::GridMainWindow(BaseGridLayout *pGrid,
                               QWidget *parent)
    : BaseMainWindow(parent)
    , mpGridLayout(pGrid)
{
    setObjectName("GridMainWindow");
}
