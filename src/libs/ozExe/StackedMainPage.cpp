#include "StackedMainPage.h"

#include <QGridLayout>

#include "BaseTabBar.h"
#include "StackedMainWindow.h"

StackedMainPage::StackedMainPage(const QString &aTitle, StackedMainWindow *parent)
    : QWidget{parent}
    , mpPageGridLayout(new QGridLayout())
    , mTitle(aTitle)
{
    setObjectName("StackedMainPage");
    gridLayout()->setObjectName("StackedMainPage:PageGridLayout");
}

QSize StackedMainPage::pageSize() const
{
    return mainWindow()->size();
}
