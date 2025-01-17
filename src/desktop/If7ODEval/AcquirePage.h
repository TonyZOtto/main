#pragma once

#include <StackedMainPage.h>
#include <SupportedFormats.h>

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
    AcquirePage(StackedMainWindow *parent);


public slots:

signals:

public: // const

public: // non-const
    virtual void initialize() override final;
    virtual void configure() override final;
    virtual void setup() override final;

public: // pointers

protected slots:
    virtual void handleResize(const QQSize newSize) override final;


private:
    ImageFileDropWidget * mpDropWidget=nullptr;
    ImageFileListWidget * mpListWidget=nullptr;
    ImageFileTreeWidget * mpTreeWidget=nullptr;
    ImageGalleryWidget * mpGalleryWidget=nullptr;
    KeyMap mConfiguration;
    SupportedFormats mFormats;
};
