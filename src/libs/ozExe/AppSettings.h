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

class OZEXE_EXPORT AppSettings : public QObject
{
    Q_OBJECT
public: // types

public: // ctors
    explicit AppSettings(QObject *parent = nullptr);

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
    bool contains(const Key &aKey);
    KeyMap map() const;
    KeyMap map(const Key aGroupKey) const;
    SettingsName settingsName() const;

public: // non-const
    bool read();
    bool read(const Key aGroupKey);
    bool write(const bool all=false);
    SettingsItem get(const Key &aKey);
    bool defalt(const Key &aKey, const QVariant &aDefValue);
    bool defalt(const Key &aKey);
    bool defalt(const Key::List &aKeyList);
    bool set(const Key &aKey, const QVariant &aNewValue);
    bool set(const SettingsItem &aItem);
    void set(const KeyMap &aMap);
    void defalt(const KeyMap &aMap);
    void set(const Key aGroupKey, const KeyMap &aMap);
    void defalt(const Key aGroupKey, const KeyMap &aMap);
    void watch(const Key aKey);
    void remove(const Key aKey);
    void removeGroup(const Key aGroupKey);

public: // pointers

private:
    SettingsName mSettingsName;
    QSettings * mpSettings=nullptr;
    QTimer * mpUpdateTimer=nullptr;
    EpochMilliseconds mUpdateMsec=0;
    bool mIsPaused=false;
    QMutex mReadWriteMutex;
    Key::List mWatchKeyList;
    QMap<Key, SettingsItem> mKeyItemMap;
};

inline SettingsName AppSettings::settingsName() const { return mSettingsName; }
