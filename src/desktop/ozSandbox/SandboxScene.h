#pragma once

#include <QGraphicsScene>

#include <QGraphicsPixmapItem>
#include <QList>

#include <Types.h>

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
        DisplayBase,
        $max
    };
    Q_ENUM(Layer)

public: // ctors
    explicit SandboxScene(QObject *parent = nullptr);

public slots:

signals:

public: // const

public: // non-const
    void set(const Layer aLayer, const QImage &aImage);
    void set(const Index aDisplayIndex, const QImage &aImage);

public: // pointers

private:
    QGraphicsPixmapItem *set(const Index aItemIndex, const QPixmap &aPixmap);

private:
    QList<QGraphicsPixmapItem *> mPixmapItems;

};
