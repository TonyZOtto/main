#pragma once

#include <QState>

#include <Key.h>

class StateMachine;

class State : public QState
{
    Q_OBJECT
public: // types

public: // ctors
    State(const Key &aStateKey, StateMachine *parent = nullptr);

public slots:

signals:

public: // const
    const Key stateKey() const;

public: // non-const

public: // pointers
public: // pointers
    StateMachine * machine();

private:

private:
    StateMachine * mpMachine=nullptr;
    const Key cmStateKey;
};

inline const Key State::stateKey() const { return cmStateKey; }
inline StateMachine *State::machine() { Q_ASSERT(mpMachine); return mpMachine; }
