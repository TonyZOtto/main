#pragma once

#include <QGraphicsScene>

#include <QGraphicsPixmapItem>
#include <QPixmap>

class SandboxMain;

class SandboxScene : public QGraphicsScene
{
    Q_OBJECT
public:
    SandboxScene(SandboxMain *parent = nullptr);


public: // const
    QPixmap onPixmap() const;
    QPixmap offPixmap() const;

public: // non-const
    void onPixmap(const QPixmap pxm);
    void offPixmap(const QPixmap pxm);

public: // pointers
    SandboxMain * main();

public slots:
    void initialize();
    void configure() {;}
    void setup() {;}
    void start() {;}
    void onscreen();

private slots:

private:
    SandboxMain * mpMainWindow=nullptr;
    QGraphicsPixmapItem * mpPixmapItem=nullptr;
    QPixmap mOnPixmap;
    QPixmap mOffPixmap;
};

inline SandboxMain *SandboxScene::main() { Q_CHECK_PTR(mpMainWindow); return mpMainWindow; }
inline QPixmap SandboxScene::onPixmap() const { return mOnPixmap; }
inline QPixmap SandboxScene::offPixmap() const { return mOffPixmap; }
inline void SandboxScene::onPixmap(const QPixmap pxm) { mOnPixmap = pxm; }
inline void SandboxScene::offPixmap(const QPixmap pxm) { mOffPixmap = pxm; }
