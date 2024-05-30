#pragma once

#include <QGraphicsView>
#include <QWidget>

class SandboxView : public QGraphicsView
{
    Q_OBJECT
public:
    SandboxView(QWidget *parent = nullptr);

public: // const

public: // non-const

public: // pointers

public slots:
    void initialize(void) {;}
    void configure(void) {;}
    void setup(void) {;}
    void start(void) {;}

private slots:
};
