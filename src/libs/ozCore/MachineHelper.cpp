#include "MachineHelper.h"

#include "StateMachine.h"

MachineHelper::MachineHelper(StateMachine *parent)
    : QObject{parent}
    , mpMachine(parent)
{
    setObjectName("MachineHelper:" + machine()->objectName());
}

void MachineHelper::addStates(const Key::List &aStateKeyList)
{
    foreach (const Key cKey, aStateKeyList)
        (void)machine()->addState(cKey);
}

