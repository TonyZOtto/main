#pragma once

#include "EngineModule.h"
class EngineApplication;

class MarkerModule : public EngineModule
{
    Q_OBJECT
public:
    explicit MarkerModule(EngineApplication *parent = nullptr);
};
