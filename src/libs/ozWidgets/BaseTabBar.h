#pragma once
#include "ozWidgets.h"

#include <QTabBar>

class OZWIDGETS_EXPORT BaseTabBar : public QTabBar
{
    Q_OBJECT
public:
    BaseTabBar(QWidget *parent = nullptr);
};
