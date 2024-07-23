#pragma once

#include <QMainWindow>

#include <QPixmap>
class QDockWidget;
class QGridLayout;
class QStackedLayout;
class QSlider;
class QToolBar;
class QWidget;

#include <Key.h>
#include <QQSize.h>

class EngineApplication;

class EngineMainWindow : public QMainWindow
{
    Q_OBJECT

public: // types
    enum StackPage { Splash = 0, Gallery, Log, $max };

public: // ctors
    EngineMainWindow(EngineApplication *pApp = nullptr);
    ~EngineMainWindow();

public slots:
    void initialize();
    void setup();

    void actSplashPage();
    void actLogPage();
    void actGalleryPage();

signals:
    void initialized();
    void setuped();

public: // const

public: // non-const
    QWidget showPage(const StackPage aPage);

public: // pointers
    EngineApplication * application();

private:
    void setupMainStack(const QQSize aMaxSize);
    QToolBar * createToolBar();
    QWidget *createSplashPage(const QQSize aMaxSize);
    QIcon styleIcon(const Key aKey) const;

private:
    EngineApplication * mpApplication=nullptr;
    QWidget * mpMainWidget=nullptr;
    QStackedLayout * mpMainStack=nullptr;
    QToolBar * mpToolBar=nullptr;
    QGridLayout * mpLogPageGrid=nullptr;
    QGridLayout * mpGalleryPageGrid=nullptr;
    QWidget * mpSplashPage=nullptr;
    QWidget * mpGalleryPage=nullptr;
    QWidget * mpLogPage=nullptr;
    QDockWidget * mpLogDockWidget=nullptr;
    QSlider * mpLogSlider=nullptr;
    QSlider * mpGallerySlider=nullptr;
    QPixmap mEclipseLogoPixmap;
    QPixmap mIndiLogoPixmap;
};

inline EngineApplication *EngineMainWindow::application() { Q_ASSERT(mpApplication); return mpApplication; }
