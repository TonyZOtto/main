#include "StackedMainWindow.h"

#include <QWidget>
#include <QGuiApplication>
#include <QHBoxLayout>
#include <QStackedLayout>
#include <QSizePolicy>
#include <QTabBar>

#include <ApplicationHelper.h>
#include <QQSize.h>
#include <Settings.h>
#include <Value.h>

#include "StackedMainPage.h"
#include "WidgetApplication.h"

StackedMainWindow::StackedMainWindow(WidgetApplication *wapp)
    : BaseMainWindow(wapp)
    , mpMainStackWidget(new QWidget(this))
    , mpMainStackLayout(new QStackedLayout())
    , mpTabBar(new QTabBar(this))
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
    foreach (StackedMainPage * pPage, mTitlePageMap)
        pPage->initialize();
}

void StackedMainWindow::configure()
{
    qInfo() << Q_FUNC_INFO;
    foreach (StackedMainPage * pPage, mTitlePageMap)
        pPage->configure();
}

void StackedMainWindow::setup()    
{
    qInfo() << Q_FUNC_INFO;
    foreach (StackedMainPage * pPage, mTitlePageMap)
        pPage->setup();

    QWidget * pMainWidget = new QWidget(this);
    setCentralWidget(pMainWidget);
    qDebug() << "StackedMainWindow" << size()
            << "CentralWidgetSize" << pMainWidget->size();
    QGridLayout * pGrid = new QGridLayout(pMainWidget);

    tabBar()->setShape(QTabBar::RoundedWest);
    QQSize tTabBarSize = tabBar()->size();
    qDebug() << "tTabBarSize" << tTabBarSize;
    tabBar()->setMaximumWidth(tTabBarSize.width());
    tabBar()->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Maximum);
    pGrid->addWidget(tabBar(), 0, 0, Qt::AlignRight | Qt::AlignTop);
    pGrid->addWidget(mainStackWidget(), 0, 1, Qt::AlignLeft | Qt::AlignTop);
    pMainWidget->setLayout(pGrid);
    mainStackWidget()->setLayout(mainStackLayout());
    connect(tabBar(), &QTabBar::currentChanged,
            this, &StackedMainWindow::setCurrent);

    show();
}

void StackedMainWindow::setCurrent(const int ix)
{
    qInfo() << Q_FUNC_INFO << ix;
    tabBar()->setCurrentIndex(ix);
    mainStackLayout()->setCurrentIndex(ix);
}

bool StackedMainWindow::contains(const KeySeg &title) const
{
    return mTitlePageMap.contains(title);
}

void StackedMainWindow::addPage(StackedMainPage *pPage)
{
    Q_ASSERT(pPage);
    const KeySeg cTitle = pPage->title();
    if (mTitlePageMap.contains(cTitle))
        qWarning() << "Duplicate Page Title: " << cTitle();
    qInfo() << Q_FUNC_INFO << cTitle << pPage->objectName();
    tabBar()->addTab(cTitle());
    mainStackLayout()->addWidget(pPage);
    mTitlePageMap.insert(cTitle, pPage);
}

StackedMainPage *StackedMainWindow::page(const KeySeg &title)
{
    StackedMainPage * result;
    Q_ASSERT(contains(title));
    result = mTitlePageMap.value(title);
    Q_ASSERT(qobject_cast<StackedMainPage *>(result));
    return result;
}
