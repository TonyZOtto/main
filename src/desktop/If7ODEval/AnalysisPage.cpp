#include "AnalysisPage.h"

#include <QGridLayout>

AnalysisPage::AnalysisPage(StackedMainWindow *parent)
    : StackedMainPage("Analysis", parent)
{
    qInfo() << Q_FUNC_INFO;
    setObjectName("AnalysisPage");
}

void AnalysisPage::initialize()
{
    qInfo() << Q_FUNC_INFO;
    // TOOD anything?
}

void AnalysisPage::configure()
{
    qInfo() << Q_FUNC_INFO;
    // TOOD anything?
}

void AnalysisPage::setup()
{
    qInfo() << Q_FUNC_INFO;
    StackedMainPage::setup();
// TOOD anything?
    setLayout(pageGridLayout());
}

void AnalysisPage::handleResize(const QQSize newSize)
{
    qInfo() << Q_FUNC_INFO  << objectName() << newSize;

}
