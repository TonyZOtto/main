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
    void setup(const QQSize aMaxSize);
};
