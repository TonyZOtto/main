#pragma once

#include <QMainWindow>

class QAction;

class SandboxToolbar;
class SandboxWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QAction * mpQuitAction=nullptr;
    SandboxWidget * mpSandboxWidget=nullptr;
    SandboxToolbar * mpSandboxToolbar=nullptr;
};
