#include "SettingsName.h"

#include <QCoreApplication>
#include <QRegularExpression>

#include "../Types.h"

SettingsName::SettingsName() {;}
SettingsName::SettingsName(const QString &name, const bool okNotExist) { set(name, okNotExist); }

QSettings::Scope SettingsName::scope() const
{
    return systemScope() ? QSettings::SystemScope : QSettings::UserScope;
}

SettingsName::Type SettingsName::set(const QString &name, const bool okNotExist)
{
    QString tName = name;
    mType = $null;
    mString = tName;
    mString.remove('%');
    mSystemScope = mString.startsWith('$');
    if (systemScope()) mString.removeFirst();
    if (mString.contains(QRegularExpression("[/.\\]")))
        mType = setFileName(mString, okNotExist);
    if ($null == mType)
        mType = setOrgApp(mString);
    return type();
}

SettingsName::Type SettingsName::setFileName(const QString &s, const bool okNotExist)
{
    Type result = $null;
    QQFileInfo tFI(s);
    if (tFI.exists() || okNotExist)
    {
        if (tFI.suffix().isEmpty())      result = UnknownFile;
        else if (tFI.isSuffix("INI"))    result = IniFile;
        else if (tFI.isSuffix("JSON"))   result = JsonFile;
        else if (tFI.isSuffix("XML"))    result = XmlFile;
    }
    if (result != $null)
    {
        mType = result;
        mFileInfo = tFI;
    }
    return result;
}

SettingsName::Type SettingsName::setOrgApp(const QString &s)
{
    Type result = $null;
    if ( ! s.contains(':'))
        mOrgName = QCoreApplication::organizationName(), mAppName = s;
    else if (s.startsWith(':'))
        mOrgName = QCoreApplication::organizationName(), mAppName = s.mid(1);
    else if (s.endsWith(':'))
        mOrgName = s.first(s.count() - 1), mAppName = QCoreApplication::applicationName();
    else
    {
        Index ix = s.indexOf(':');
        Q_ASSERT(ix > 1);
        mOrgName = s.left(ix - 1);
        mAppName = s.mid(ix + 1);
    }
    if ( ! orgName().isEmpty() && ! appName().isEmpty())
        result = OrgApp;
    return result;
}
