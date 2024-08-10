#include "InputModuleMachine.h"

#include "State.h"

InputModuleMachine::InputModuleMachine(QObject *parent)
    : StateMachine{"InputModuleMachine", parent}
{
    setObjectName("InputModuleMachine");
}

void InputModuleMachine::initialize()
{
    State * pIdleState = new State("Idle", this);

    setInitialState(pIdleState);
}
