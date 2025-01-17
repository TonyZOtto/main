#include "StackedMainPage.h"

#include <QGridLayout>
#include <QTabBar>

#include <ApplicationHelper.h>

#include "StackedMainWindow.h"

StackedMainPage::StackedMainPage(const KeySeg &aTitle, StackedMainWindow *parent)
    : QWidget{parent}
    , mpMainWindow(parent)
    , mpPageGridLayout(new QGridLayout())
    , mTitle(aTitle)
{
    qInfo() << Q_FUNC_INFO << title();
    setObjectName("StackedMainPage:" + aTitle);
    pageGridLayout()->setObjectName("StackedMainPage:PageGridLayout");
}

void StackedMainPage::initialize()
{
    qInfo() << Q_FUNC_INFO << title();
}

void StackedMainPage::configure()
{
    qInfo() << Q_FUNC_INFO << title();

}

void StackedMainPage::setup()
{
    qInfo() << Q_FUNC_INFO << title();
    setLayout(pageGridLayout());
}

void StackedMainPage::handleResize(const QQSize newSize)
{
    qInfo() << Q_FUNC_INFO  << objectName() << newSize;
    mSizeDirty = true;
}
