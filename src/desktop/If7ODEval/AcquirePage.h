#pragma once

#include <StackedMainPage.h>

class ImageFileDropWidget;
class ImageFileTreeWidget;
class ImageGalleryWidget;
class StackedMainWindow;

class EvalMainWindow;

class AcquirePage : public StackedMainPage
{
    Q_OBJECT
public:
    AcquirePage(EvalMainWindow *parent);

public:

public slots:
    virtual void initialize();
    virtual void configure();
    virtual void setup();

signals:

public: // const

public: // non-const

public: //


private:
    ImageFileDropWidget * mpDropWidget=nullptr;
    ImageFileTreeWidget * mpTreeWidget=nullptr;
    ImageGalleryWidget * mpGalleryWidget=nullptr;
};
