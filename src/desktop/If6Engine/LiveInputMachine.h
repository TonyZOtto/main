#pragma once

#include <StateMachine.h>

class LiveInputMachine : public StateMachine
{
    Q_OBJECT
public:
    explicit LiveInputMachine(QObject *parent = nullptr);
};
