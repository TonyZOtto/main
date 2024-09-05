#pragma once

#include <WidgetApplication.h>

class EvalApplication : public WidgetApplication
{
    Q_OBJECT
public:
    EvalApplication(int &argc, char **argv);

public slots:
    void initialize();

signals:

};
