#include "SandboxMain.h"

#include <QApplication>
#include <QGridLayout>
#include <QIcon>
#include <QLabel>
#include <QWidget>

#include "SandboxActions.h"

SandboxMain::SandboxMain(QWidget *parent)
    : QMainWindow(parent)
{
    setObjectName("ozSandbox:MainWindow");
}

SandboxMain::~SandboxMain()
{
    if (mpSandboxActions)   mpSandboxActions->deleteLater();
    if (mpMainLabel)       mpMainLabel->deleteLater();
    if (mpCentralWidget)    mpCentralWidget->deleteLater();
}

void SandboxMain::initialize()
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
}

void SandboxMain::configure()
{
    // TODO QSettings
    mBaseSize = QSize(512, 512);
    mNumSides = 4;
}


void SandboxMain::setup()
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
}

void SandboxMain::objconnect()
{
    Q_CHECK_PTR(mpSandboxActions);
    mpSandboxActions->objconnect();

}
