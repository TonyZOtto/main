#pragma once
#include "ozExe.h"

#include <QObject>

#include <QSettings>
#include <QVariant>
class QTimer;

#include <Key.h>
#include <KeyMap.h>
#include <SettingsName.h>
#include <Types.h>
#include <Uid.h>

class OZEXE_EXPORT Settings : public QObject
{
    Q_OBJECT
public: // ctors
    Settings(QObject *parent=nullptr);
    Settings(const SettingsName &sname, QObject *parent=nullptr);

public slots:
    void startWatch(const EpochMilliseconds ems);
    void watcher();

signals:
    void opened(const SettingsName &sname);
    void openError(const SettingsName &sname);
    void closed(const SettingsName &sname);
    void got(const Key &key, const QVariant &value);
    void seted(const Key &key, const QVariant &value);
    void added(const Key &key, const QVariant &newValue);
    void changed(const Key &key, const QVariant &newValue, const QVariant &oldValue);
    void removed(const Key &key, const QVariant &oldValue);
    void watching(const Key &key, const QVariant &value);
    void watchedChanged(const Key &key, const QVariant &newValue, const QVariant &oldValue);
    void groupChanged(const Key &key);

public: // const
    bool contains(const Key &key) const;
    QVariant get(const Key &key) const;
    QVariant get(const Key &key, const QVariant &defalt) const;
    Uid instanceUid() const;
    SettingsName settingsName() const;
    KeyMap map() const;
    KeyMap map(const Key &groupKey) const;

public: // non-const
    bool open(const SettingsName &sname);
    void watch(const Key &key);
    void unwatch(const Key &key);
    QVariant set(const Key &key, const QVariant &value);
    Key beginGroup(const Key &groupKey);
    Key setGroup(const Key &groupKey);
    Key endGroup(const Key &groupKey);
    void endGroup();

public: // pointers
    QSettings * qsettings() const;

private:
    void close();
    Key rootKey(const Key &key);

private:
    QSettings * mpQSettings=nullptr;
    QTimer * mpWatchTimer=nullptr;
    Uid mInstanceUid;
    SettingsName mSettingsName;
    Key mCurrentGroup;
    KeyMap mCurrentWatches;


};

inline Uid Settings::instanceUid() const  { return mInstanceUid; }
inline SettingsName Settings::settingsName() const { return mSettingsName; }
inline QSettings *Settings::qsettings() const { Q_ASSERT(mpQSettings); return mpQSettings; }
