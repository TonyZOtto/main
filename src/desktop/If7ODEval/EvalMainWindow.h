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
    virtual void initialize() override final;
    virtual void configure() override final;
    virtual void setup() override final;

signals:

public: // pointers

protected slots:


private:
};
