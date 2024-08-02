#include "StateMachine.h"

#include "State.h"

StateMachine::StateMachine(const Key &aMachineKey, QObject *parent)
    : QStateMachine(parent)
    , cmMachineKey(aMachineKey)
{
    setObjectName("StateMachine:" + machineKey()());
}

void StateMachine::initialize()
{

}

State *StateMachine::addState(const Key aStateKey)
{
    if (mKeyStateDMap.contains(aStateKey))
    {
        State * pOldState = mKeyStateDMap.at(aStateKey);
        pOldState->deleteLater();
        mKeyStateDMap.remove(aStateKey);
    }
    State * result = new State(aStateKey, this);
    mKeyStateDMap.insertUnique(aStateKey, result);
    return result;
}

const Key StateMachine::stateKey(State *pState) const
{
    return mKeyStateDMap.at(pState);
}

bool StateMachine::contains(const Key &aStateKey) const
{
    return mKeyStateDMap.contains(aStateKey);
}

bool StateMachine::contains(State *pState) const
{
    return mKeyStateDMap.contains(pState);
}

State *StateMachine::state(const Key &aStateKey)
{
    return mKeyStateDMap.at(aStateKey);
}

