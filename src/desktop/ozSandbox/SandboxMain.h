#pragma once

#include <QMainWindow>

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

public: // const
    const QSize baseSize() const;
    Count numSides() const;
    Count frameCount() const;
    QPixmap showPixmap() const;
    QPixmap makePixmap() const;

public: // non-const
    Count & frameCount();

public: // pointers
    SandboxActions * actions();

public slots:
    void initialize(void);
    void configure(void);
    void setup(void);
    void objconnect(void);
    void start(void) {;}

private slots:

private:
    QSize mBaseSize;
    Count mNumSides=0; // 0=circle 3=triangle 4=square 5=pentagon, etc.
    Count mFrameCount=0;
    QPixmap mShowPixmap;
    QPixmap mMakePixmap;
    QLabel * mpMainLabel=nullptr;
    QWidget * mpCentralWidget=nullptr;
    QGridLayout * mpMainLayout=nullptr;
    SandboxActions * mpSandboxActions=nullptr;

};


inline const QSize SandboxMainWindow::baseSize() const
{
    return mBaseSize;
}

inline Count SandboxMainWindow::numSides() const
{
    return mNumSides;
}

inline Count SandboxMainWindow::frameCount() const
{
    return mFrameCount;
}

inline QPixmap SandboxMainWindow::showPixmap() const
{
    return mShowPixmap;
}

inline QPixmap SandboxMainWindow::makePixmap() const
{
    return mMakePixmap;
}

inline Count &SandboxMainWindow::frameCount()
{
    return mFrameCount;
}

inline SandboxActions *SandboxMainWindow::actions()
{
    Q_CHECK_PTR(mpSandboxActions); return mpSandboxActions;
}
