#include "SandboxActions.h"

#include <QAction>
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
    Q_CHECK_PTR(mpQuitAction);
    mpQuitAction->setIcon(mQuitIcon);
    mpQuitAction->setShortcuts(QKeySequence::Quit);

    Q_CHECK_PTR(mpToolbar);
    mpToolbar->addAction(mpQuitAction);
    main()->addToolBar(mpToolbar);
    mpToolbar->show();
}

void SandboxActions::createIcons()
{
    mQuitIcon = QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit);
}
