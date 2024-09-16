#include "FacesPage.h"

#include <QGridLayout>

FacesPage::FacesPage(StackedMainWindow *parent)
    : StackedMainPage("Faces", parent)
{
    qInfo() << Q_FUNC_INFO;
    setObjectName("FacesPage");
}

void FacesPage::initialize()
{
    qInfo() << Q_FUNC_INFO;
    // TOOD anything?
}

void FacesPage::configure()
{
    qInfo() << Q_FUNC_INFO;
    // TOOD anything?
}

void FacesPage::setup()
{
    qInfo() << Q_FUNC_INFO;
    StackedMainPage::setup();
    // TOOD anything?

    setLayout(pageGridLayout());
}
