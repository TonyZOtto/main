#pragma once
#include "ozWidgets.h"

#include <QWidget>

class OZWIDGETS_EXPORT ImageFileTreeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageFileTreeWidget(QWidget *parent = nullptr);


public slots:
    void initialize();
    void configure();
    void setup();

signals:
    void initialized();
    void configured();
    void setuped();

};
