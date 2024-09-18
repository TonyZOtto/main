#pragma once
#include "ozCore.h"

#include <QSharedDataPointer>

#include <QColor>
#include <QFont>
#include <QIcon>
#include <QSize>
#include <QLabel>
#include <QMenu>
#include <QPushButton>
#include <QString>
#include <QToolButton>
#include <QToolTip>

#include <Key.h>
//#include <AnyColor.h>

class TriggerItemData;

class OZCORE_EXPORT TriggerItem
{
public: // our ctors
    TriggerItem(const Key &aKey, const QString &text=QString());

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


