#include "EvalMainWindow.h"

#include <QScreen>

#include <ApplicationHelper.h>
#include <Debug.h>
#include <QQSize.h>
#include <Settings.h>
#include <Value.h>
#include <StackedMainPage.h>
#include <WidgetApplication.h>

#include "AcquirePage.h"
#include "AnalysisPage.h"
#include "FacesPage.h"
#include "FramesPage.h"
#include "LogPage.h"
#include "SplashPage.h"

EvalMainWindow::EvalMainWindow(WidgetApplication *wapp)
    : StackedMainWindow(wapp)
{
    qInfo() << Q_FUNC_INFO;
    setObjectName("MainWindow:" + wapp->applicationName());
    addPage(new SplashPage(this));
    addPage(new AcquirePage(this));
    addPage(new FramesPage(this));
    addPage(new FacesPage(this));
    addPage(new AnalysisPage(this));
    addPage(new LogPage(this));
}

EvalMainWindow::~EvalMainWindow() {;}

void EvalMainWindow::initialize()
{
    qInfo() << Q_FUNC_INFO;
    StackedMainWindow::initialize();
    emit initialized();
}

void EvalMainWindow::configure()
{
    qInfo() << Q_FUNC_INFO;
    StackedMainWindow::configure();
    emit configured();
}

void EvalMainWindow::setup()
{
    qInfo() << Q_FUNC_INFO;
    StackedMainWindow::setup();
    setCurrent(0);
    update();
    emit setuped();
}

