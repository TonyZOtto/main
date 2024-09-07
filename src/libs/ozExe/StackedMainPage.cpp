#include "StackedMainPage.h"

#include <QGridLayout>

#include "BaseTabBar.h"
#include "StackedMainWindow.h"

StackedMainPage::StackedMainPage(const QString &aTitle, StackedMainWindow *parent)
    : QWidget{parent}
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

QQSize StackedMainPage::pageSize() const
{
    return mainWindow()->size();
}
