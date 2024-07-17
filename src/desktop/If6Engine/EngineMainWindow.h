#pragma once

#include <QMainWindow>

class EngineMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    EngineMainWindow(QWidget *parent = nullptr);
    ~EngineMainWindow();

public slots:
    void initialize();

signals:
    void initialized();

public: // const

public: // non-const

public: // pointers

private:

};
