#pragma once

#include <KeyMap.h>
class MachineHelper;

#include "EngineModule.h"
class EngineApplication;
class InputModuleMachine;
class LiveInputMachine;
class StoredInputMachine;

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
    InputModuleMachine * mpInputModuleMachine=nullptr;
    LiveInputMachine * mpLiveInputMachine=nullptr;
    StoredInputMachine * mpStoredInputMachine=nullptr;
    MachineHelper * mpLiveHelper=nullptr;
    MachineHelper * mpStoredHelper=nullptr;
};
