#include "delAppSettings.h"

#include <Success.h>

#include "SettingsItem.h"

delAppSettings::delAppSettings(QObject *parent)
    : QObject{parent}
{
    qInfo() << Q_FUNC_INFO << (parent ? parent->objectName() : "NULL");
    setObjectName("AppSettings");
}

void delAppSettings::open(const SettingsName &aName)
{
    qInfo() << Q_FUNC_INFO << aName.toString();
    close();
    mSettingsName = aName;
    switch (settingsName().type())
    {
    case SettingsName::IniFile:
        mpSettings = new QSettings(settingsName().fileInfo()
            .filePath(), QSettings::IniFormat, this);
        break;
    case SettingsName::OrgApp:
        mpSettings = new QSettings(settingsName().scope(),
            settingsName().orgName(), settingsName().appName(), this);
        break;
    default:
        qWarning() << "Unhandled Settings Type:"
                   << settingsName().type();
        emit openFail("Unhandled Settings Type", settingsName());
        break;
    }
    if (mpSettings)
    {
        if (mpSettings->status() == QSettings::NoError)
        {
            qDebug() << "Settings opened:" << settingsName().toString();

            emit opened(settingsName());
        }
        else
        {
            qWarning() << "Settings->status()" << mpSettings->status();
            emit openFail("Invalid Settings", settingsName());
            close();
        }
    }
}

void delAppSettings::start(const EpochMilliseconds &sampleMsec)
{
    qInfo() << Q_FUNC_INFO << "TODO: UNUSED" << sampleMsec;
    Q_UNUSED(sampleMsec);
}

void delAppSettings::pause()
{
    qInfo() << Q_FUNC_INFO << "TODO";

}

void delAppSettings::resume()
{
    qInfo() << Q_FUNC_INFO << "TODO";

}

void delAppSettings::finish()
{
    qInfo() << Q_FUNC_INFO << "TODO";

}

void delAppSettings::close(const bool writeFirst)
{
    qInfo() << Q_FUNC_INFO << settingsName().toString() << writeFirst;
    if (writeFirst)
        write();
    if (mpSettings)
    {
        emit closed(settingsName());
        mpSettings->deleteLater();
    }
}

bool delAppSettings::isOpen() const
{
    Success success;
    success.expect(mpSettings);
    if (success.test())
        success.expect(mpSettings->status() == QSettings::NoError);
    qInfo() << Q_FUNC_INFO << success();
    return success();
}

bool delAppSettings::contains(const Key &aKey)
{
    return mKeyItemMap.contains(fullKey(aKey));
}

SettingsItem delAppSettings::get(const Key &aKey) const
{
    return mKeyItemMap.value(aKey);
}

KeyMap delAppSettings::map() const
{
    Q_ASSERT(!"MUSTDO"); // MUSTDO AppSettings::map()
    return KeyMap();
}

KeyMap delAppSettings::map(const Key aGroupKey) const
{
    qInfo() << Q_FUNC_INFO << aGroupKey;
    KeyMap result;
    settings()->beginGroup(aGroupKey());
    const QStringList cKeys = settings()->allKeys();
    foreach (const QString cKey, cKeys)
    {
        const SettingsItem cItem = get(cKey);
        const QVariant cValue = cItem.value();
        result.insert(cKey, cValue);
    }
    settings()->endGroup();
    return result;
}

bool delAppSettings::write(const bool all)
{
    qInfo() << Q_FUNC_INFO << all;
    bool result = false;
    if (notOpen()) return result;                       /*=====*/
    settings()->beginGroup(mCurrentGroup());
    foreach (const Key cKey, mKeyItemMap.keys())
    {
        SettingsItem tItem = get(cKey);
        if (tItem.flags().testFlag(SettingsItem::Dirty) || all)
            settings()->setValue(cKey, tItem.value());
        tItem.flags().setFlag(SettingsItem::Dirty, false);
        tItem.flags().setFlag(SettingsItem::Changed, false);
        result = set(tItem);
    }
    if (mCurrentGroup.notNull())
        settings()->endGroup();
    return result;
}

bool delAppSettings::write(const Key aGroupKey)
{
    qInfo() << Q_FUNC_INFO << aGroupKey;
    bool result = false;
    beginGroup(aGroupKey);
    write();
    endGroup(aGroupKey);
    return result;
}

bool delAppSettings::defalt(const Key &aKey, const QVariant &aDefValue)
{
    bool result = false;
    if (notContains(aKey))
    {
        SettingsItem tItem(aKey, aDefValue);
        result = set(tItem, isOpen());
    }
    return result;
}

void delAppSettings::defalt(const KeyMap &aDefaltMap)
{
    foreach (const Key cKey, aDefaltMap.keys())
    {
        const QVariant cDefalt = aDefaltMap.value(cKey);
        SettingsItem tItem(cKey, cDefalt);
        set(tItem);
    }
}

bool delAppSettings::set(const Key &aKey, const QVariant &aNewValue)
{
    SettingsItem tItem;
    if (contains(aKey))
        tItem = mKeyItemMap.value(aKey);
    else
        tItem.key(aKey);
    tItem.previousValue(tItem.currentValue());
    tItem.currentValue(aNewValue);
    return set(tItem);
}

bool delAppSettings::set(SettingsItem /*copy*/ aItem, const bool aWrite)
{
    mKeyItemMap.remove(aItem.key());
    aItem.flags().setFlag(SettingsItem::Changed);
    aItem.flags().setFlag(SettingsItem::Dirty);
    mKeyItemMap.insert(aItem.key(), aItem);
    if (aWrite)
        return write();
    else
        return true;
}

void delAppSettings::update(/*non-const ref*/KeyMap & aMap, const bool aWrite)
{
    foreach (const Key cKey, aMap.keys())
    {
        if ( ! contains(cKey))
            remove(cKey);
        if (aMap.value(cKey) != get(cKey).value())
            set(cKey, aMap.value(cKey));
    }
    if (aWrite)
        write(true);
}

void delAppSettings::update(const Key aGroupKey, KeyMap & aMap, const bool aWrite)
{
    if (notOpen()) return;
    beginGroup(aGroupKey);
    update(aMap, aWrite);
    endGroup(aGroupKey);
}

bool delAppSettings::remove(const Key aKey)
{
    if (notOpen()) return false;
    bool result = settings()->contains(aKey);
    if (result)
        settings()->remove(aKey());
    return result;
}

SettingsItem::Flags &delAppSettings::flags(const Key aKey)
{
    static SettingsItem::Flags stFlags;
    return contains(aKey) ? mKeyItemMap[aKey].flags() : stFlags;
}

Key delAppSettings::fullKey(const Key &aKey)
{
    return mCurrentGroup + aKey;
}

Key delAppSettings::beginGroup(const Key &aKey)
{
    mCurrentGroup.append(aKey);
    return mCurrentGroup;
}

QVariant delAppSettings::value(const Key &aKey) const
{
    if (notOpen()) return QVariant();
    return settings()->value(aKey);
}

void delAppSettings::setValue(const Key &aKey, const QVariant &aValue)
{
    if (notOpen()) return;
    settings()->setValue(aKey, aValue);
}

Key delAppSettings::endGroup(const Key &aKey)
{
    mCurrentGroup.removeTail(aKey);
    return mCurrentGroup;
}
