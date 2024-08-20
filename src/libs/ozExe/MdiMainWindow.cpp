#include "MdiMainWindow.h"

#include <QMdiArea>

MdiMainWindow::MdiMainWindow(WidgetApplication *wapp)
    : BaseMainWindow{wapp}
    , mpMdiArea(new QMdiArea(this))
{
    setObjectName("MdiMainWindow");
    Q_ASSERT(mpMdiArea);
    mpMdiArea->setObjectName("QMdiArea:" + objectName());
}

