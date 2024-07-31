#pragma once


#include <QObject>

#include <Key.h>

class StateMachine;

class MachineHelper : public QObject
{
    Q_OBJECT
public: // ctors
    explicit MachineHelper(StateMachine *parent = nullptr);

public slots:
    void addStates(const Key::List &aStateKeyList);

signals:

public: // const

public: // non-const

public: // pointers
    StateMachine * machine();

private:
    StateMachine * mpMachine=nullptr;
};

inline StateMachine *MachineHelper::machine() { Q_ASSERT(mpMachine); return mpMachine; }
