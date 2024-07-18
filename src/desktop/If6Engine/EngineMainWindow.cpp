#include "EngineMainWindow.h"

#include <QCoreApplication>
#include <QDockWidget>
#include <QGridLayout>
#include <QStackedLayout>
#include <QSlider>
#include <QWidget>

#include "EngineApplication.h"

EngineMainWindow::EngineMainWindow(EngineApplication *pApp)
    : QMainWindow(nullptr)
    , mpApplication(pApp)
{
    setObjectName("EngineMainWindow"
                  + QCoreApplication::applicationName());
}

EngineMainWindow::~EngineMainWindow() {}

void EngineMainWindow::initialize()
{
    mpMainWidget = new QWidget(this);
    mpMainStack = new QStackedLayout(this);
    mpLogPageGrid = new QGridLayout(this);
    mpGalleryPageGrid = new QGridLayout(this);
    mpSplashPage = new QWidget(this);
    mpLogPageWidget = new QWidget(this);
    mpGalleryPageWidget = new QWidget(this);
    mpLogDockWidget = new QDockWidget(this);
    mpLogSlider = new QSlider(this);
    mpGallerySlider = new QSlider(this);
    Q_ASSERT(mpMainWidget);
    Q_ASSERT(mpMainStack);
    Q_ASSERT(mpLogPageGrid);
    Q_ASSERT(mpGalleryPageGrid);
    Q_ASSERT(mpSplashPage);
    Q_ASSERT(mpLogPageWidget);
    Q_ASSERT(mpGalleryPageWidget);
    Q_ASSERT(mpLogDockWidget);
    Q_ASSERT(mpLogSlider);
    Q_ASSERT(mpGallerySlider);
    mEclipseLogoPixmap.load(":/image/logo/png/EclipseIRLogo.png");
    mIndiLogoPixmap.load(":/image/logo/png/INDI200.png");
    emit initialized();
}

void EngineMainWindow::setup()
{
    setWindowTitle("INDIface Six Engine");

    emit setuped();
}
