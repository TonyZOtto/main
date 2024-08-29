#include "AcquirePage.h"

#include <ApplicationHelper.h>
#include <AppSettings.h>
#include <ImageFileDropWidget.h>
#include <ImageFileTreeWidget.h>
#include <ImageGalleryConfig.h>
#include <ImageGalleryWidget.h>

Q_GLOBAL_STATIC(ApplicationHelper, APPH)

#include "EvalMainWindow.h"

AcquirePage::AcquirePage(EvalMainWindow *parent)
    : StackedMainPage("Acquire", parent)
    , mpDropWidget(new ImageFileDropWidget(this))
    , mpTreeWidget(new ImageFileTreeWidget(this))
{
    setObjectName("AcquirePage");
}

void AcquirePage::setup()
{
    const ImageGalleryConfig cConfig(QQSize(128)); // TODO read settings
    const KeyMap cSettings = APPH->appSettings()->map("Acquire");
    const ImageGalleryConfig cIGConfig(cSettings.group("Gallery"));
    mpGalleryWidget = new ImageGalleryWidget(cConfig, this);

}
