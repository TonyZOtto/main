#include "AcquirePage.h"

#include <ApplicationHelper.h>
#include <ImageFileDropWidget.h>
#include <ImageFileListWidget.h>
#include <ImageFileTreeWidget.h>
#include <ImageGalleryConfig.h>
#include <ImageGalleryWidget.h>
#include <Settings.h>

Q_GLOBAL_STATIC(ApplicationHelper, APPH)

#include "EvalMainWindow.h"

AcquirePage::AcquirePage(EvalMainWindow *parent)
    : StackedMainPage("Acquire", parent)
    , mpDropWidget(new ImageFileDropWidget(this))
    , mpListWidget(new ImageFileListWidget(this))
    , mpTreeWidget(new ImageFileTreeWidget(this))
    , mpGalleryWidget(new ImageGalleryWidget(this))
{
    setObjectName("AcquirePage");
}

void AcquirePage::initialize()
{

}

void AcquirePage::configure()
{
    const ImageGalleryConfig cGalleryConfig(APPH->settings()
                                    ->map("Acquire/Gallery"));
    mpGalleryWidget->configure(cGalleryConfig);
}

void AcquirePage::setup()
{

    mpDropWidget->setup();

    pageGridLayout()->addWidget(mpDropWidget, 0, 0);
    pageGridLayout()->addWidget(mpListWidget, 1, 0);
    pageGridLayout()->addWidget(mpTreeWidget, 2, 0);
    pageGridLayout()->addWidget(mpGalleryWidget, 0, 1, 3, 1);

    StackedMainPage::setup();
}
