#pragma once

#include "BaseMainWindow.h"

class QMdiArea;

class MdiMainWindow : public BaseMainWindow
{
    Q_OBJECT
public:
    MdiMainWindow(QWidget *parent = nullptr);

private:
    QMdiArea * mpMdiArea=nullptr;
};
