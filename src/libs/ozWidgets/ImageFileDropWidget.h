#pragma once
#include "ozWidgets.h"

#include <QWidget>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDropEvent>

class OZWIDGETS_EXPORT ImageFileDropWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageFileDropWidget(QWidget *parent = nullptr);

public slots:
    void setup();

signals:
    void setuped();

private:

};
