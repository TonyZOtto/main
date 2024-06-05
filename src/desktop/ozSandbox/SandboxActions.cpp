#include "SandboxActions.h"

#include <QAction>
#include <QApplication>
#include <QToolBar>

#include "SandboxMain.h"

SandboxActions::SandboxActions(SandboxMain *parent)
    : QObject(parent)
    , mpMainWindow(parent)
{
    setObjectName("SandboxActions:" + mpMainWindow->objectName());
}

void SandboxActions::initialize()
{
    mpQuitAction = new QAction("Quit", this);
    mpStopAction = new QAction("Stop", this);
    mpPauseAction = new QAction("Pause", this);
    mpResumeAction = new QAction("Resume", this);
    mpToolbar = new QToolBar("Main", main());
    emit initialized();
}

void SandboxActions::setup()
{
    mRunState = Paused;
    createIcons();
    Q_CHECK_PTR(mpQuitAction);
    Q_CHECK_PTR(mpStopAction);
    Q_CHECK_PTR(mpPauseAction);
    Q_CHECK_PTR(mpResumeAction);
    mpQuitAction->setIcon(mQuitIcon);
    mpStopAction->setIcon(mStopIcon);
    mpPauseAction->setIcon(mPauseIcon);
    mpResumeAction->setIcon(mResumeIcon);
    mpQuitAction->setShortcuts(QKeySequence::Quit);
    mpStopAction->setShortcut(QKeySequence("Alt+S"));
    mpPauseAction->setShortcut(QKeySequence("Alt+P"));
    mpResumeAction->setShortcut(QKeySequence("Alt+R"));
    Q_CHECK_PTR(mpToolbar);
    mpToolbar->addAction(mpQuitAction);
    mpToolbar->addAction(mpStopAction);
    mpToolbar->addAction(mpPauseAction);
    mpToolbar->addAction(mpResumeAction);
    main()->addToolBar(mpToolbar);
    mpToolbar->show();
    emit seted();
}

void SandboxActions::objconnect()
{
    Q_CHECK_PTR(mpQuitAction);
    connect(mpQuitAction, &QAction::triggered, this, &SandboxActions::quit);
    emit connected();
}

void SandboxActions::updateSetup()
{
    updateSetupPause();
    updateSetupRotate();
    updateSetupSides();
    updateSetupSizes();
}

void SandboxActions::quit()
{
    emit quiting();
    qApp->exit();
}

void SandboxActions::createIcons()
{
    mQuitIcon = QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit);
    mStopIcon = QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackStop);
    mPauseIcon = QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackPause);
    mResumeIcon = QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackStart);
}

void SandboxActions::updateSetupPause()
{
    switch (mRunState)
    {
    case Running:
        mpStopAction->setEnabled(true);
        mpPauseAction->setEnabled(true);
        mpResumeAction->setEnabled(false);
        break;
    case Paused:
        mpStopAction->setEnabled(true);
        mpPauseAction->setEnabled(false);
        mpResumeAction->setEnabled(true);
        break;
    case Stopped:
        mpStopAction->setEnabled(false);
        mpPauseAction->setEnabled(false);
        mpResumeAction->setEnabled(true);
        break;
    default:
        mpStopAction->setEnabled(false);
        mpPauseAction->setEnabled(false);
        mpResumeAction->setEnabled(false);
        break;
    }
}

void SandboxActions::updateSetupRotate()
{

}

void SandboxActions::updateSetupSides()
{

}

void SandboxActions::updateSetupSizes()
{

}
