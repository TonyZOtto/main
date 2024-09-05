#pragma once
#include "ozExe.h"

#include "BaseMainWindow.h"

#include <QStackedLayout>

#include <Key.h>
#include <KeyMap.h>
#include <QQSize.h>

class BaseTabBar;
class StackedMainPage;

class OZEXE_EXPORT StackedMainWindow : public BaseMainWindow
{
public:
    StackedMainWindow(WidgetApplication *wapp);

public slots:
    void initialize();
    void configure();
    void setup();
    void setCurrent(const int ix);

signals:
    void initialized();
    void configured();
    void setuped();
    void startupError(const QString errorString);

public: // const
    QQSize pageSize() const;

public: // non-const
    void pageSize(const QQSize sz);
    void addPage(StackedMainPage * pPage);

public: // pointers
    QWidget * mainStackWidget();
    QStackedLayout * mainStackLayout();
    BaseTabBar * tabBar();

private:
    QWidget * mpMainStackWidget=nullptr;
    QStackedLayout * mpMainStackLayout=nullptr;
    BaseTabBar * mpTabBar=nullptr;
    QQSize mPageSize;

};

inline QQSize StackedMainWindow::pageSize() const { return mPageSize; }
inline void StackedMainWindow::pageSize(const QQSize sz) { mPageSize = sz; }
inline QWidget *StackedMainWindow::mainStackWidget() { Q_ASSERT(mpMainStackWidget); return mpMainStackWidget; }
inline QStackedLayout *StackedMainWindow::mainStackLayout() { Q_ASSERT(mpMainStackLayout); return mpMainStackLayout; }
inline BaseTabBar *StackedMainWindow::tabBar() { Q_ASSERT(mpTabBar); return mpTabBar; }

