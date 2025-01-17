#pragma once
#include "ozCore.h"

#include "BaseMainWindow.h"

#include <QMap>
#include <QStackedLayout>
#include <QString>

#include <KeySeg.h>
#include <QQSize.h>

class QTabBar;
class StackedMainPage;

class OZCORE_EXPORT StackedMainWindow : public BaseMainWindow
{
    Q_OBJECT
public:
    StackedMainWindow(WidgetApplication *wapp);

public slots:
    virtual void initialize();
    virtual void configure();
    virtual void setup();
    void setCurrent(const int ix);

signals:

public: // const
    bool contains(const KeySeg &title) const;
    QQSize pageSize() const;

public: // non-const
    void pageSize(const QQSize sz);
    void addPage(StackedMainPage * pPage);

public: // pointers
    StackedMainPage * page(const KeySeg &title);
    QWidget * mainStackWidget();
    QStackedLayout * mainStackLayout();
    QTabBar * tabBar();

private:
    QWidget * mpMainStackWidget=nullptr;
    QStackedLayout * mpMainStackLayout=nullptr;
    QTabBar * mpTabBar=nullptr;
    QQSize mPageSize;
    QMap<KeySeg, StackedMainPage *> mTitlePageMap;
};

inline QQSize StackedMainWindow::pageSize() const { return mPageSize; }
inline void StackedMainWindow::pageSize(const QQSize sz) { mPageSize = sz; }
inline QWidget *StackedMainWindow::mainStackWidget() { Q_ASSERT(mpMainStackWidget); return mpMainStackWidget; }
inline QStackedLayout *StackedMainWindow::mainStackLayout() { Q_ASSERT(mpMainStackLayout); return mpMainStackLayout; }
inline QTabBar *StackedMainWindow::tabBar() { Q_ASSERT(mpTabBar); return mpTabBar; }

