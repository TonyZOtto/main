#include "StackedMainPage.h"

#include <QGridLayout>

#include "BaseTabBar.h"
#include "StackedMainWindow.h"

StackedMainPage::StackedMainPage(const QString &aTitle, StackedMainWindow *parent)
    : QWidget{parent}
    , mpPageGridLayout(new QGridLayout())
    , mTitle(aTitle)
{
    qInfo() << Q_FUNC_INFO;
    setObjectName("StackedMainPage");
    pageGridLayout()->setObjectName("StackedMainPage:PageGridLayout");
}

void StackedMainPage::initialize()
{

}

void StackedMainPage::configure()
{

}

void StackedMainPage::setup()
{
    setLayout(pageGridLayout());
}

QQSize StackedMainPage::pageSize() const
{
    return mainWindow()->size();
}
