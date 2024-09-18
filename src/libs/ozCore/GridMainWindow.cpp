#include "GridMainWindow.h"

#include <QGridLayout>

GridMainWindow::GridMainWindow(WidgetApplication *wapp)
    : BaseMainWindow(wapp)
    , mpGridLayout(new QGridLayout())
{
    setObjectName("GridMainWindow");
    Q_ASSERT(mpGridLayout);
    mpGridLayout->setObjectName("QGridLayout:" + objectName());
}

GridMainWindow::GridMainWindow(QGridLayout *pGrid,
                               WidgetApplication *wapp)
    : BaseMainWindow(wapp)
    , mpGridLayout(pGrid)
{
    setObjectName("GridMainWindow");
    Q_ASSERT(mpGridLayout);
}

void GridMainWindow::initialize()
{
    qInfo() << Q_FUNC_INFO;
    // TODO Anything
    emit initialized();
}
