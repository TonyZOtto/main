#pragma once

#include <QMainWindow>

#include <QPixmap>
class QDockWidget;
class QGridLayout;
class QStackedLayout;
class QSlider;
class QToolBar;
class QWidget;

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

signals:
    void initialized();
    void setuped();

public: // const
    QWidget splashPageWidget(const QQSize aMaxSize) const;

public: // non-const
    QWidget showPage(const StackPage aPage);

public: // pointers
    EngineApplication * application();

private:
    void setupMainStack(const QQSize aMaxSize);
    QWidget *setupSplash(const QQSize aMaxSize);
    QIcon splashIcon(const QQSize aBaseSize=QQSize(64)) const;

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

inline EngineApplication *EngineMainWindow::application() { Q_CHECK_PTR(mpApplication); return mpApplication; }
