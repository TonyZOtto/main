#include "StoredInputMachine.h"

StoredInputMachine::StoredInputMachine(QObject *parent)
    : StateMachine{"StoredInputMachine", parent}
{
    setObjectName("StoredInputMachine");

}

void StoredInputMachine::initialize()
{

}
