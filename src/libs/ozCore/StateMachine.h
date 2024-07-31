#pragma once

#include <QStateMachine>

#include <DualMap.h>
#include <Key.h>

class State;

class StateMachine : public QStateMachine
{
    Q_OBJECT
public: // types
public: // ctors
    explicit StateMachine(const Key &aMachineKey, QObject *parent = nullptr);

public slots:
    State * addState(const Key aStateKey);

signals:

public: // const
    const Key machineKey() const;
    const Key stateKey(State * pState) const;
    bool contains(const Key &aStateKey) const;
    bool contains(State * pState) const;

public: // non-const

public: // pointers
    State * state(const Key &aStateKey);

private:
    const Key cmMachineKey;
    DualMap<Key, State *> mKeyStateDMap;
};

inline const Key StateMachine::machineKey() const { return cmMachineKey; }
