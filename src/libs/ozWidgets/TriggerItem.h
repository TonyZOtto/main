#pragma once

#include <QSharedDataPointer>

#include <QColor>
#include <QFont>
#include <QIcon>
#include <QSize>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QToolTip>

#include <Key.h>
//#include <AnyColor.h>

#include "BaseToolButton.h"

class TriggerItemData;

class TriggerItem
{
public: // our ctors
    TriggerItem(const Key &aKey);


public: // QSharedDataPointer functions
    TriggerItem();
    TriggerItem(const TriggerItem &);
    TriggerItem &operator=(const TriggerItem &);
    ~TriggerItem();

private:
    QSharedDataPointer<TriggerItemData> data;
};
