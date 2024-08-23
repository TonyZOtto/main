#pragma once
#include "ozWidgets.h"

#include <QObject>

#include <KeyMapT.h>

#include "TriggerItem.h"

class OZWIDGETS_EXPORT TriggerManager : public QObject
{
    Q_OBJECT
public: // ctors
    explicit TriggerManager(QObject *parent = nullptr);

public slots:

signals:

public: // const
    bool contains(const Key &aKey);
    bool notContains(const Key &aKey) { return ! contains(aKey); }
    TriggerItem item(const Key &aKey);

public: // non-const
    void add(const TriggerItem &aItem);
    void remove(const Key &aKey);

private slots:

private:
    KeyMapT<TriggerItem> mKeyItemMap;
};
