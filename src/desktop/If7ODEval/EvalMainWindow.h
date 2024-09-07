#pragma once

#include <StackedMainWindow.h>

class AcquirePage;
class LogPage;
class SplashPage;

class EvalMainWindow : public StackedMainWindow
{
    Q_OBJECT

public:
    EvalMainWindow(WidgetApplication *wapp);
    ~EvalMainWindow();

public slots:
    virtual void initialize();
    virtual void configure();
    virtual void setup();

signals:

private:
    SplashPage * mpSplashPage=nullptr;
    LogPage * mpLogPage=nullptr;
    AcquirePage * mpAcquirePage=nullptr;
};
