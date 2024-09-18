#pragma once
#include "ozWidgets.h"

#include <QWidget>

#include <QGraphicsView>
#include <QGraphicsScene>
class QDropEvent;
class QDragEnterEvent;

class SupportedFormats;

class OZWIDGETS_EXPORT ImageFileDropWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageFileDropWidget(QWidget *parent = nullptr);

public slots:
    void initialize();
    void configure();
    void setup();

signals:
    void initialized();
    void configured();
    void setuped();

    void dragEntered(QDragEnterEvent *e);
    void dropStarted(QDropEvent *e);
    void dropFile(const QFileInfo &fi);

public: // pointers
    SupportedFormats * readFormats();

private:
    virtual void dragEnterEvent(QDragEnterEvent *e) override final;
    virtual void dropEvent(QDropEvent *e) override final;


private:
    SupportedFormats * mpReadFormats=nullptr;
};
