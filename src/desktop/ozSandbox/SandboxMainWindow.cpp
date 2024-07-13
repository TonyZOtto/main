#include "SandboxMainWindow.h"

#include <QApplication>
#include <QGraphicsView>
#include <QGridLayout>
#include <QIcon>
#include <QLabel>
#include <QTimer>
#include <QWidget>

#include "SandboxActions.h"
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
    mpActions = new SandboxActions(this);
    actions()->initialize();
    mpScene = new SandboxScene(this);
    scene()->initialize();

    connect(this, &SandboxMainWindow::initialized,
            this, &SandboxMainWindow::configure);
    connect(this, &SandboxMainWindow::configured,
            this, &SandboxMainWindow::setup);
    connect(this, &SandboxMainWindow::setuped,
            this, &SandboxMainWindow::objconnect);
    connect(this, &SandboxMainWindow::objconnected,
            this, &SandboxMainWindow::start);

    emit initialized();
}

void SandboxMainWindow::configure()
{
    qInfo() << Q_FUNC_INFO;
    // TODO QSettings from SandboxData
    actions()->configure();
    scene()->configure();

    emit configured();
}

void SandboxMainWindow::setup()
{
    qInfo() << Q_FUNC_INFO;
    actions()->setup();

    scene()->set(SandboxScene::BackColor, Qt::green);
    setFixedSize(scene()->viewRect().size());
    setCentralWidget(scene()->widget());

    scene()->setup();
    show();
    emit setuped();
}

void SandboxMainWindow::objconnect()
{
    qInfo() << Q_FUNC_INFO;
    actions()->objconnect();
    scene()->objconnect();

    emit objconnected();
}

void SandboxMainWindow::start()
{
    qInfo() << Q_FUNC_INFO;
    actions()->start();
    scene()->start();

    emit started();
}
