#pragma once

#include <StateMachine.h>

class StoredInputMachine : public StateMachine
{
    Q_OBJECT
public:
    explicit StoredInputMachine(QObject *parent = nullptr);
};
