#pragma once

#include <StateMachine.h>

class InputModuleMachine : public StateMachine
{
    Q_OBJECT
public:
    explicit InputModuleMachine(QObject *parent = nullptr);
};
