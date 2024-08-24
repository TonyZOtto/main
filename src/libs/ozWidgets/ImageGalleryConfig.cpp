#include "ImageGalleryConfig.h"

#include <QtGlobal>
#include <QColor>

#include <QQSize.h>
#include <Rgba32Table.h>
#include <Types.h>

class ImageGalleryConfigData : public QSharedData
{
public: // read-write
    QString             d_title;
    QQSize              d_maxThumbsSize;
    Count               d_maxThumbsArea;
    QQSize              d_thumbSize;
    int                 d_markWidth;
    int                 d_cellSeparation;
    bool                d_multiSelect;
    QColor              d_selectColor;
    QColor              d_backColor;
    Qt::AspectRatioMode d_aspectMode;
    bool                d_aspectCenter;
    QQSize              d_viewSize;
    bool                d_allowScroll;
    Qt::Orientations    d_scrollOrientations;
    Rgba32Table         d_markColorTable;
    Qt::Edges           d_titleEdges;
    int                 d_titleHeight;
    QString             d_titleFont;
    int                 d_titlePoints;
    int                 d_titleWeight;
    QColor              d_titleForeColor;
    QColor              d_titleBackColor;

public: // calculated or read-only
    QQSize              d_cells;
    QQSize              d_sceneSize;
    QQSize::List        d_typicalThumbSizes;
};

ImageGalleryConfig::ImageGalleryConfig()
    : data(new ImageGalleryConfigData)
{}

ImageGalleryConfig::ImageGalleryConfig(const ImageGalleryConfig &rhs)
    : data{rhs.data}
{}

ImageGalleryConfig &ImageGalleryConfig::operator=(const ImageGalleryConfig &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

ImageGalleryConfig::~ImageGalleryConfig() {}
