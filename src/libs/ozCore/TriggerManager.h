#pragma once
#include "ozCore.h"

#include <QObject>

#include <QMap>

#include "TriggerItem.h"

class OZCORE_EXPORT TriggerManager : public QObject
{
    Q_OBJECT
public: // ctors
    explicit TriggerManager(QObject *parent = nullptr);

public slots:

signals:
    void added(const TriggerItem &item);
    void replaced(const TriggerItem &newItem, const TriggerItem &oldItem);
    void removed(const TriggerItem &item);

public: // const
    bool contains(const Key &aKey);
    bool notContains(const Key &aKey) { return ! contains(aKey); }
    TriggerItem get(const Key &aKey) const;

public: // non-const
    bool set(const TriggerItem &aItem);
    void remove(const Key &aKey);
    TriggerItem & item(const Key &aKey);
    TriggerItem & operator [] (const Key &aKey) { return item(aKey); }

private slots:

private:
    QMap<Key, TriggerItem> mKeyItemMap;
};
