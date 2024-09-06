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
    void initialize();
    void configure();
    void setup();

    void add(const ImageGalleryItem &item);
    QQPoint append(const ThumbImage aThumb);
    void select(const QQPoint pt);
    void deselect();
    void deselect(const QQPoint pt);

signals:
    void initialized();
    void configured();
    void setuped();


private: // pointers
    QGraphicsScene * scene();
    QGraphicsView * view();

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
