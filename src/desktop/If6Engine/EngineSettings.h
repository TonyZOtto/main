#pragma once

#include <AppSettings.h>

class EngineSettings : public AppSettings
{
    Q_OBJECT
public:
    explicit EngineSettings(QObject *parent = nullptr);
};
