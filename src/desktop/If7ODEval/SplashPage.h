#pragma once

#include <QQSize.h>
#include <StackedMainPage.h>

class SplashPage : public StackedMainPage
{
    Q_OBJECT
public:
    SplashPage(StackedMainWindow *parent);

public slots:

signals:

public: // const

public: // non-const
    virtual void initialize() override final;
    virtual void configure() override final;
    virtual void setup() override final;

public: // pointers

protected slots:
    virtual void handleResize(const QQSize newSize) override final;


private:

};

