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
public: // ctors
    explicit InputModule(EngineApplication *parent = nullptr);


public slots:
    virtual void initialize();
    virtual void configure();

signals:
    void shutdown();
    void newLiveUrl();
    void newStoredUrl();

public: // const
    virtual Success isValid() const;
    virtual KeyMap defaltSettings() const;

public: // pointers


private slots:
    void initializeMachines();
    void urlChanged(const QUrl &newUrl);
    void watchedChanged(const Key &aKey,
                        const QVariant &aNewValue,
                        const QVariant &aOldValue);

private: // non-const
    Key::List storedMachineStates();

private:
    InputModuleMachine * mpInputModuleMachine=nullptr;
    LiveInputMachine * mpLiveInputMachine=nullptr;
    StoredInputMachine * mpStoredInputMachine=nullptr;
    MachineHelper * mpLiveHelper=nullptr;
    MachineHelper * mpStoredHelper=nullptr;
};


