#pragma once

#include <StackedMainWindow.h>

class MainWindow : public StackedMainWindow
{
    Q_OBJECT

public:
    MainWindow(WidgetApplication *wapp);
    ~MainWindow();

private:
};
