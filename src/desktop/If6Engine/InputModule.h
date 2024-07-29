#pragma once

#include <KeyMap.h>

#include "EngineModule.h"
class EngineApplication;

class InputModule : public EngineModule
{
    Q_OBJECT
public:
    explicit InputModule(EngineApplication *parent = nullptr);


public slots:
    virtual void initialize();

signals:

public: // const
    virtual Success isValid() const;
    virtual KeyMap defaltSettings() const;


private:

};
