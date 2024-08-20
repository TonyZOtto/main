#include "BaseStackedLayout.h"

BaseStackedLayout::BaseStackedLayout()
{
    setObjectName("BaseStackedLayout");
}

BaseStackedLayout::BaseStackedLayout(QWidget *parentWidget) : QStackedLayout(parentWidget)
{
    setObjectName("BaseStackedLayout");
}

BaseStackedLayout::BaseStackedLayout(QLayout *parentLayout) : QStackedLayout(parentLayout)
{
    setObjectName("BaseStackedLayout");
}

