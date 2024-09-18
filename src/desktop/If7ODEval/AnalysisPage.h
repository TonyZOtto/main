#pragma once

#include <StackedMainPage.h>

#include <FillerWidget.h>

class AnalysisPage : public StackedMainPage
{
    Q_OBJECT
public:
    AnalysisPage(StackedMainWindow *parent);

public slots:

signals:

public: // const

public: // non-const
    virtual void initialize() override final;
    virtual void configure() override final;
    virtual void setup() override final;

public: // pointers

private:
};
