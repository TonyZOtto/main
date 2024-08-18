#include "MdiMainWindow.h"

#include <QMdiArea>

MdiMainWindow::MdiMainWindow(QWidget *parent)
    : BaseMainWindow{parent}
    , mpMdiArea(new QMdiArea(this))
{
    setObjectName("MdiMainWindow");
    Q_ASSERT(mpMdiArea);
    mpMdiArea->setObjectName("QMdiArea:" + objectName());
}

