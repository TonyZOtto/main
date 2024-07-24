#pragma once

#include <QApplication>
#include <QObject>

class WidgetApplication : public QApplication
{
    Q_OBJECT
public:
    WidgetApplication();
};
