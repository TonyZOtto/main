#include "StackedMainWindow.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QStackedLayout>

#include "BaseTabBar.h"
#include "StackedMainPage.h"

StackedMainWindow::StackedMainWindow(WidgetApplication *wapp)
    : BaseMainWindow(wapp)
    , mpMainStackWidget(new QWidget(this))
    , mpMainStackLayout(new QStackedLayout())
    , mpTabBar(new BaseTabBar(this))
{
    setObjectName("StackedMainWindow");
    mainStackWidget()->setObjectName("StackedMainWindow:MainStackWidget");
    mainStackLayout()->setObjectName("StackedMainWindow:MainStackLayout");
    tabBar()->setObjectName("StackedMainWindow:TabBar");
}

void StackedMainWindow::setup()
{
    updateGeometry();
    tabBar()->setShape(QTabBar::RoundedEast);
    QWidget * pMainWidget = new QWidget(this);
    QHBoxLayout * pHBox = new QHBoxLayout();
    pHBox->addWidget(tabBar(), 0, Qt::AlignRight | Qt::AlignTop);
    mainStackWidget()->setLayout(mainStackLayout());
    pHBox->addWidget(mainStackWidget(), 0,  Qt::AlignLeft | Qt::AlignTop);
    pMainWidget->setLayout(pHBox);
    setCentralWidget(pMainWidget);
}

void StackedMainWindow::addPage(StackedMainPage *pPage)
{
    mainStackLayout()->addWidget(pPage);
    mainStackLayout()->setCurrentWidget(pPage);
    const int cTabIndex = tabBar()->addTab(pPage->title());
    tabBar()->setCurrentIndex(cTabIndex);
    update();
}
