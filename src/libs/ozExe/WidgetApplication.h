#pragma once
#include "ozExe.h"

#include <QApplication>
#include <QObject>

#include <ApplicationHelper.h>

class OZEXE_EXPORT WidgetApplication : public QApplication
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
    void startupError(const QString errorString);

public:


private:
};
