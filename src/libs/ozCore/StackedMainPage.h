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
    QGridLayout * pageGridLayout();

private:
    QGridLayout * mpPageGridLayout=nullptr;
    KeySeg mTitle;
};

inline KeySeg StackedMainPage::title() const { return mTitle; }
inline QGridLayout *StackedMainPage::pageGridLayout() { Q_ASSERT(mpPageGridLayout); return mpPageGridLayout; }
