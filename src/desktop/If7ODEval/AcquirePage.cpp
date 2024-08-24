#include "AcquirePage.h"

#include <ImageFileDropWidget.h>
#include <ImageFileTreeWidget.h>
#include <ImageGalleryWidget.h>

#include "EvalMainWindow.h"

AcquirePage::AcquirePage(EvalMainWindow *parent)
    : StackedMainPage("Acquire", parent)
    , mpDropWidget(new ImageFileDropWidget(this))
    , mpTreeWidget(new ImageFileTreeWidget(this))
    , mpGalleryWidget(new ImageGalleryWidget(this))
{
    setObjectName("AcquirePage");
}

void AcquirePage::setup()
{

}
