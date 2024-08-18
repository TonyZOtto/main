#pragma once
#include "ozWidgets.h"

#include <QGridLayout>

class OZWIDGETS_EXPORT BaseGridLayout : public QGridLayout
{
    Q_OBJECT
public:
    BaseGridLayout(QWidget *parent = nullptr);
};
