#include "AppSettings.h"

AppSettings::AppSettings(QObject *parent)
    : QObject{parent}
{
    setObjectName("AppSettings");
}

void AppSettings::open(const SettingsName &aName)
{

}

void AppSettings::start(const EpochMilliseconds &sampleMsec)
{

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

void AppSettings::close()
{

}
