#include "TriggerManager.h"

TriggerManager::TriggerManager(QObject *parent)
    : QObject{parent}
{
    setObjectName("TriggerManager");
}

bool TriggerManager::contains(const Key &aKey)
{
    return mKeyItemMap.contains(aKey);
}

TriggerItem TriggerManager::item(const Key &aKey)
{
    return mKeyItemMap.get(aKey);
}

void TriggerManager::add(const TriggerItem &aItem)
{
    if (contains(aItem.key()))
        qWarning() << "TriggerManager already contains" << aItem.key();
    mKeyItemMap.set(aItem.key(), aItem);
}

void TriggerManager::remove(const Key &aKey)
{
    if (notContains(aKey))
        qWarning() << "TriggerManager doesn't contain" << aKey;
    mKeyItemMap.remove(aKey);
}
