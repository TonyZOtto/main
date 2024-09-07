#include "StackedMainWindow.h"

#include <QWidget>
#include <QGuiApplication>
#include <QHBoxLayout>
#include <QStackedLayout>

#include <ApplicationHelper.h>
#include <QQSize.h>
#include <Settings.h>
#include <Value.h>

#include "BaseTabBar.h"
#include "StackedMainPage.h"
#include "WidgetApplication.h"

StackedMainWindow::StackedMainWindow(WidgetApplication *wapp)
    : BaseMainWindow(wapp)
    , mpMainStackWidget(new QWidget(this))
    , mpMainStackLayout(new QStackedLayout())
    , mpTabBar(new BaseTabBar(this))
{
    qInfo() << Q_FUNC_INFO;
    setObjectName("StackedMainWindow");
    mainStackWidget()->setObjectName("StackedMainWindow:MainStackWidget");
    mainStackLayout()->setObjectName("StackedMainWindow:MainStackLayout");
    tabBar()->setObjectName("StackedMainWindow:TabBar");
}

void StackedMainWindow::initialize()
{
    qInfo() << Q_FUNC_INFO;

}

void StackedMainWindow::configure()
{
    qInfo() << Q_FUNC_INFO;

}

void StackedMainWindow::setup()

{
    qInfo() << Q_FUNC_INFO;
    showMaximized();
    update();
    updateGeometry();
    QWidget * pMainWidget = new QWidget(this);
    setCentralWidget(pMainWidget);
    qDebug() << "StackedMainWindow" << size()
            << "CentralWidgetSize" << pMainWidget->size();
    QGridLayout * pGrid = new QGridLayout(pMainWidget);

    tabBar()->setShape(QTabBar::RoundedEast);
    QQSize tTabBarSize = tabBar()->size();
    qDebug() << "tTabBarSize" << tTabBarSize;
    tabBar()->setMaximumWidth(tTabBarSize.width());
    pGrid->addWidget(tabBar(), 0, 0, Qt::AlignRight | Qt::AlignTop);
    pGrid->addWidget(mainStackWidget(), 0, 1, Qt::AlignLeft | Qt::AlignTop);
    pMainWidget->setLayout(pGrid);
    mainStackWidget()->setLayout(mainStackLayout());
    connect(tabBar(), &QTabBar::currentChanged,
            this, &StackedMainWindow::setCurrent);
}

void StackedMainWindow::setCurrent(const int ix)
{
    qInfo() << Q_FUNC_INFO << ix;
    tabBar()->setCurrentIndex(ix);
    mainStackLayout()->setCurrentIndex(ix);
}

void StackedMainWindow::addPage(StackedMainPage *pPage)
{
    Q_ASSERT(pPage);
    qInfo() << Q_FUNC_INFO << pPage->objectName();
    tabBar()->addTab(pPage->title());
    mainStackLayout()->addWidget(pPage);
    mainStackLayout()->setCurrentWidget(pPage);
    update();
}
