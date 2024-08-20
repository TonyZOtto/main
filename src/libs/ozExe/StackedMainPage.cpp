#include "StackedMainPage.h"

#include <QGridLayout>

#include "BaseTabBar.h"
#include "StackedMainWindow.h"

StackedMainPage::StackedMainPage(const QString &aTitle, StackedMainWindow *parent)
    : QWidget{parent}
    , mTitle(aTitle)
{
    setObjectName("StackedMainPage");
}

QSize StackedMainPage::pageSize() const
{
    return mainWindow()->size();
}
