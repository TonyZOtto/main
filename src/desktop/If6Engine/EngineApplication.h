#pragma once

#include <QApplication>

class EngineMainWindow;

class EngineApplication : public QApplication
{
    Q_OBJECT
public: // ctors
    EngineApplication(int &argc, char **argv);

public slots:
    void initialize();

signals:
    void initialized();

public: // const

public: // non-const
    void set(EngineMainWindow * pMW);

public: // pointers
    EngineMainWindow * mainWindow();

private:
    EngineMainWindow * mpMainWindow=nullptr;
};

inline void EngineApplication::set(EngineMainWindow *pMW) { Q_CHECK_PTR(pMW); mpMainWindow = pMW; }
inline EngineMainWindow *EngineApplication::mainWindow()  { Q_CHECK_PTR(mpMainWindow); return mpMainWindow; }
