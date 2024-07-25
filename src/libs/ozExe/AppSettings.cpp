#include "AppSettings.h"

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

bool AppSettings::write(const bool all)
{
    Q_UNUSED(all); return false;
}
