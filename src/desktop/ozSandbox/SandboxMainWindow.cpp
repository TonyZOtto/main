#include "SandboxMainWindow.h"

#include <QApplication>
#include <QGraphicsView>
#include <QGridLayout>
#include <QIcon>
#include <QLabel>
#include <QToolBar>
#include <QTimer>
#include <QWidget>

#include "SandboxApplication.h"
#include "SandboxEngine.h"
#include "SandboxScene.h"

SandboxMainWindow::SandboxMainWindow(SandboxApplication *parent)
    : mpApplication(parent)
{
    qInfo() << Q_FUNC_INFO;
    setObjectName("SandboxMainWindow:" + app()->applicationName());
}

SandboxMainWindow::~SandboxMainWindow()
{
    qInfo() << Q_FUNC_INFO;
    if (mpActions)   mpActions->deleteLater();
    if (mpScene)   mpScene->deleteLater();
}

void SandboxMainWindow::initialize()
{
    qInfo() << Q_FUNC_INFO;
    mpActions = new ActionManager(this);
    initializeActions();
    mpScene = new SandboxScene(this);
    scene()->initialize();
    emit initialized();
}

void SandboxMainWindow::actConnect()
{
    QAction * pQuitAct = action("Game/Quit");
    qInfo() << Q_FUNC_INFO << "Game/Quit"
            << Qt::hex << qptrdiff(pQuitAct) << app();
    Q_ASSERT(connect(pQuitAct, &QAction::triggered,
                     app(), &SandboxApplication::actQuit));
    emit actConnected();
}
void SandboxMainWindow::configure()
{
    qInfo() << Q_FUNC_INFO;
    // TODO QSettings from SandboxData
    scene()->configure();
    emit configured();
}


void SandboxMainWindow::setup()
{
    qInfo() << Q_FUNC_INFO;
    setupActions();

    scene()->set(SandboxScene::BackColor, Qt::green);
    scene()->setup();

    setCentralWidget(scene()->widget());
    show();
    emit setuped();
}


void SandboxMainWindow::start()
{
    qInfo() << Q_FUNC_INFO;
    scene()->start();
    emit started();
}

QAction *SandboxMainWindow::action(const Key &aKey)
{
    qInfo() << Q_FUNC_INFO << aKey
            << Qt::hex << qptrdiff(mpActions);  //actions()->contains(aKey);
    QAction * result = actions()->action(aKey);
    Q_CHECK_PTR(result);
    return result;
}

void SandboxMainWindow::initializeActions()
{
    qInfo() << Q_FUNC_INFO;
    actions()->add("Game/Flip", "&Flip");
    actions()->add("Game/Quit", "&Quit");
}

void SandboxMainWindow::setupActions()
{
    qInfo() << Q_FUNC_INFO;
    action("Game/Quit")->setEnabled(true);
}

void SandboxMainWindow::setupToolbar()
{
    mpMainToolBar = QMainWindow::addToolBar("Main");
    toolBar()->setObjectName("SandboxMainWindow:ToolBar:"
                                 + mpMainToolBar->windowTitle());
    toolBar()->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    toolBar()->setEnabled(true);
    toolBar()->setVisible(true);
    toolBar()->show();

}

