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
    mpToolBar = addToolBar("Main");
    Q_ASSERT(mpToolBar);
    mpToolBar->addAction("&Splash");
    mpToolBar->addAction("&Gallery");
    mpToolBar->addAction("&Log");
    mpToolBar->addAction("&Quit");
    mpToolBar->show();

    setCentralWidget(mpMainWidget);
    setupMainStack(mpMainWidget->size());
    mpMainWidget->setLayout(mpMainStack);
    emit setuped();
}

void EngineMainWindow::setupMainStack(const QQSize aMaxSize)
{
    mpSplashPage = setupSplash(aMaxSize);
    Q_ASSERT(mpMainStack);
    mpMainStack->addWidget(mpSplashPage);
    mpMainWidget->setLayout(mpMainStack);
}

QWidget * EngineMainWindow::setupSplash(const QQSize aMaxSize)
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
    tIndiPixmap = tIndiPixmap.scaledToWidth(tIndiSize.width());
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

QIcon EngineMainWindow::splashIcon(const QQSize aBaseSize) const
{
    QIcon result;
    QQSize cSize = aBaseSize.square();
    const int cWidth = cSize.width();
    const int cHeight = cSize.height();
    QPixmap tBasePixmap(cSize);
    QRect tBaseRect(QPoint(0,0), cSize);
    QPainterPath tBasePath;
    tBasePath.moveTo(6,  2);
    tBasePath.lineTo(cWidth - 6,  2);
    tBasePath.arcTo(cWidth - 10, 2, 4, 4, 90, -90);
    tBasePath.lineTo(cWidth - 6, cHeight - 6);
    tBasePath.arcTo(cWidth - 10, cHeight - 10, 4, 4, 0, -90);
    tBasePath.lineTo(6, cHeight - 6);
    tBasePath.arcTo(2, cHeight - 10, 4, 4, 270, -90);
    tBasePath.lineTo(2, 6);
    tBasePath.arcTo(2, 2, 4, 4, 180, -90);
    QBrush tTransparentBrush(Qt::transparent);
    QBrush tBaseBrush(Qt::darkGray);
    QPen tBlackPen(Qt::black);
    QPainter tBasePainter(&tBasePixmap);
    tBasePainter.fillRect(tBaseRect, tTransparentBrush);
    tBasePainter.setPen(tBlackPen);
    tBasePainter.setBrush(tBaseBrush);
    tBasePainter.drawPath(tBasePath);
    tBasePainter.end();
    result.addPixmap(tBasePixmap);
    return result;
}
