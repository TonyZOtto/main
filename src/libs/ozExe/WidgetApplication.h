#pragma once

#include <QApplication>
#include <QObject>

class ApplicationHelper;

class WidgetApplication : public QApplication
{
    Q_OBJECT
public:
    WidgetApplication(int &argc, char **argv);

private:
    ApplicationHelper * mpHelper=nullptr;
};
