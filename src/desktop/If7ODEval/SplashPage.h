#pragma once

#include <QQSize.h>
#include <StackedMainPage.h>

class EvalMainWindow;

class SplashPage : public StackedMainPage
{
    Q_OBJECT
public:
    SplashPage(EvalMainWindow *parent);

public slots:

signals:

public: // const

public: // non-const
    virtual void initialize();
    virtual void configure();
    virtual void setup();

public: // pointers

};
