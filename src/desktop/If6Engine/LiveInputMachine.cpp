#include "LiveInputMachine.h"

LiveInputMachine::LiveInputMachine(QObject *parent)
    : StateMachine{"LiveInputMachine", parent}
{
    setObjectName("LiveInputMachine");
}

void LiveInputMachine::initialize()
{

}
