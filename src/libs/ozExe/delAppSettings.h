#pragma once
#include "ozExe.h"

#include <QObject>

#include <QMap>
#include <QSettings>
#include <QMutex>
#include <QTimer>

#include <Key.h>
#include <KeyMap.h>

#include "SettingsItem.h"
#include "SettingsName.h"

class QSettings;

class OZEXE_EXPORT delAppSettings : public QObject
{
    Q_OBJECT
public: // types

public: // ctors
    explicit delAppSettings(QObject *parent = nullptr);

public slots:
    void open(const SettingsName &aName);
    void start(const EpochMilliseconds &sampleMsec);
    void pause();
    void resume();
    void finish();
    void close(const bool writeFirst=false);

signals:
    void opened(const SettingsName &aName);
    void openFail(const QString errorMessage,
                  const SettingsName &aName);
    void closed(const SettingsName &aName);
    void changed(const Key &aKey,
                 const QVariant &aNewValue,
                 const QVariant &aOldValue);
    void updated(const Key &aKey,
                 const QVariant &aNewValue,
                 const QVariant &aOldValue);
    void watched(const Key &aKey,
                 const QVariant &aNewValue,
                 const QVariant &aOldValue);
    void seted(const Key &aKey,
                const QVariant &aNewValue);
    void readed(const SettingsName &aSName,
                const Key &aKey,
                const QVariant &aNewValue,
                const QVariant &aOldValue);
    void written(const SettingsName &aSName,
                 const Key &aKey,
                 const QVariant &aNewValue);
    void started();
    void paused();
    void resumed();
    void finished();

public: // const
    bool isOpen() const;
    bool notOpen() const { return ! isOpen(); }
    bool contains(const Key &aKey);
    bool notContains(const Key &aKey) { return ! contains(aKey); }
    SettingsItem get(const Key &aKey) const;
    KeyMap map() const;
    KeyMap map(const Key aGroupKey) const;
    SettingsName settingsName() const;

public: // non-const
    bool read();
    bool read(const Key aGroupKey);
    bool write(const bool all=false);
    bool write(const Key aGroupKey);
    bool defalt(const Key &aKey, const QVariant &aDefValue);
    bool defalt(const Key::List &aKeyList);
    void defalt(const KeyMap &aDefaltMap);
    bool set(const Key &aKey, const QVariant &aNewValue);
    bool set(SettingsItem /*copy*/ aItem, const bool aWrite=false);
    void set(const KeyMap &aMap);
    void set(const Key aGroupKey, const KeyMap &aMap);
    void update(/*non-const ref*/KeyMap &aMap, const bool aWrite=false);
    void update(const Key aGroupKey, /*non-const ref*/KeyMap &aMap, const bool aWrite=false);
    void defalt(const Key aGroupKey, const KeyMap &aMap);
    void watch(const Key aKey);
    bool remove(const Key aKey);
    void removeGroup(const Key aGroupKey);
    SettingsItem::Flags & flags(const Key aKey);

private:
    Key fullKey(const Key &aKey);
    Key beginGroup(const Key &aKey);
    QVariant value(const Key &aKey) const;
    void setValue(const Key &aKey, const QVariant &aValue);
    Key endGroup(const Key &aKey);
    void endGroup();

public: // pointers
    QSettings * settings() const;

private:
    SettingsName mSettingsName;
    QSettings * mpSettings=nullptr;
    QTimer * mpUpdateTimer=nullptr;
    EpochMilliseconds mUpdateMsec=0;
    bool mIsPaused=false;
    QMutex mReadWriteMutex;
    Key::List mWatchKeyList;
    Key mCurrentGroup;
    QMap<Key, SettingsItem> mKeyItemMap;
};

inline SettingsName delAppSettings::settingsName() const { return mSettingsName; }
inline QSettings *delAppSettings::settings() const { Q_ASSERT(mpSettings); return mpSettings; }
