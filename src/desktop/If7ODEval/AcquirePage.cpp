#include "AcquirePage.h"

#include <ApplicationHelper.h>
#include <ImageFileDropWidget.h>
#include <ImageFileListWidget.h>
#include <ImageFileTreeWidget.h>
#include <ImageGalleryConfig.h>
#include <ImageGalleryWidget.h>
#include <Settings.h>

//Q_GLOBAL_STATIC(ApplicationHelper, APPH)

#include "EvalMainWindow.h"

AcquirePage::AcquirePage(EvalMainWindow *parent)
    : StackedMainPage("Acquire", parent)
    , mpDropWidget(new ImageFileDropWidget(this))
    , mpListWidget(new ImageFileListWidget(this))
    , mpTreeWidget(new ImageFileTreeWidget(this))
    , mpGalleryWidget(new ImageGalleryWidget(this))
{
    qInfo() << Q_FUNC_INFO;
    setObjectName("AcquirePage");
}

void AcquirePage::initialize()
{
    qInfo() << Q_FUNC_INFO;
    mpDropWidget->initialize();
    mpListWidget->initialize();
    mpTreeWidget->initialize();
    mpGalleryWidget->initialize();
}

void AcquirePage::configure()
{
    qInfo() << Q_FUNC_INFO;
    mpDropWidget->configure();
    mpListWidget->configure();
    mpTreeWidget->configure();
    mpGalleryWidget->configure();
}

void AcquirePage::setup()
{
    qInfo() << Q_FUNC_INFO;

    mpDropWidget->setup();
    mpListWidget->setup();
    mpTreeWidget->setup();
    mpGalleryWidget->setup();

    pageGridLayout()->addWidget(mpDropWidget, 0, 0);
    pageGridLayout()->addWidget(mpListWidget, 1, 0);
    pageGridLayout()->addWidget(mpTreeWidget, 2, 0);
    pageGridLayout()->addWidget(mpGalleryWidget, 0, 1, 3, 1);

    StackedMainPage::setup();
}
