#pragma once

#include <QList>
#include <QSettings>
#include <QString>

#include "../filesys/FileInfo.h"



class SettingsName
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
    bool systemScope() const;
    QSettings::Scope scope() const;
    FileInfo fileInfo() const;
    QString orgName() const;
    QString appName() const;

public: // non-const
    Type set(const QString &name, const bool okNotExist=false);

private:
    Type setFileName(const QString &s, const bool okNotExist=false);
    Type setOrgApp(const QString &s);


private:
    QString mString;
    Type mType=$null;
    bool mSystemScope=false;
    FileInfo mFileInfo;
    QString mOrgName;
    QString mAppName;
};

inline SettingsName::Type SettingsName::type() const
{
    return mType;
}

inline bool SettingsName::systemScope() const
{
    return mSystemScope;
}
inline FileInfo SettingsName::fileInfo() const
{
    return mFileInfo;
}
inline QString SettingsName::orgName() const
{
    return mOrgName;
}
inline QString SettingsName::appName() const
{
    return mAppName;
}
