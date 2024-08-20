#include "SplashPage.h"

#include <QFont>
#include <QPixmap>

#include <QQLabel.h>

#include "EvalMainWindow.h"

SplashPage::SplashPage(EvalMainWindow *parent)
    : StackedMainPage("Splash", parent)
{
    setObjectName("SplashPage");
    setup(mainWindow()->size());
}

void SplashPage::setup(const QQSize aMaxSize)
{
    QQSize tRightSize = aMaxSize / QQSize(1, 2);
    QQSize tLeftSize = tRightSize / QQSize(2, 1);
    QPixmap tEclipsePixmap(":/png/EclipseIRLogo200.png");
    QPixmap tINDIonlyPixmap(":/png/INDI200.png");
    QQSize tEclipseSize(tEclipsePixmap.size(), tLeftSize);
    QQSize tINDIonlySize(tINDIonlyPixmap.size(), tLeftSize);
    QQLabel * pEclipseLabel = new QQLabel(tEclipsePixmap.scaled(tEclipseSize));
    QQLabel * pINDIonlyLabel = new QQLabel(tINDIonlyPixmap.scaled(tINDIonlySize));
    QQLabel * pTextLabel = new QQLabel("INDIface7\nObject\nDetect\nEvalTool");
    pTextLabel->setFont(QFont("Helvetica", 64));
    gridLayout()->addWidget(pEclipseLabel, 0, 0);
    gridLayout()->addWidget(pINDIonlyLabel, 1, 0);
    gridLayout()->addWidget(pTextLabel, 0, 1, 2, 1);
    gridLayout()->setAlignment(pEclipseLabel,  Qt::AlignCenter | Qt::AlignHCenter);
    gridLayout()->setAlignment(pINDIonlyLabel, Qt::AlignCenter | Qt::AlignHCenter);
    gridLayout()->setAlignment(pTextLabel,     Qt::AlignCenter | Qt::AlignHCenter);
    setLayout(gridLayout());
}
