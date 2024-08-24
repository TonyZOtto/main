#pragma once
#include "ozWidgets.h"

#include <QObject>

#include <QMap>

#include "TriggerItem.h"

class OZWIDGETS_EXPORT TriggerManager : public QObject
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

private slots:

private:
    QMap<Key, TriggerItem> mKeyItemMap;
};
