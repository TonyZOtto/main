#include "SandboxMainWindow.h"

#include <QApplication>
#include <QGraphicsView>
#include <QGridLayout>
#include <QIcon>
#include <QLabel>
#include <QTimer>
#include <QWidget>

#include "SandboxActions.h"
#include "SandboxEngine.h"
#include "SandboxScene.h"

SandboxMainWindow::SandboxMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setObjectName("ozSandbox:MainWindow");
}

SandboxMainWindow::~SandboxMainWindow()
{
    if (mpActions)   mpActions->deleteLater();
    if (mpScene)   mpScene->deleteLater();
    if (mpEngine)   mpEngine->deleteLater();
    if (mpMainLabel)        mpMainLabel->deleteLater();
    if (mpCentralWidget)    mpCentralWidget->deleteLater();
}

void SandboxMainWindow::initialize()
{
    mpActions = new SandboxActions(this);
    Q_CHECK_PTR(mpActions);
    mpActions->initialize();
    mpScene = new SandboxScene(this);
    Q_CHECK_PTR(mpScene);
    mpScene->initialize();
    mpEngine = new SandboxEngine(mpScene, this);
    Q_CHECK_PTR(mpEngine);
    mpEngine->initialize();
    mpMainLabel = new QLabel(this);
    Q_CHECK_PTR(mpMainLabel);
    mpCentralWidget = new QWidget(this);
    Q_CHECK_PTR(mpCentralWidget);
    mpMainLayout = new QGridLayout();
    Q_CHECK_PTR(mpMainLayout);
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
    // TODO QSettings
    Q_CHECK_PTR(mpScene);
    mBaseWidgetSize = QSize(512, 512);
    mpScene->viewRect(SCRect(mBaseWidgetSize));
    emit configured();
}


void SandboxMainWindow::setup()
{
    Q_CHECK_PTR(mpActions);
    Q_CHECK_PTR(mpScene);
    Q_CHECK_PTR(mpEngine);
    Q_CHECK_PTR(mpCentralWidget);
    Q_CHECK_PTR(mpMainLabel);

    mpActions->setup();
    mpScene->setup();
    mpEngine->setup();

//    mBackPixmap = QPixmap(mBaseWidgetSize);
  //  mBackPixmap.fill(Qt::blue); // TODO BackColor, BackImage
    QImage tBackImage(":/image/MM512A.jpg");
//    tBackImage.convertTo(QImage::Format_Grayscale8);
    mBackPixmap = QPixmap::fromImage(tBackImage).copy(SCRect(mBaseWidgetSize));
    mpCentralWidget->setLayout(mpMainLayout);
    setCentralWidget(mpScene->view()->viewport());
    show();
    emit setuped();
}

void SandboxMainWindow::objconnect()
{
    Q_CHECK_PTR(mpActions);
    mpActions->objconnect();

    emit objconnected();
}

void SandboxMainWindow::start()
{
    emit started();

}
