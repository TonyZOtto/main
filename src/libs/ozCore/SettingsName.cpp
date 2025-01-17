#include "SettingsName.h"

#include <QCoreApplication>
#include <QRegularExpression>

#include "Types.h"


SettingsName::SettingsName(const bool orgapp)
    : mType(orgapp ? OrgApp : $null)
    , mSystemScope(false)
    , mOrgName(QCoreApplication::organizationName())
    , mAppName(QCoreApplication::applicationName()) {;}

SettingsName::SettingsName(const QString &name,
                           const bool okNotExist)
{
    set(name, okNotExist);
}

bool SettingsName::isValid() const
{
    return mType != $null;
}

QSettings::Scope SettingsName::scope() const
{
    return systemScope() ? QSettings::SystemScope : QSettings::UserScope;
}

QString SettingsName::toString() const
{
    QString result;
    if ($null == type())
        ; // leave empty
    else if (OrgApp == type())
        result = orgName() + ":" + appName();
    else // it must be a file of some kind
        result = fileInfo().filePath();
    return result;
}

void SettingsName::clear()
{
    mString.clear(),
    mType = $null,
    mSystemScope = false,
    mFileInfo = QFileInfo(),
    mOrgName.clear(),
    mAppName.clear();
}

SettingsName::Type SettingsName::setDefaltOrgApp()
{
    SettingsName::Type result = $null;
    mType = OrgApp,
    mSystemScope = false,
    mOrgName = QCoreApplication::organizationName(),
    mAppName = QCoreApplication::applicationName();
    result = mType;
    qDebug() << Q_FUNC_INFO << result << toString();
    return result;
}

SettingsName::Type SettingsName::set(const QString &name, const bool okNotExist)
{
    qInfo() << Q_FUNC_INFO << name << okNotExist;
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
    qInfo() << Q_FUNC_INFO << s << okNotExist;
    Type result = $null;
    QFileInfo tFI(s);
    if (tFI.exists() || okNotExist)
    {
        if (tFI.suffix().isEmpty())                 result = UnknownFile;
        else if (tFI.suffix().toUpper() == "INI")   result = IniFile;
        else if (tFI.suffix().toUpper() == "JSON")  result = JsonFile;
        else if (tFI.suffix().toUpper() == "XML")   result = XmlFile;
        else                                        result = UnknownFile;
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
    qInfo() << Q_FUNC_INFO << s;
    Type result = $null;
    if ( ! s.contains(':'))
        mOrgName = QCoreApplication::organizationName(), mAppName = s;
    else if (s.startsWith(':'))
        mOrgName = QCoreApplication::organizationName(), mAppName = s.mid(1);
    else if (s.endsWith(':'))
        mOrgName = s.first(s.length() - 1), mAppName = QCoreApplication::applicationName();
    else
    {
        Index ix = s.indexOf(':');
        Q_ASSERT(ix > 1);
        mOrgName = s.left(ix - 1);
        mAppName = s.mid(ix + 1);
    }
    if ( ! orgName().isEmpty() && ! appName().isEmpty())
        result = OrgApp;
    qDebug() << Q_FUNC_INFO << result << toString();
    return result;
}
