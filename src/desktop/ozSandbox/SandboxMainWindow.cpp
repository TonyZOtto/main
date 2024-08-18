#include "SandboxMainWindow.h"

#include <QApplication>
#include <QGraphicsView>
#include <QGridLayout>
#include <QIcon>
#include <QLabel>
#include <QStyle>
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
//    if (mpActions)   mpActions->deleteLater();
    if (mpScene)   mpScene->deleteLater();
}

void SandboxMainWindow::initialize()
{
    qInfo() << Q_FUNC_INFO;
//    mpActions = new ActionManager(this);
    mpMainToolBar = createMainToolBar();

    mpScene = new SandboxScene(this);
    scene()->initialize();
    emit initialized();
}

void SandboxMainWindow::actConnect()
{
//    QAction * pQuitAct = action("Game/Quit");
//    qInfo() << Q_FUNC_INFO << "Game/Quit"
  //          << Qt::hex << qptrdiff(pQuitAct) << app();
    //Q_ASSERT(connect(pQuitAct, &QAction::triggered,
      //               app(), &SandboxApplication::actQuit));
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
    actConnect();

    addToolBar(Qt::TopToolBarArea, toolBar());
    toolBar()->show();
    update();

    scene()->set(SandboxScene::BackColor, Qt::green);
    scene()->setup();
    setMinimumSize(scene()->viewRect().size());
    setCentralWidget(scene()->widget());
    update();

    show();
    emit setuped();
}


void SandboxMainWindow::start()
{
    qInfo() << Q_FUNC_INFO;
    scene()->start();
    emit started();
}
#if 0
QAction *SandboxMainWindow::action(const Key &aKey)
{
    QAction * result = actions()->action(aKey);
    Q_ASSERT(result);
    return result;
}
#endif
void SandboxMainWindow::setupActions()
{
    qInfo() << Q_FUNC_INFO;
    //action("Game/Quit")->setEnabled(true);
}

QToolBar * SandboxMainWindow::createMainToolBar()
{
    QToolBar * result = new QToolBar("Main");
    Q_ASSERT(result);
    result->setObjectName("SandboxMainWindow:ToolBar");
//    actions()->add("Game/Flip", result->addAction(styleIcon("Flip"), "&Flip"));
  //  actions()->add("Game/Quit", result->addAction(styleIcon("Quit"), "&Quit"));
    result->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    result->setHidden(false);
    result->setEnabled(true);
    result->setVisible(true);
    result->show();
    return result;
}

QIcon SandboxMainWindow::styleIcon(const Key aKey) const
{
    QIcon result;
    QStyle * pStyle = QApplication::style();
    if ("Splash" == aKey())
        result = pStyle->standardIcon(QStyle::SP_DesktopIcon);
    else if ("Gallery" == aKey())
        result = pStyle->standardIcon(QStyle::SP_DirOpenIcon);
    else if ("Log" == aKey())
        result = pStyle->standardIcon(QStyle::SP_FileIcon);
    else if ("Quit" == aKey())
        result = pStyle->standardIcon(QStyle::SP_ArrowRight);
    return result;
}

/*
QToolBar *EngineMainWindow::createToolBar()
{
    QToolBar * result = addToolBar("Main");
    Q_ASSERT(result);
    result->addAction(styleIcon("Splash"), "&Splash");
    result->addAction(styleIcon("Gallery"), "&Gallery");
    result->addAction(styleIcon("Log"), "&Log");
    result->addAction(styleIcon("Quit"), "&Quit");
    result->setHidden(false);
    result->setVisible(true);
    result->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    result->show();
    return result;
}
*/
