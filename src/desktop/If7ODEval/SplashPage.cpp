#include "SplashPage.h"

#include <QFont>
#include <QPixmap>

#include <QQLabel.h>

#include <ApplicationHelper.h>

#include "EvalMainWindow.h"

SplashPage::SplashPage(StackedMainWindow *parent)
    : StackedMainPage("Splash", parent)
{
    qInfo() << Q_FUNC_INFO;
    setObjectName("SplashPage");
}

void SplashPage::initialize()
{
    qInfo() << Q_FUNC_INFO;
    // TOOD anything?
}

void SplashPage::configure()
{
    qInfo() << Q_FUNC_INFO;
    // TOOD anything?
}

void SplashPage::setup()
{
    qInfo() << Q_FUNC_INFO << pageSize();
    StackedMainPage::setup();

    QQSize tRightSize = pageSize() / QQSize(2, 1);
    QQSize tLeftSize = tRightSize / QQSize(1, 2);
    qDebug() << tLeftSize << tRightSize;
    QPixmap tEclipsePixmap(":/png/EclipseIRLogo200.png");
    QPixmap tINDIonlyPixmap(":/png/INDI200.png");
    QQSize tEclipseSize(tEclipsePixmap.size(), tLeftSize);
    QQSize tINDIonlySize(tINDIonlyPixmap.size(), tLeftSize);
    qDebug() << tEclipsePixmap.size() << tEclipseSize
             << tINDIonlyPixmap.size() << tINDIonlySize;
    QQLabel * pEclipseLabel = new QQLabel(tEclipsePixmap.scaled(tEclipseSize));
    QQLabel * pINDIonlyLabel = new QQLabel(tINDIonlyPixmap.scaled(tINDIonlySize));
    QQLabel * pTextLabel = new QQLabel("INDIface7\nObject\nDetect\nEvalTool");
    pTextLabel->setFont(QFont("Helvetica", 48));

    pageGridLayout()->addWidget(pEclipseLabel, 0, 0);
    pageGridLayout()->addWidget(pINDIonlyLabel, 1, 0);
    pageGridLayout()->addWidget(pTextLabel, 0, 1, 2, 1);
    pageGridLayout()->setAlignment(pEclipseLabel,  Qt::AlignCenter | Qt::AlignHCenter);
    pageGridLayout()->setAlignment(pINDIonlyLabel, Qt::AlignCenter | Qt::AlignHCenter);
    pageGridLayout()->setAlignment(pTextLabel,     Qt::AlignCenter | Qt::AlignHCenter);
    setLayout(pageGridLayout());
}

void SplashPage::handleResize(const QQSize newSize)
{
    qInfo() << Q_FUNC_INFO  << objectName() << newSize;

}
