#pragma once

#include <QObject>

#include <QIcon>
#include <QList>
class QAction;
class QLabel;
class QToolBar;

#include <Types.h>
#include <Angle.h>

class SandboxMain;

class SandboxActions : public QObject
{
    Q_OBJECT
public: // types
    enum RunState
    {
        $nullRunState = 0,
        Running,
        Paused,
        Stopped,
        $sizeRunState
    };
    Q_ENUM(RunState);

public: // ctors
    explicit SandboxActions(SandboxMain *parent = nullptr);


public: // const

public: // non-const

public: // pointers
    SandboxMain * main();

public slots:
    void initialize(void);
    void configure(void) {;}
    void setup(void);
    void objconnect(void);
    void start(void) {;}
    void updateSetup(void);
    void quit(void);

private slots:
    void createIcons();
    void createSystemIcons();
    void createPlaybackIcons();
    void updateSetupPause(void);
    void updateSetupRotate(void);
    void updateSetupSides(void);
    void updateSetupSizes(void);


signals:
    void initialized(void);
    void configured(void);
    void seted(void);
    void connected(void);
    void started(void);
    void quiting();
    void run();
    void running(const bool is);
    void stop();
    void pause();
    void resume();
    void paused(const bool is);
    void flip();
    void rotate(const Angle ang);

private:
    SandboxMain * mpMainWindow=nullptr;
    Angle mCurrentRotation;
    QList<Angle> mRotateAngles;
    QList<Count> mSideses;
    QList<QSize> mSizes;
    Index mRotateIndex=-1;
    Index mSidesIndex=-1;
    Index mSizesIndex=-1;
    RunState mRunState=$nullRunState;
    QAction * mpQuitAction=nullptr;
    QAction * mpStopAction=nullptr;
    QAction * mpPauseAction=nullptr;
    QAction * mpResumeAction=nullptr;
    QAction * mpFlipAction=nullptr;
    QAction * mpRotateAction=nullptr;
    QAction * mpRotateUpAction=nullptr;
    QLabel * mpRotateAngleLabel=nullptr;
    QAction * mpRotateDnAction=nullptr;
    QAction * mpSizeUpAction=nullptr;
    QLabel * mpSizeLabel=nullptr;
    QAction * mpSizeDnAction=nullptr;
    QAction * mpSidesAction=nullptr;
    QLabel * mpSidesLabel=nullptr;
    QToolBar * mpToolbar=nullptr;
    QIcon mQuitIcon;
    QIcon mStopIcon;
    QIcon mPauseIcon;
    QIcon mResumeIcon;
    QIcon mFlipIcon;
    QIcon mSizeUpIcon;
    QIcon mSizeDnIcon;
    QIcon mSidesesIcon;
    QIcon mRotateIcon;
    QIcon mRotateLeftIcon;
    QIcon mRotateRightIcon;

};

inline SandboxMain *SandboxActions::main() { Q_CHECK_PTR(mpMainWindow); return mpMainWindow; }
