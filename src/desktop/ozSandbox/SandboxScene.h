#pragma once

#include <QGraphicsScene>

#include <QList>
class QColor;
class QImage;
class QGraphicsPixmapItem;
class QGraphicsView;
class QWidget;

#include <SCRect.h>
#include <Types.h>
class BasePhoto;

class SandboxMainWindow;

class SandboxScene : public QGraphicsScene
{
    Q_OBJECT
public: // types
    enum Layer
    {
        $null = 0,
        BackColor,
        BackImage,
        Frame,
        OldSubject,
        NewSubject,
        $max
    };
    Q_ENUM(Layer)

public: // ctors
    explicit SandboxScene(SandboxMainWindow *parent = nullptr);
    ~SandboxScene();

public slots:
    void initialize(void);
    void configure(void) {;}
    void setup(void);
    void start(void) {;}

signals:
    void initialized(void);
    void configured(void);
    void setuped(void);
    void started(void);

public: // const
    SCRect viewRect() const;

public: // non-const
    void viewRect(const SCRect &aViewRect);
    void set(const Layer aLayer, const QColor &aFillColor);
    void set(const Layer aLayer, const BasePhoto &aPhoto);
    void set(const Layer aLayer, const QImage &aImage);
    void set(const Layer aLayer, const QPixmap &aPixmap);

public: // pointers
    SandboxMainWindow * mainWindow();
    QGraphicsView * view();
    QWidget * widget();

private:

private:
    SandboxMainWindow * mpMainWindow=nullptr;
    QGraphicsView * mpView=nullptr;
    QList<QGraphicsPixmapItem *> mPixmapItems;
    SCRect mViewRect;
};

inline SCRect SandboxScene::viewRect() const { return mViewRect; }
inline void SandboxScene::viewRect(const SCRect &aViewRect) { mViewRect = aViewRect; }
inline SandboxMainWindow *SandboxScene::mainWindow() { Q_CHECK_PTR(mpMainWindow); return mpMainWindow; }
inline QGraphicsView *SandboxScene::view() { Q_CHECK_PTR(mpView); return mpView; }
