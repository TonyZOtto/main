#pragma once

#include <StateMachine.h>

class LiveInputMachine;
class StoredInputMachine;

class InputModuleMachine : public StateMachine
{
    Q_OBJECT
public: // ctors
    explicit InputModuleMachine(QObject *parent = nullptr);

public slots:
    void initialize();

signals:
    void initialized();

public: // const

public: // non-const

public: // pointers
    void set(LiveInputMachine * pLive);
    void set(StoredInputMachine * pStored);

private slots:

private:

private:
    LiveInputMachine * mpLiveMachine=nullptr;
    StoredInputMachine * mpStoredMachine=nullptr;

};

inline void InputModuleMachine::set(LiveInputMachine *pLive) { Q_ASSERT(pLive); mpLiveMachine = pLive; }
inline void InputModuleMachine::set(StoredInputMachine *pStored) { Q_ASSERT(pStored); mpStoredMachine = pStored; }
