#pragma once

#include <QGuiApplication>
#include <QObject>

class ApplicationHelper;

class GuiApplication : public QGuiApplication
{
    Q_OBJECT
public:
    GuiApplication(int &argc, char **argv);

private:
    ApplicationHelper * mpHelper=nullptr;
};
