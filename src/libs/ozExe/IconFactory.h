#pragma once

#include <QObject>

#include <QIcon>
#include <QMap>

#include <Key.h>
#include <QQSize.h>
#include <QQDir.h>

#include "IconFactoryColorSet.h"

class IconFactory : public QObject
{
    Q_OBJECT
public: // types
    enum Flag
    {
        $null       =   0,
        Base        =   1,
        NormalOff   =   16 << QIcon::Normal     | 8 << QIcon::Off,
        DisabledOff =   16 << QIcon::Disabled   | 8 << QIcon::Off,
        ActiveOff   =   16 << QIcon::Active     | 8 << QIcon::Off,
        SelectedOff =   16 << QIcon::Selected   | 8 << QIcon::Off,
        NormalOn    =   16 << QIcon::Normal     | 8 << QIcon::On,
        DisabledOn  =   16 << QIcon::Disabled   | 8 << QIcon::On,
        ActiveOn    =   16 << QIcon::Active     | 8 << QIcon::On,
        SelectedOn  =   16 << QIcon::Selected   | 8 << QIcon::On,
    };
    Q_DECLARE_FLAGS(Flags, Flag);

public: // ctors
    explicit IconFactory(QObject *parent = nullptr);
    IconFactory(const QDir &aBaseDir, QObject *parent = nullptr);

public slots:
    void createIcon(const Key &aIconKey, const QQSize aSize);

signals:
    void iconCreated(const Key &aIconKey, const QIcon &aIcon);

public: // const
    const QDir baseDir() const;

public: // non-const
    void set(const Flags aFlags, const IconFactoryColorSet &aColorSet);
    bool baseDir(const QDir &aBaseDir);

private: // const
    QByteArray generateSvg(const Key &aIconKey, const QQSize aSize, const Flag aFlag);

private:
    QQDir mBaseDir;
    QMap<Flag, IconFactoryColorSet> mFlagColorSetMap;
    QMap<Key, QByteArray> mKeySvgBytesMap;
    QMap<Key, QIcon> mKeyIconMap;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(IconFactory::Flags)

inline const QDir IconFactory::baseDir() const { return mBaseDir; }
