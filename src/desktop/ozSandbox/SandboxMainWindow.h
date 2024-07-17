#pragma once

#include <QMainWindow>

#include <QPixmap>
#include <QSize>
class QToolBar;
class QWidget;

#include <ActionManager.h>
#include <Types.h>
class CommandLine;

class SandboxApplication;
class SandboxScene;

class SandboxMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    SandboxMainWindow(SandboxApplication *parent = nullptr);
    ~SandboxMainWindow();

public slots:
    void initialize();
    void configure();
    void actConnect();
    void setup();
    void start();

signals:
    void initialized();
    void actConnected();
    void configured();
    void setuped();
    void started();


public: // const

public: // non-const
    Count & frameCount();

public: // pointers
    SandboxApplication * app();
    ActionManager * actions();
    QAction * action(const Key &aKey);
    SandboxScene * scene();

private slots:
    void initializeActions();
    void setupActions();

private:
    SandboxApplication * mpApplication=nullptr;
    ActionManager * mpActions=nullptr;
    SandboxScene * mpScene=nullptr;
    QToolBar * mpMainToolBar=nullptr;
};

inline SandboxApplication *SandboxMainWindow::app() { Q_CHECK_PTR(mpApplication); return mpApplication; }
inline ActionManager *SandboxMainWindow::actions() { Q_CHECK_PTR(mpActions); return mpActions; }
inline SandboxScene *SandboxMainWindow::scene() {  Q_CHECK_PTR(mpScene); return mpScene; }
