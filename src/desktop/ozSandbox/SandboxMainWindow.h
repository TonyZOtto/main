#pragma once

#include <QMainWindow>

#include <QPixmap>
#include <QSize>
class QGridLayout;
class QLabel;
class QWidget;

#include <Types.h>
class CommandLine;

class SandboxActions;
class SandboxApplication;
class SandboxScene;

class SandboxMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    SandboxMainWindow(SandboxApplication *parent = nullptr);
    ~SandboxMainWindow();

public slots:
    void initialize(void);
    void configure(void);
    void setup(void);
    void start(void);

signals:
    void initialized(void);
    void configured(void);
    void setuped(void);
    void started(void);


public: // const
    const QSize baseWidgetSize() const;

public: // non-const
    Count & frameCount();

public: // pointers
    SandboxApplication * app();
    SandboxActions * actions();
    SandboxScene * scene();

private slots:

private:
    SandboxApplication * mpApplication=nullptr;
    SandboxActions * mpActions=nullptr;
    SandboxScene * mpScene=nullptr;
};

inline SandboxApplication *SandboxMainWindow::app() { Q_CHECK_PTR(mpApplication); return mpApplication; }
inline SandboxActions *SandboxMainWindow::actions() { Q_CHECK_PTR(mpActions); return mpActions; }
inline SandboxScene *SandboxMainWindow::scene() {  Q_CHECK_PTR(mpScene); return mpScene; }
