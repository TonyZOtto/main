#pragma once

#include <WidgetApplication.h>

class EvalApplication : public WidgetApplication
{
    Q_OBJECT
public:
    EvalApplication(int &argc, char **argv);

public slots:
    virtual void initialize() override final;
    virtual void configure();
    virtual void setup();

signals:

};
