#pragma once

#include <QMainWindow>

#include <QPixmap>
#include <QSize>
class QGridLayout;
class QLabel;
class QWidget;

#include <Types.h>

class SandboxActions;

class SandboxMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    SandboxMainWindow(QWidget *parent = nullptr);
    ~SandboxMainWindow();

public slots:
    void initialize(void);
    void configure(void);
    void setup(void);
    void objconnect(void);
    void start(void);

signals:
    void initialized(void);
    void configured(void);
    void setuped(void);
    void objconnected(void);
    void started(void);


public: // const
    const QSize baseWidgetSize() const;

public: // non-const
    Count & frameCount();

public: // pointers
    SandboxActions * actions();

private slots:

private:
    QSize mBaseWidgetSize;
    QLabel * mpMainLabel=nullptr;
    QWidget * mpCentralWidget=nullptr;
    QGridLayout * mpMainLayout=nullptr;
    SandboxActions * mpSandboxActions=nullptr;
    QPixmap mBackPixmap;
};

inline const QSize SandboxMainWindow::baseWidgetSize() const { return mBaseWidgetSize; }
inline SandboxActions *SandboxMainWindow::actions() { Q_CHECK_PTR(mpSandboxActions); return mpSandboxActions; }
