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
    setObjectName("EngineMainWindow:"
                  + QCoreApplication::applicationName());
}

EngineMainWindow::~EngineMainWindow()
{
}

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
    mpMainWidget->setObjectName("MainWidget:EngineMainWindow");
    Q_ASSERT(mpMainStack);
    mpMainStack->setObjectName("MainStack:EngineMainWindow");
    Q_ASSERT(mpLogPageGrid);
    mpLogPageGrid->setObjectName("LogPageGrid:QGridLayout:EngineMainWindow");
    Q_ASSERT(mpGalleryPageGrid);
    mpGalleryPageGrid->setObjectName("GalleryPageGrid:QGridLayout:EngineMainWindow");
    Q_ASSERT(mpSplashPage);
    mpLogPage->setObjectName("SplashPage:EngineMainWindow");
    Q_ASSERT(mpLogPage);
    mpLogPage->setObjectName("LogPage:EngineMainWindow");
    Q_ASSERT(mpGalleryPage);
    mpLogPage->setObjectName("GalleryPage:EngineMainWindow");
    Q_ASSERT(mpLogDockWidget);
    mpLogPage->setObjectName("GalleryPage:EngineMainWindow");
    Q_ASSERT(mpLogSlider);
    mpLogSlider->setObjectName("LogSlider:EngineMainWindow");
    Q_ASSERT(mpGallerySlider);
    mpGallerySlider->setObjectName("GallerySlider:EngineMainWindow");
    mEclipseLogoPixmap.load(":/image/logo/png/EclipseIRLogo.png");
    mIndiLogoPixmap.load(":/image/logo/png/INDI200.png");
    emit initialized();
}

void EngineMainWindow::setup()
{
    setWindowTitle("INDIface Six Engine");
    setFixedSize(QSize(800, 600));
    setupMainStack(size());
    Q_ASSERT(mpMainWidget);
    setCentralWidget(mpMainWidget);
    mpToolBar = createToolBar();
    show();
    emit setuped();
}

void EngineMainWindow::actSplashPage()
{
    Q_ASSERT(mpMainStack);
    Q_ASSERT(mpSplashPage);
    mpMainStack->setCurrentWidget(mpSplashPage);
}

void EngineMainWindow::actLogPage()
{
    Q_ASSERT(mpMainStack);
    Q_ASSERT(mpLogPage);
    mpMainStack->setCurrentWidget(mpLogPage);
}

void EngineMainWindow::actGalleryPage()
{
    Q_ASSERT(mpMainStack);
    Q_ASSERT(mpGalleryPage);
    mpMainStack->setCurrentWidget(mpGalleryPage);
}

void EngineMainWindow::setupMainStack(const QQSize aMaxSize)
{
    mpSplashPage = createSplashPage(aMaxSize);
    Q_ASSERT(mpSplashPage);
    Q_ASSERT(mpMainStack);
    mpMainStack->addWidget(mpSplashPage);
    mpMainWidget->setLayout(mpMainStack);
    mpMainStack->setCurrentWidget(mpSplashPage);
}

QToolBar *EngineMainWindow::createToolBar()
{
    QToolBar * result = addToolBar("Main");
    Q_ASSERT(result);

    QAction * pSplashAction = result->addAction(styleIcon("Splash"), "&Splash");
    QAction * pGalleryAction = result->addAction(styleIcon("Gallery"), "&Gallery");
    QAction * pLogAction = result->addAction(styleIcon("Log"), "&Log");
    result->addAction(styleIcon("Quit"), "&Quit",
        application(), &EngineApplication::actQuit);
    Q_ASSERT(pSplashAction);
    Q_ASSERT(pGalleryAction);
    Q_ASSERT(pLogAction);
    connect(pSplashAction, &QAction::triggered,
            this, &EngineMainWindow::actSplashPage);
    connect(pGalleryAction, &QAction::triggered,
            this, &EngineMainWindow::actGalleryPage);
    connect(pLogAction, &QAction::triggered,
            this, &EngineMainWindow::actLogPage);
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
    pEircLabel->setObjectName("createSplashPage():EircLabel");
    pIndiLabel->setObjectName("createSplashPage():IndiLabel");
    QQSize tEircSize(tEircPixmap.size(), cHalfSize);
    QQSize tIndiSize(tIndiPixmap.size(), cHalfSize);
    pEircLabel->setPixmap(tEircPixmap.scaledToWidth(tEircSize.width()));
    pIndiLabel->setPixmap(tIndiPixmap.scaledToWidth(tIndiSize.width()));
    QVBoxLayout * pBoxLayout = new QVBoxLayout(result);
    Q_ASSERT(pBoxLayout);
    pIndiLabel->setObjectName("createSplashPage():BoxLayout");
    pBoxLayout->addWidget(pEircLabel);
    pBoxLayout->addWidget(pIndiLabel);
    result->setFixedSize(aMaxSize);
    result->setLayout(pBoxLayout);
    return result;
}

QIcon EngineMainWindow::styleIcon(const Key aKey) const
{
    QIcon result;
#if 0
#else
    QStyle * pStyle = QApplication::style();
    Q_ASSERT(pStyle);
    pStyle->setObjectName("styleIcon():Style");
    if ("Splash" == aKey())
        result = pStyle->standardIcon(QStyle::SP_DesktopIcon);
    else if ("Gallery" == aKey())
        result = pStyle->standardIcon(QStyle::SP_DirOpenIcon);
    else if ("Log" == aKey())
        result = pStyle->standardIcon(QStyle::SP_FileIcon);
    else if ("Quit" == aKey())
        result = pStyle->standardIcon(QStyle::SP_ArrowRight);
    //pStyle->deleteLater();
#endif
    return result;
}
