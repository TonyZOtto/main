#pragma once
#include "ozWidgets.h"

#include <QWidget>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QList>



#include <MatrixT.h>
#include <QQPoint.h>
#include <QQSize.h>
#include <ThumbImage.h>

#include "ImageGalleryConfig.h"
#include "ImageGalleryItem.h"

class OZWIDGETS_EXPORT ImageGalleryWidget : public QWidget
{
    Q_OBJECT
public: // ctors
    explicit ImageGalleryWidget(const ImageGalleryConfig &cfg,
                                QWidget *parent=nullptr);

public slots:
    void add(const ImageGalleryItem &item);
    void select(const QQPoint pt);
    void deselect();
    void deselect(const QQPoint pt);

signals:

public: // const
    Count count() const;

public: // non-const
    QQPoint append(const BaseImage &origImage);

private: // pointers
    QGraphicsScene * scene();
    QGraphicsView * view();

private slots:
    void setup();

private: // non-const

private:
    QGraphicsScene * mpScene=nullptr;
    QGraphicsView * mpView=nullptr;
    const ImageGalleryConfig cmConfig;
    QList<ImageGalleryItem> mItemList;
    MatrixT<ThumbImage> mThumbMatrix;
    QQPoint mSelectPoint;
    QQPoint::List mMultiSelectPoints;
    QQPoint mAppendPoint;

};
