#pragma once
#include "ozExe.h"

#include "BaseMainWindow.h"

#include <QStackedLayout>

#include <Key.h>
#include <KeyMap.h>

class BaseTabBar;
class StackedMainPage;

class OZEXE_EXPORT StackedMainWindow : public BaseMainWindow
{
public:
    StackedMainWindow(WidgetApplication *wapp);

public slots:
    void setCurrent(const int ix);

public: // const
    KeyMap settings(const Key groupName);

public: // non-const
    virtual void setup();
    void addPage(StackedMainPage * pPage);

public: // pointers
    QWidget * mainStackWidget();
    QStackedLayout * mainStackLayout();
    BaseTabBar * tabBar();

private:
    QWidget * mpMainStackWidget=nullptr;
    QStackedLayout * mpMainStackLayout=nullptr;
    BaseTabBar * mpTabBar=nullptr;
};

inline QWidget *StackedMainWindow::mainStackWidget() { Q_ASSERT(mpMainStackWidget); return mpMainStackWidget; }
inline QStackedLayout *StackedMainWindow::mainStackLayout() { Q_ASSERT(mpMainStackLayout); return mpMainStackLayout; }
inline BaseTabBar *StackedMainWindow::tabBar() { Q_ASSERT(mpTabBar); return mpTabBar; }

