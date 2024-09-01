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
    gridLayout()->setObjectName("StackedMainPage:PageGridLayout");
}

void StackedMainPage::initialize()
{

}

void StackedMainPage::configure()
{

}

void StackedMainPage::setup()
{

}

QSize StackedMainPage::pageSize() const
{
    return mainWindow()->size();
}
