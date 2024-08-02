#pragma once

#include <StateMachine.h>

class StoredInputMachine : public StateMachine
{
    Q_OBJECT
public:
    explicit StoredInputMachine(QObject *parent = nullptr);

public slots:
    virtual void initialize();

signals:
    void initialized();
};
