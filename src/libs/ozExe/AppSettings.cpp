#include "AppSettings.h"

#include <Success.h>

#include "SettingsItem.h"

AppSettings::AppSettings(QObject *parent)
    : QObject{parent}
{
    setObjectName("AppSettings");
}

void AppSettings::open(const SettingsName &aName)
{
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
            emit opened(settingsName());
        }
        else
        {
            emit openFail("Invalid Settings", settingsName());
            close();
        }
    }
}

void AppSettings::start(const EpochMilliseconds &sampleMsec)
{
    Q_UNUSED(sampleMsec);
}

void AppSettings::pause()
{

}

void AppSettings::resume()
{

}

void AppSettings::finish()
{

}

void AppSettings::close(const bool writeFirst)
{
    if (writeFirst)
        write();
    if (mpSettings)
    {
        emit closed(settingsName());
        mpSettings->deleteLater();
    }
}

bool AppSettings::isOpen() const
{
    Success success;
    success.expect(mpSettings);
    if (success.test())
        success.expect(mpSettings->status() == QSettings::NoError);
    return success();
}

bool AppSettings::contains(const Key &aKey)
{
    return mKeyItemMap.contains(fullKey(aKey));
}

SettingsItem AppSettings::get(const Key &aKey)
{
    return mKeyItemMap.value(aKey);
}

KeyMap AppSettings::map() const
{
    Q_ASSERT(!"MUSTDO"); // MUSTDO AppSettings::map()


    return KeyMap();
}

KeyMap AppSettings::map(const Key aGroupKey) const
{
    Q_ASSERT(!"MUSTDO"); // MUSTDO AppSettings::map(Key)
    Q_UNUSED(aGroupKey);
    return KeyMap();
}

bool AppSettings::write(const bool all)
{
    bool result = false;
    if (notOpen()) return result;
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

bool AppSettings::write(const Key aGroupKey)
{
    bool result = false;
    beginGroup(aGroupKey);
    write();
    endGroup(aGroupKey);
    return result;
}

bool AppSettings::defalt(const Key &aKey, const QVariant &aDefValue)
{
    bool result = false;
    if (notContains(aKey))
    {
        SettingsItem tItem(aKey, aDefValue);
        result = set(tItem, isOpen());
    }
    return result;
}

void AppSettings::defalt(const KeyMap &aDefaltMap)
{
    foreach (const Key cKey, aDefaltMap.keys())
    {
        const QVariant cDefalt = aDefaltMap.value(cKey);
        SettingsItem tItem(cKey, cDefalt);
        set(tItem);
    }
}

bool AppSettings::set(const Key &aKey, const QVariant &aNewValue)
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

bool AppSettings::set(SettingsItem /*copy*/ aItem, const bool aWrite)
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

void AppSettings::update(/*non-const ref*/KeyMap & aMap, const bool aWrite)
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

void AppSettings::update(const Key aGroupKey, KeyMap & aMap, const bool aWrite)
{
    if (notOpen()) return;
    beginGroup(aGroupKey);
    update(aMap, aWrite);
    endGroup(aGroupKey);
}

bool AppSettings::remove(const Key aKey)
{
    if (notOpen()) return false;
    bool result = settings()->contains(aKey);
    if (result)
        settings()->remove(aKey());
    return result;
}

SettingsItem::Flags &AppSettings::flags(const Key aKey)
{
    static SettingsItem::Flags stFlags;
    return contains(aKey) ? mKeyItemMap[aKey].flags() : stFlags;
}

Key AppSettings::fullKey(const Key &aKey)
{
    return mCurrentGroup + aKey;
}

Key AppSettings::beginGroup(const Key &aKey)
{
    mCurrentGroup.append(aKey);
    return mCurrentGroup;
}

QVariant AppSettings::value(const Key &aKey) const
{
    if (notOpen()) return QVariant();
    return settings()->value(aKey);
}

void AppSettings::setValue(const Key &aKey, const QVariant &aValue)
{
    if (notOpen()) return;
    settings()->setValue(aKey, aValue);
}

Key AppSettings::endGroup(const Key &aKey)
{
    mCurrentGroup.removeTail(aKey);
    return mCurrentGroup;
}
