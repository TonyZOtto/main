#pragma once

#include "EngineModule.h"
class EngineApplication;

class OutputModule : public EngineModule
{
    Q_OBJECT
public:
    explicit OutputModule(EngineApplication *parent = nullptr);

public slots:
    virtual void initialize();

signals:

public: // const
    virtual Success isValid() const;
    virtual KeyMap defaltSettings() const;


private:

};
