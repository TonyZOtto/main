#pragma once
#include "ozCore.h"

#include <QFileInfo>
#include <QList>
#include <QSettings>
#include <QString>

class OZCORE_EXPORT SettingsName
{
public: // types
    typedef QList<SettingsName> List;
    enum Type
    {
        $null = 0,
        IniFile,
        JsonFile,
        XmlFile,
        UnknownFile,
        OrgApp,
        $max
    };

public: // ctors
    SettingsName();
    SettingsName(const QString &name, const bool okNotExist=false);

public: // const
    Type type() const;
    bool isValid() const;
    bool systemScope() const;
    QSettings::Scope scope() const;
    QFileInfo fileInfo() const;
    QString orgName() const;
    QString appName() const;
    QString toString() const;

public: // non-const
    void clear();
    Type setDefaltOrgApp();
    Type set(const QString &name, const bool okNotExist=false);

private:
    Type setFileName(const QString &s, const bool okNotExist=false);
    Type setOrgApp(const QString &s);

private:
    QString mString;
    Type mType=$null;
    bool mSystemScope=false;
    QFileInfo mFileInfo;
    QString mOrgName;
    QString mAppName;
};

inline SettingsName::Type SettingsName::type() const { return mType; }
inline bool SettingsName::systemScope() const { return mSystemScope; }
inline QFileInfo SettingsName::fileInfo() const { return mFileInfo; }
inline QString SettingsName::orgName() const { return mOrgName; }
inline QString SettingsName::appName() const { return mAppName; }
