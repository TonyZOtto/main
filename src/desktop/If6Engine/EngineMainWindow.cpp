#include "EngineMainWindow.h"

#include <QBrush>
#include <QCoreApplication>
#include <QColor>
#include <QDockWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPainter>
#include <QPainterPath>
#include <QPen>
#include <QRect>
#include <QStackedLayout>
#include <QStyle>
#include <QSlider>
#include <QToolBar>
#include <QVBoxLayout>
#include <QWidget>

#include <QQPoint.h>


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
    mpGalleryPage = new QWidget(this);
    mpLogPage = new QWidget(this);
    mpLogDockWidget = new QDockWidget(this);
    mpLogSlider = new QSlider(this);
    mpGallerySlider = new QSlider(this);
    Q_ASSERT(mpMainWidget);
    Q_ASSERT(mpMainStack);
    Q_ASSERT(mpLogPageGrid);
    Q_ASSERT(mpGalleryPageGrid);
    Q_ASSERT(mpSplashPage);
    Q_ASSERT(mpLogPage);
    Q_ASSERT(mpGalleryPage);
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
    setFixedSize(QSize(800, 600));
    setupMainStack(size());
    mpMainWidget->setLayout(mpMainStack);
    setCentralWidget(mpMainWidget);
    mpToolBar = createToolBar();
    emit setuped();
}

void EngineMainWindow::setupMainStack(const QQSize aMaxSize)
{
    mpSplashPage = createSplashPage(aMaxSize);
    Q_ASSERT(mpMainStack);
    mpMainStack->addWidget(mpSplashPage);
    mpMainWidget->setLayout(mpMainStack);
    mpMainStack->setCurrentWidget(mpSplashPage);
}

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

QWidget * EngineMainWindow::createSplashPage(const QQSize aMaxSize)
{
    QWidget * result = new QWidget(this);
    Q_ASSERT(result);
    const QQSize cHalfSize(aMaxSize.width(), aMaxSize.height() / 2);
    QPixmap tEircPixmap(":/image/logo/png/EclipseIRLogo.png");
    QPixmap tIndiPixmap(":/image/logo/png/INDI200.png");
    QLabel * pEircLabel = new QLabel(result);
    QLabel * pIndiLabel = new QLabel(result);
    Q_ASSERT(pEircLabel);
    Q_ASSERT(pIndiLabel);
    QQSize tEircSize(tEircPixmap.size(), cHalfSize);
    QQSize tIndiSize(tIndiPixmap.size(), cHalfSize);
    pEircLabel->setPixmap(tEircPixmap.scaledToWidth(tEircSize.width()));
    pIndiLabel->setPixmap(tIndiPixmap.scaledToWidth(tIndiSize.width()));
    QVBoxLayout * pBoxLayout = new QVBoxLayout(result);
    Q_ASSERT(pBoxLayout);
    pBoxLayout->addWidget(pEircLabel);
    pBoxLayout->addWidget(pIndiLabel);
    result->setFixedSize(aMaxSize);
    result->setLayout(pBoxLayout);
    return result;
}

QIcon EngineMainWindow::styleIcon(const Key aKey) const
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
