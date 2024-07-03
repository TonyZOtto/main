#include "SandboxMain.h"

#include <QApplication>
#include <QGridLayout>
#include <QIcon>
#include <QLabel>
#include <QTimer>
#include <QWidget>

#include "SandboxActions.h"

SandboxMainWindow::SandboxMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setObjectName("ozSandbox:MainWindow");
}

SandboxMainWindow::~SandboxMainWindow()
{
    if (mpSandboxActions)   mpSandboxActions->deleteLater();
    if (mpMainLabel)        mpMainLabel->deleteLater();
    if (mpCentralWidget)    mpCentralWidget->deleteLater();
}

void SandboxMainWindow::initialize()
{
    mpSandboxActions = new SandboxActions(this);
    Q_CHECK_PTR(mpSandboxActions);
    mpSandboxActions->initialize();
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
    mBaseSize = QSize(512, 512);
    mNumSides = 4;
    emit configured();
}


void SandboxMainWindow::setup()
{
    Q_CHECK_PTR(mpSandboxActions);
    Q_CHECK_PTR(mpCentralWidget);
    Q_CHECK_PTR(mpMainLabel);
    mFrameCount = 0;
    mShowPixmap = QPixmap(baseSize());
    mMakePixmap = QPixmap(showPixmap().size());
    mShowPixmap.fill(Qt::blue);
    mMakePixmap.fill(Qt::red);

    mpSandboxActions->setup();

    mpMainLabel->setFixedSize(showPixmap().size());
    mpMainLabel->setBaseSize(size());
    mpMainLabel->setPixmap(showPixmap());
    mpMainLayout->addWidget(mpMainLabel);
    mpCentralWidget->setLayout(mpMainLayout);
    setCentralWidget(mpCentralWidget);
    show();
    emit setuped();
}

void SandboxMainWindow::objconnect()
{
    Q_CHECK_PTR(mpSandboxActions);
    mpSandboxActions->objconnect();

    emit objconnected();
}

void SandboxMainWindow::start()
{
    emit started();

}
