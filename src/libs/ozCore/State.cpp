#include "State.h"

#include "StateMachine.h"

State::State(const Key &aStateKey, StateMachine *parent)
    : QState(parent)
    , mpMachine(parent)
    , cmStateKey(aStateKey)
{
    setObjectName("State:" + stateKey()()
                  + "<" + machine()->machineKey()());
}

