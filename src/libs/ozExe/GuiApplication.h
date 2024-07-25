#pragma once

#include <QGuiApplication>
#include <QObject>

class GuiApplication : public QGuiApplication
{
    Q_OBJECT
public:
    GuiApplication(int &argc, char **argv);
};
