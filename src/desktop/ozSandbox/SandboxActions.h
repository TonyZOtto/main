#pragma once

#include <QObject>

#include <QIcon>
class QAction;
class QToolBar;

#include <Types.h>
#include <types/Angle.h>

class SandboxMain;

class SandboxActions : public QObject
{
    Q_OBJECT
public:
    explicit SandboxActions(SandboxMain *parent = nullptr);


public: // const

public: // non-const

public: // pointers
    SandboxMain * main();

public slots:
    void initialize(void);
    void configure(void) {;}
    void setup(void);
    void start(void) {;}
    void quit(void) {;}

private slots:
    void createIcons();

signals:
    void initialized(void);
    void configured(void);
    void seted(void);
    void started(void);
    void quiting();
    void run();
    void stop();
    void running(const bool is);
    void pause();
    void resume();
    void paused(const bool is);
    void flip();
    void rotate(const Angle ang);

private:
    SandboxMain * mpMainWindow=nullptr;
    bool mIsRunning=false;
    bool mIsPaused=true;
    QAction * mpQuitAction=nullptr;
    QAction * mpPauseAction=nullptr;
    QAction * mpStopAction=nullptr;
    QAction * mpFlipAction=nullptr;
    QAction * mpRotateAction=nullptr;
    QAction * mpSizeUpAction=nullptr;
    QAction * mpSizeDnAction=nullptr;
    QAction * mpSidesAction=nullptr;
    QToolBar * mpToolbar=nullptr;
    QIcon mQuitIcon;
    QIcon mPauseIcon;
    QIcon mFlipIcon;
};

inline SandboxMain *SandboxActions::main() { Q_CHECK_PTR(mpMainWindow); return mpMainWindow; }
