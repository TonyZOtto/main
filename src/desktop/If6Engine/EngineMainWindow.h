#pragma once

#include <QMainWindow>

#include <QPixmap>
class QDockWidget;
class QGridLayout;
class QStackedLayout;
class QSlider;
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

private:
    EngineApplication * mpApplication=nullptr;
    QWidget * mpMainWidget=nullptr;
    QStackedLayout * mpMainStack=nullptr;
    QGridLayout * mpLogPageGrid=nullptr;
    QGridLayout * mpGalleryPageGrid=nullptr;
    QWidget * mpSplashPage=nullptr;
    QWidget * mpLogPageWidget=nullptr;
    QWidget * mpGalleryPageWidget=nullptr;
    QDockWidget * mpLogDockWidget=nullptr;
    QSlider * mpLogSlider=nullptr;
    QSlider * mpGallerySlider=nullptr;
    QPixmap mEclipseLogoPixmap;
    QPixmap mIndiLogoPixmap;
};

inline EngineApplication *EngineMainWindow::application() { Q_CHECK_PTR(mpApplication); return mpApplication; }
