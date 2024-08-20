#pragma once

#include <GridMainWindow.h>

class MainWindow : public GridMainWindow
{
    Q_OBJECT

public:
    MainWindow(WidgetApplication *wapp);
    ~MainWindow();
};
