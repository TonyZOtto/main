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
    mpToolbar = new QToolBar("Main", main());
}

void SandboxActions::setup()
{
    createIcons();
    Q_CHECK_PTR(mpQuitAction);
    mpQuitAction->setIcon(mQuitIcon);
    mpQuitAction->setShortcuts(QKeySequence::Quit);
    Q_CHECK_PTR(mpToolbar);
    mpToolbar->addAction(mpQuitAction);
    main()->addToolBar(mpToolbar);
    mpToolbar->show();
    emit seted();
}

void SandboxActions::objconnect()
{
    Q_CHECK_PTR(mpQuitAction);
    connect(mpQuitAction, &QAction::triggered, this, &SandboxActions::quit);

}

void SandboxActions::quit()
{
    emit quiting();
    qApp->exit();
}

void SandboxActions::createIcons()
{
    mQuitIcon = QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit);
}
