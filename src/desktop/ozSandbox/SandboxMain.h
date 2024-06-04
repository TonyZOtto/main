#pragma once

#include <QMainWindow>

#include <QSize>
class QGridLayout;
class QLabel;
class QWidget;

#include <Types.h>

class SandboxActions;

class SandboxMain : public QMainWindow
{
    Q_OBJECT

public:
    SandboxMain(QWidget *parent = nullptr);
    ~SandboxMain();

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


inline const QSize SandboxMain::baseSize() const
{
    return mBaseSize;
}

inline Count SandboxMain::numSides() const
{
    return mNumSides;
}

inline Count SandboxMain::frameCount() const
{
    return mFrameCount;
}

inline QPixmap SandboxMain::showPixmap() const
{
    return mShowPixmap;
}

inline QPixmap SandboxMain::makePixmap() const
{
    return mMakePixmap;
}

inline Count &SandboxMain::frameCount()
{
    return mFrameCount;
}

inline SandboxActions *SandboxMain::actions()
{
    Q_CHECK_PTR(mpSandboxActions); return mpSandboxActions;
}
