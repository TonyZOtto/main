#pragma once

#include <Value.h>
#include <StackedMainWindow.h>

class AcquirePage;
class LogPage;
class SplashPage;

class EvalMainWindow : public StackedMainWindow
{
    Q_OBJECT

public: // ctors
    EvalMainWindow(WidgetApplication *wapp);
    ~EvalMainWindow();

public slots:
    virtual void initialize();
    virtual void configure();
    virtual void setup();

signals:

public: // pointers
    AcquirePage * acquirePage();

private:
};
