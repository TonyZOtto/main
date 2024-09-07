#pragma once
#include "ozExe.h"

#include <QWidget>

class QGridLayout;

#include <QQSize.h>
class BaseTabBar;
class StackedMainWindow;

class OZEXE_EXPORT StackedMainPage : public QWidget
{
    Q_OBJECT
public:
    explicit StackedMainPage(const QString &aTitle, StackedMainWindow *parent);

public slots:

signals:

public: // const
    QQSize pageSize() const;
    QString title() const;

public: // non-const
    virtual void initialize();
    virtual void configure();
    virtual void setup();

public: //

public: // pointers
    StackedMainWindow * mainWindow() const;
    QGridLayout * pageGridLayout();

private:
    StackedMainWindow * mpMainWindow=nullptr;
    QGridLayout * mpPageGridLayout=nullptr;
    QString mTitle;
};

inline QString StackedMainPage::title() const { return mTitle; }
inline StackedMainWindow *StackedMainPage::mainWindow() const { Q_ASSERT(mpMainWindow); return mpMainWindow; }
inline QGridLayout *StackedMainPage::pageGridLayout() { Q_ASSERT(mpPageGridLayout); return mpPageGridLayout; }
