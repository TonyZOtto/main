#include "FramesPage.h"

#include <QGridLayout>

FramesPage::FramesPage(StackedMainWindow *parent)
    : StackedMainPage("Frames", parent)
{
    qInfo() << Q_FUNC_INFO;
    setObjectName("FramesPage");
}


void FramesPage::initialize()
{
    qInfo() << Q_FUNC_INFO;
    // TOOD anything?
}

void FramesPage::configure()
{
    qInfo() << Q_FUNC_INFO;
    // TOOD anything?
}

void FramesPage::setup()
{
    qInfo() << Q_FUNC_INFO;
    StackedMainPage::setup();
    // TOOD anything?

    setLayout(pageGridLayout());
}
