#pragma once

#include <QSharedDataPointer>

#include <QColor>
#include <QFont>
#include <QIcon>
#include <QSize>
#include <QLabel>
#include <QMenu>
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

public: // const
    Key key() const;
    QString text() const;
    QString title() const;
/*    bool keyEquals(const TriggerItem &other) const;
    bool keyLess(const TriggerItem &other) const;
    bool operator == (const TriggerItem &other) const;
    bool operator <  (const TriggerItem &other) const;
*/
public: // non-const
    void key(const Key &aKey);
    void text(const Key &aString);
    void title(const Key &aString);
    QAction * action();

public: // QSharedDataPointer functions
    TriggerItem();
    TriggerItem(const TriggerItem &);
    TriggerItem &operator=(const TriggerItem &);
    ~TriggerItem();

private:
    QSharedDataPointer<TriggerItemData> data;

};


