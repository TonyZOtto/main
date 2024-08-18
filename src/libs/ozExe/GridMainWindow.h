#pragma once

#include "BaseMainWindow.h"

class BaseGridLayout;

class GridMainWindow : public BaseMainWindow
{
    Q_OBJECT
public:
    GridMainWindow(QWidget *parent = nullptr);
    GridMainWindow(BaseGridLayout * pGrid,
                   QWidget *parent = nullptr);

private:
    BaseGridLayout * mpGridLayout=nullptr;
};
