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
    BaseMainWindow::initialize();
    foreach (StackedMainPage * pPage, mTitlePageMap)
        pPage->initialize();
}

void StackedMainWindow::configure()
{
    qInfo() << Q_FUNC_INFO;
    BaseMainWindow::configure();
    foreach (StackedMainPage * pPage, mTitlePageMap)
        pPage->configure();
}

void StackedMainWindow::setup()
{
    qInfo() << Q_FUNC_INFO;
    BaseMainWindow::setup();
    foreach (StackedMainPage * pPage, mTitlePageMap)
        pPage->setup();

    QGridLayout * pGrid = new QGridLayout(centralWidget());
    tabBar()->setShape(QTabBar::RoundedWest);
    tabBar()->setMinimumSize(30, 400);
    tabBar()->setMaximumSize(50, 500);
    mainStackWidget()->setMinimumSize(600, 420);;
    pGrid->addWidget(tabBar(), 0, 0, Qt::AlignRight | Qt::AlignTop);
    pGrid->addWidget(mainStackWidget(), 0, 1, Qt::AlignLeft | Qt::AlignTop);
    setLayout(pGrid);
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
