#pragma once

#include <QStackedLayout>

class BaseStackedLayout : public QStackedLayout
{
    Q_OBJECT
public:
    BaseStackedLayout();
    BaseStackedLayout(QWidget *parentWidget);
    BaseStackedLayout(QLayout *parentLayout);
};
