#pragma once

#include <StackedMainPage.h>

#include <KeyMap.h>

class ImageFileDropWidget;
class ImageFileListWidget;
class ImageFileTreeWidget;
class ImageGalleryWidget;
class StackedMainWindow;

class EvalMainWindow;

class AcquirePage : public StackedMainPage
{
    Q_OBJECT
public: // ctors
    AcquirePage(EvalMainWindow *parent);


public slots:

signals:

public: // const

public: // non-const
    virtual void initialize();
    virtual void configure();
    virtual void setup();

public: // pointers

private:
    ImageFileDropWidget * mpDropWidget=nullptr;
    ImageFileListWidget * mpListWidget=nullptr;
    ImageFileTreeWidget * mpTreeWidget=nullptr;
    ImageGalleryWidget * mpGalleryWidget=nullptr;
    KeyMap mConfiguration;
};
