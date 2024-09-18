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
    explicit ImageGalleryWidget(QWidget * viewWidget,
                                QWidget *parent);

public slots:
    void initialize();
    void configure();
    void setup();

    void add(const ImageGalleryItem &item);
    QQPoint append(const ThumbImage aThumb);
    void select(const QQPoint cellPoint);
    void deselect();
    void deselect(const QQPoint cellPoint);

signals:
    void initialized();
    void configured();
    void setuped();

public: // const
    ImageGalleryConfig config();

public: // non-const
    void config(const ImageGalleryConfig cfg);

private: // pointers
    QGraphicsScene * scene();
    QGraphicsView * view();

private: // non-const
    void calculate();
    void calculateViewGeometry();

private:
    QWidget * mpViewWidget=nullptr;
    QGraphicsScene * mpScene=nullptr;
    QGraphicsView * mpView=nullptr;
    ImageGalleryConfig mConfig;
    QList<ImageGalleryItem> mItemList;
    MatrixT<ThumbImage> mThumbMatrix;
    QQPoint mSelectPoint;
    QQPoint::List mMultiSelectPoints;
    QQPoint mAppendPoint;
};

inline ImageGalleryConfig ImageGalleryWidget::config() { return mConfig; }

