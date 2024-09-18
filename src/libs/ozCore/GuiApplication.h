#pragma once
#include "ozCore.h"

#include <QGuiApplication>
#include <QObject>

class ApplicationHelper;

class OZCORE_EXPORT GuiApplication : public QGuiApplication
{
    Q_OBJECT
public:
    GuiApplication(int &argc, char **argv);

private:
};
