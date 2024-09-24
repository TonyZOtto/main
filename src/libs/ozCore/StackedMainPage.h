#pragma once
#include "ozCore.h"

#include <QWidget>

class QGridLayout;

#include <KeySeg.h>
#include <QQSize.h>
class QTabBar;
class StackedMainWindow;

class OZCORE_EXPORT StackedMainPage : public QWidget
{
    Q_OBJECT
public:
    explicit StackedMainPage(const KeySeg &aTitle,
                             StackedMainWindow *parent);

public slots:

signals:

public: // const
    QQSize pageSize() const;
    KeySeg title() const;

public: // non-const
    virtual void initialize();
    virtual void configure();
    virtual void setup();

public: //

public: // pointers
    StackedMainWindow * mainWindow();
    QGridLayout * pageGridLayout();

protected slots:
    virtual void handleResize(const QQSize newSize);


private:
    StackedMainWindow * mpMainWindow=nullptr;
    QGridLayout * mpPageGridLayout=nullptr;
    KeySeg mTitle;
    bool mSizeDirty=true;
};

inline KeySeg StackedMainPage::title() const { return mTitle; }

inline StackedMainWindow *StackedMainPage::mainWindow() { Q_ASSERT(mpMainWindow); return mpMainWindow; }
inline QGridLayout *StackedMainPage::pageGridLayout() { Q_ASSERT(mpPageGridLayout); return mpPageGridLayout; }
