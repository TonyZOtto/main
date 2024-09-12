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
    QGridLayout * pageGridLayout();

private:
    QGridLayout * mpPageGridLayout=nullptr;
    QString mTitle;
};

inline QString StackedMainPage::title() const { return mTitle; }
inline QGridLayout *StackedMainPage::pageGridLayout() { Q_ASSERT(mpPageGridLayout); return mpPageGridLayout; }
