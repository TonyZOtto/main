#include "ImageGalleryConfig.h"


ImageGalleryConfig::ImageGalleryConfig(QObject *parent)
    : QObject{parent}
{
    setObjectName("ImageGalleryConfig");
    ThumbPixelSize(QQSize(128));
    BackColor(QColor("steelblue"));
    BackColor(QColor(Qt::darkGray));
    ScrollOrientationValue(0); // no scrolling
}
