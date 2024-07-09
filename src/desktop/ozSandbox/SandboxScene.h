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
    explicit SandboxScene(QObject *parent = nullptr);
    ~SandboxScene();

public slots:
    void initialize(void);
    void configure(void) {;}
    void setup(void);
    void objconnect(void) {;}
    void start(void) {;}

signals:
    void initialized(void);
    void configured(void);
    void setuped(void);
    void objconnected(void);
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
    QGraphicsView * view();
    QWidget * widget();

private:

private:
    QGraphicsView * mpView=nullptr;
    QList<QGraphicsPixmapItem *> mPixmapItems;
    SCRect mViewRect;
};

inline SCRect SandboxScene::viewRect() const { return mViewRect; }
inline void SandboxScene::viewRect(const SCRect &aViewRect) { mViewRect = aViewRect; }
inline QGraphicsView *SandboxScene::view() { Q_CHECK_PTR(mpView); return mpView; }
