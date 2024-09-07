#include "Settings.h"

#include <QTimer>

#include <MillisecondTime.h>
#include <Value.h>

Settings::Settings(QObject *parent)
    : QObject{parent}
{
    qInfo() << Q_FUNC_INFO << "NoName";
    setObjectName("Settings");
    close();
}

Settings::Settings(const SettingsName &sname, QObject *parent)
    : QObject{parent}
{
    qInfo() << Q_FUNC_INFO << sname.toString();
    open(sname);
    setObjectName("Settings:" + SettingsName().toString());
}

void Settings::startWatch(const EpochMilliseconds ems)
{
    qInfo() << Q_FUNC_INFO << settingsName().toString() << ems;
    if ( ! mpWatchTimer)
    {
        mpWatchTimer = new QTimer(this);
    }
    connect(mpWatchTimer, &QTimer::timeout,
            this, &Settings::watcher);
    mpWatchTimer->start(ems);
}

void Settings::watcher()
{
    // MUSTDO
}

bool Settings::contains(const Key &key) const
{
    return qsettings()->contains(key());
}

QVariant Settings::get(const Key &key) const
{
    return contains(key) ? qsettings()->value(key()) : QVariant();
}

QVariant Settings::get(const Key &key, const QVariant &defalt) const
{
    return contains(key) ? get(key()) : defalt;
}

KeyMap Settings::map() const
{
    KeyMap result;
    foreach (const QString cSKey, qsettings()->allKeys())
    {
        const Value cValue(qsettings()->value(cSKey));
        result.insert(Key(cSKey), cValue);
    }
    return result;
}

KeyMap Settings::map(const Key &groupKey) const
{
    KeyMap result;
    Key tTempGroup = mCurrentGroup;
    tTempGroup.append(groupKey);
    const QString cTempGroupString = tTempGroup();
    qsettings()->endGroup();
    foreach (const QString cSKey, qsettings()->allKeys())
    {
        if (cSKey.startsWith(cTempGroupString))
        {
            const Value cValue(qsettings()->value(cSKey));
            result.insert(Key(cSKey), cValue);
        }
    }
    qsettings()->beginGroup(mCurrentGroup);
    return result;
}

bool Settings::open(const SettingsName &sname)
{
    bool result = false;
    close();
    mInstanceUid = Uid(true);
    qInfo() << Q_FUNC_INFO << sname.toString() << instanceUid().tail();
    switch(sname.type())
    {
    case SettingsName::OrgApp:
        mpQSettings = new QSettings(sname.scope(),
                                   sname.orgName(),
                                   sname.appName(), this);
        break;

    case SettingsName::IniFile:
        mpQSettings = new QSettings(sname.fileInfo()
                                       .absoluteFilePath(),
                                   QSettings::IniFormat, this);
        break;

    // TODO: Handle others?

    default:
        qCritical() << "Unhandled Settings:" << sname.toString();
        break;
    }
    mSettingsName = sname;

    result = mpQSettings->status() == QSettings::NoError;
    if (result)
    {
        emit opened(mSettingsName);
        qInfo() << "Settings::open(" << mSettingsName.toString() << ")";
        mpQSettings->setValue("Control/Opened", MillisecondTime::baseString());
        foreach (const Key cKey, mCurrentWatches.keys())
            mCurrentWatches.replace(cKey, mpQSettings->value(cKey()));
    }
    else
    {
        qCritical() << "Settings::open(" << mSettingsName.toString() << ") FAILED";
        emit openError(mSettingsName);
        mSettingsName.clear();
        close();
    }
    qInfo() << Q_FUNC_INFO << true << mSettingsName.toString() << instanceUid().tail();
    return result;
}

void Settings::close()
{
    qInfo() << Q_FUNC_INFO << mSettingsName.toString() << instanceUid().tail();
    if (mpWatchTimer) mpWatchTimer->stop();
    if (mpQSettings)
    {
        emit closed(mSettingsName);
        mpQSettings->deleteLater();
        mpQSettings = nullptr;
    }
    mCurrentGroup.clear();
    foreach (const Key cKey, mCurrentWatches.keys())
        mCurrentWatches.clear(cKey);
    mSettingsName.clear();
    qDebug() << Q_FUNC_INFO << "exit";
}
