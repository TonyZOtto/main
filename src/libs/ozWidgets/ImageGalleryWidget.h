#pragma once
#include "ozWidgets.h"

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>



#include <MatrixT.h>
#include <QQPoint.h>
#include <QQSize.h>
#include <ThumbImage.h>

#include "ImageGalleryConfig.h"
#include "ImageGalleryItem.h"

class OZWIDGETS_EXPORT ImageGalleryWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageGalleryWidget(QWidget *parent=nullptr);

public slots:
    void configure(const ImageGalleryConfig &cfg);
    void add(const ImageGalleryItem &item);
    QQPoint append(const ThumbImage aThumb);
    void select(const QQPoint pt);
    void deselect();
    void deselect(const QQPoint pt);

signals:

private: // pointers
    QGraphicsScene * scene();
    QGraphicsView * view();

private slots:
    void setup();

private: // non-const

private:
    QGraphicsScene * mpScene=nullptr;
    QGraphicsView * mpView=nullptr;
    ImageGalleryConfig mConfig;
    QList<ImageGalleryItem> mItemList;
    MatrixT<ThumbImage> mThumbMatrix;
    QQPoint mSelectPoint;
    QQPoint::List mMultiSelectPoints;
    QQPoint mAppendPoint;

};
