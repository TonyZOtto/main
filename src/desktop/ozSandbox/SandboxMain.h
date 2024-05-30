#pragma once

#include <QMainWindow>

class QGraphicsPixmapItem;

#include <Types.h>

class SandboxActions;
class SandboxScene;
class SandboxView;

class SandboxMain : public QMainWindow
{
    Q_OBJECT

public:
    SandboxMain(QWidget *parent = nullptr);
    ~SandboxMain();

public: // const
    const QSize baseSize() const;

public: // non-const

public: // pointers
    SandboxActions * actions();

public slots:
    void initialize(void);
    void configure(void) {;}
    void setup(void);
    void start(void) {;}

private slots:

private:
    const QSize cmBaseSize;
    Count mSides=0; // 0=circle 3=triangle 4=square 5=pentagon, etc.
    Count mFrameCount=0;
    SandboxActions * mpSandboxActions=nullptr;
    SandboxScene * mpScene=nullptr;
    SandboxView * mpView=nullptr;
    QGraphicsPixmapItem * mpPixmapItem=nullptr;

};


inline const QSize SandboxMain::baseSize() const
{
    return cmBaseSize;
}

inline SandboxActions *SandboxMain::actions()
{
    Q_CHECK_PTR(mpSandboxActions); return mpSandboxActions;
}
