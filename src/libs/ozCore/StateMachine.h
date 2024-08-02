#pragma once
#include "ozCore.h"

#include <QStateMachine>

#include <DualMap.h>
#include <Key.h>

class State;

class OZCORE_EXPORT StateMachine : public QStateMachine
{
    Q_OBJECT
public: // types
public: // ctors
    explicit StateMachine(const Key &aMachineKey, QObject *parent = nullptr);

public slots:
    virtual void initialize();

signals:
    void initialized();

public: // const
    const Key machineKey() const;
    const Key stateKey(State * pState) const;
    bool contains(const Key &aStateKey) const;
    bool contains(State * pState) const;

public: // non-const
    State * addState(const Key aStateKey);

public: // pointers
    State * state(const Key &aStateKey);

private:
    const Key cmMachineKey;
    DualMap<Key, State *> mKeyStateDMap;
};

inline const Key StateMachine::machineKey() const { return cmMachineKey; }
