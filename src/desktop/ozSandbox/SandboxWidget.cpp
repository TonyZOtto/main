#include "SandboxWidget.h"

#include <QSizePolicy>

SandboxWidget::SandboxWidget(QWidget *parent)
    : QWidget{parent}
{
    setObjectName("SandboxWidget");

/*    setMinimumSize(512, 512);
    QSizePolicy tSzP;
    tSzP.setHorizontalPolicy(QSizePolicy::Fixed);
    tSzP.setVerticalPolicy(QSizePolicy::Fixed);
    setSizePolicy(tSzP);
*/
    setFixedSize(512, 512);
}
