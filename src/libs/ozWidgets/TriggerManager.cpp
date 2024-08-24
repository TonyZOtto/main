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

TriggerItem TriggerManager::get(const Key &aKey) const
{
    return mKeyItemMap.value(aKey);
}

bool TriggerManager::set(const TriggerItem &aItem)
{
    const Key cKey = aItem.key();
    Q_ASSERT(cKey.notNull());
    const bool result = contains(cKey);
    if (result)
    {
        const TriggerItem cOldItem = get(cKey);
        mKeyItemMap.remove(cKey);
        mKeyItemMap.insert(cKey, aItem);
        emit replaced(aItem, cOldItem);
    }
    else
    {
        mKeyItemMap.insert(cKey, aItem);
        emit added(aItem);
    }
    return result;
}

void TriggerManager::remove(const Key &aKey)
{
    if (notContains(aKey))
    {
        qWarning() << "TriggerManager doesn't contain" << aKey;
        emit removed(TriggerItem());
    }
    else
    {
        emit removed(get(aKey));
        mKeyItemMap.remove(aKey);
    }
}
