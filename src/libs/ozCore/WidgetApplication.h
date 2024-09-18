#pragma once
#include "ozCore.h"

#include <QApplication>
#include <QObject>

#include <ApplicationHelper.h>

class OZCORE_EXPORT WidgetApplication : public QApplication
{
    Q_OBJECT
public: // ctors
    WidgetApplication(int &argc, char **argv);

public slots:
    virtual void initialize();
    virtual void configure();
    virtual void setup();

signals:
    void initialized();
    void configured();
    void setuped();
    void startupComplete();
    void startupError(const QString errorString);

public:


private:
};
