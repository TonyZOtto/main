#pragma once
#include "ozExe.h"

#include <QGuiApplication>
#include <QObject>

class ApplicationHelper;

class OZEXE_EXPORT GuiApplication : public QGuiApplication
{
    Q_OBJECT
public:
    GuiApplication(int &argc, char **argv);

private:
    ApplicationHelper * mpHelper=nullptr;
};
