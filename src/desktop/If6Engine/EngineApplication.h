#pragma once

#include <QApplication>

#include <VersionInfo.h>

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
//    void set(VersionInfo * pVI);
    void set(EngineMainWindow * pMW);

public: // pointers
//    VersionInfo * versionInfo();
    EngineMainWindow * mainWindow();

private:
//    VersionInfo * mpVersionInfo=nullptr;
    EngineMainWindow * mpMainWindow=nullptr;
};

//inline VersionInfo *EngineApplication::versionInfo() { Q_CHECK_PTR(mpVersionInfo); return mpVersionInfo; }
//inline void EngineApplication::set(VersionInfo *pVI) { mpVersionInfo = pVI; }
inline void EngineApplication::set(EngineMainWindow *pMW) { Q_CHECK_PTR(pMW); mpMainWindow = pMW; }
inline EngineMainWindow *EngineApplication::mainWindow()  { Q_CHECK_PTR(mpMainWindow); return mpMainWindow; }
