#include "StackedMainWindow.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QStackedLayout>

#include <QQSize.h>

#include "BaseTabBar.h"
#include "StackedMainPage.h"

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

void StackedMainWindow::setCurrent(const int ix)
{
    tabBar()->setCurrentIndex(ix);
    mainStackLayout()->setCurrentIndex(ix);
}

void StackedMainWindow::setup()
{
    qInfo() << Q_FUNC_INFO;
    showMaximized();
    QWidget * pMainWidget = new QWidget(this);
    setCentralWidget(pMainWidget);
    update();
    updateGeometry();
    qDebug() << "CentralWidgetSize" << pMainWidget->size();
    QGridLayout * pGrid = new QGridLayout(pMainWidget);

    tabBar()->setShape(QTabBar::RoundedEast);
    QQSize tTabBarSize = tabBar()->size();
    qDebug() << "tTabBarSize" << tTabBarSize;
    tabBar()->setMaximumWidth(tTabBarSize.width());
    pGrid->addWidget(tabBar(), 0, Qt::AlignRight | Qt::AlignTop);
    pGrid->addWidget(mainStackWidget(), 0,  Qt::AlignLeft | Qt::AlignTop);
    pMainWidget->setLayout(pGrid);
    mainStackWidget()->setLayout(mainStackLayout());
    connect(tabBar(), &QTabBar::currentChanged,
            this, &StackedMainWindow::setCurrent);
}

void StackedMainWindow::addPage(StackedMainPage *pPage)
{
    Q_ASSERT(pPage);
    qInfo() << Q_FUNC_INFO;
    mainStackLayout()->addWidget(pPage);
    mainStackLayout()->setCurrentWidget(pPage);
    const int cTabIndex = tabBar()->addTab(pPage->title());
    tabBar()->setCurrentIndex(cTabIndex);
    update();
}
