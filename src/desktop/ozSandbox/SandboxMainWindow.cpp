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
    setObjectName("SandboxMainWindow:" + app()->applicationName());
}

SandboxMainWindow::~SandboxMainWindow()
{
    if (mpActions)   mpActions->deleteLater();
    if (mpScene)   mpScene->deleteLater();
}

void SandboxMainWindow::initialize()
{
    mpActions = new SandboxActions(this);
    Q_CHECK_PTR(mpActions);
    mpActions->initialize();
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
    // TODO QSettings from SandboxData
    Q_CHECK_PTR(mpActions);
    mpActions->configure();
    scene()->configure();

    emit configured();
}

void SandboxMainWindow::setup()
{
    Q_CHECK_PTR(mpActions);
    mpActions->setup();
    scene()->setup();

    scene()->set(SandboxScene::BackColor, Qt::blue);
    QImage tBackImage(":/image/MM512A.jpg");
    tBackImage.convertTo(QImage::Format_Grayscale8);
    scene()->set(SandboxScene::BackImage,
        tBackImage);
    setFixedSize(scene()->viewRect().size());
    setCentralWidget(scene()->widget());
    show();
    emit setuped();
}

void SandboxMainWindow::objconnect()
{
    Q_CHECK_PTR(mpActions);
    mpActions->objconnect();
    scene()->objconnect();

    emit objconnected();
}

void SandboxMainWindow::start()
{
    Q_CHECK_PTR(mpActions);
    mpActions->start();
    scene()->start();

    emit started();
}
