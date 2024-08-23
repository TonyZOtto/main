#pragma once

#include <StackedMainWindow.h>

class LogPage;
class SplashPage;

class EvalMainWindow : public StackedMainWindow
{
    Q_OBJECT

public:
    EvalMainWindow(WidgetApplication *wapp);
    ~EvalMainWindow();

public slots:
    virtual void setup();

private:
    SplashPage * mpSplashPage=nullptr;
    LogPage * mpLogPage=nullptr;
};
