#pragma once

#include <KeyMap.h>
class MachineHelper;
class StateMachine;

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


private slots:
    void initializeMachines();
    Key::List storedMachineStates();

private:
    StateMachine * mpInputMachine=nullptr;
    StateMachine * mpStoredMachine=nullptr;
    MachineHelper * mpInputHelper=nullptr;
    MachineHelper * mpStoredHelper=nullptr;
};
