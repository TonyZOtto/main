#include "ImageGalleryConfig.h"

#include <QtGlobal>
#include <QColor>

#include <Rgba32Table.h>

QQSize::List ImageGalleryConfig::smTypicalThumbSizes
    = QQSize::List()
        << QQSize(64) << QQSize(80) << QQSize(96) << QQSize(128)
        << QQSize(144) << QQSize(160) << QQSize(192) << QQSize(256)
        << QQSize(48, 64) << QQSize(64, 48) // 4x3
        << QQSize(96, 128) << QQSize(128, 96)
        << QQSize(54, 96) << QQSize(96, 54) // 9x16
        << QQSize(72, 128) << QQSize(128, 72)
        << QQSize(108, 192) << QQSize(192, 108)
        << QQSize(144, 256) << QQSize(256, 144);

class ImageGalleryConfigData : public QSharedData
{
public: // read-write
    QString             dTitle;
    QQSize              dMaxThumbsSize;
    Count               dMaxThumbsArea;
    QQSize              dThumbSize;
    int                 dMarkWidth;
    int                 dCellSeparation;
    bool                dIsMultiSelect;
    QColor              dSelectColor;
    Qt::AspectRatioMode dAspectMode;
    bool                dAspectCenter;
    QQSize              dViewSize;
    bool                dAllowScroll;
    Qt::Orientations    dScrollOrientations;
    Rgba32Table         dMarkColorTable;
    Qt::Edges           dTitleEdges;
    int                 dTitleHeight;
    QString             dTitleFont;
    int                 dTitlePoints;
    int                 dTitleWeight;
    QColor              dTitleForeColor;
    QColor              dTitleBackColor;
};

ImageGalleryConfig::ImageGalleryConfig(const QString &aTitle)
    : data(new ImageGalleryConfigData)
{
    data->dTitle = aTitle;
}

ImageGalleryConfig::ImageGalleryConfig(const KeyMap &aMap)
{
    Q_ASSERT(!"MUSTDO"); // MUSTDO ImageGalleryConfig::ImageGalleryConfig(aMap)
    Q_UNUSED(aMap);

}

ImageGalleryConfig::ImageGalleryConfig(const QQSize thumbSize,
                                       const QString &aTitle)
{
    data->dTitle = aTitle;
    data->dThumbSize = thumbSize;
    // defalts
    data->dMaxThumbsArea = 0;
    data->dMarkWidth = 5;
    data->dCellSeparation = 5;
    data->dIsMultiSelect = false;
    data->dAspectMode = Qt::KeepAspectRatioByExpanding;
    data->dAspectCenter = true;
    data->dAllowScroll = false;
    data->dTitleEdges = Qt::Edges(0);
    data->dTitleHeight = 9;
    data->dTitlePoints = 7;
    data->dTitleWeight = 500;
    calculate();
}

ImageGalleryConfig::ImageGalleryConfig(const Index thumbSizeIndex,
                                       const QString &aTitle)
{
    data->dTitle = aTitle;
    if (thumbSizeIndex >= 0
            && thumbSizeIndex < smTypicalThumbSizes.count())
        data->dThumbSize = smTypicalThumbSizes.value(thumbSizeIndex);
    calculate();
}

QString ImageGalleryConfig::title() const
{
    return data->dTitle;
}

void ImageGalleryConfig::set(const KeyMap &aMap)
{
    Q_ASSERT(!"MUSTDO"); // MUSTDO ImageGalleryConfig::set()
    Q_UNUSED(aMap);
}

void ImageGalleryConfig::set(const Key &aKey, const QVariant &aValue)
{
    if (false)  ;
    else if (aKey == "Title")   data->dTitle = aValue.toString();
    else if (aKey == "MaxThumbsSize")  data->dMaxThumbsSize = aValue.toSize();
    else if (aKey == "dMaxThumbsArea")  data->dMaxThumbsArea = aValue.toUInt();
    else if (aKey == "dThumbSize")  data->dThumbSize = aValue.toSize();
    else if (aKey == "dMarkWidth")  data->dMarkWidth = aValue.toInt();
    else if (aKey == "dCellSeparation")  data->dCellSeparation = aValue.toInt();
    else if (aKey == "dIsMultiSelect")  data->dIsMultiSelect = aValue.toBool();
    else if (aKey == "dSelectColor")  data->dSelectColor = aValue.toString();
    else if (aKey == "dAspectMode")  data->dAspectMode = Qt::AspectRatioMode(aValue.toInt());
    else if (aKey == "dAspectCenter")  data->dAspectCenter = aValue.toBool();
    else if (aKey == "dViewSize")  data->dViewSize = aValue.toSize();
    else if (aKey == "dAllowScroll")  data->dAllowScroll = aValue.toBool();
    else if (aKey == "dScrollOrientations")  data->dScrollOrientations = Qt::Orientations( aValue.toInt());
// for now TODO    else if (aKey == "dMarkColorTable")  data->dMarkColorTable.set(aValue.toString());
    else if (aKey == "dTitleEdges")  data->dTitleEdges = Qt::Edges(aValue.toInt());
    else if (aKey == "dTitleHeight")  data->dTitleHeight = aValue.toInt();
    else if (aKey == "dTitleFont")  data->dTitleFont = aValue.toString();
    else if (aKey == "dTitleHeight")  data->dTitleHeight = aValue.toInt();
    else if (aKey == "dTitlePoints")  data->dTitlePoints = aValue.toInt();
    else if (aKey == "dTitleWeight")  data->dTitleWeight = aValue.toInt();
    else if (aKey == "dTitleForeColor")  QColor(data->dTitleForeColor = aValue.toString());
    else if (aKey == "dTitleBackColor")  QColor(data->dTitleBackColor = aValue.toString());
    else qWarning() << Q_FUNC_INFO << "Unhandled Config item" << aKey << aValue;
}

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

void ImageGalleryConfig::calculate()
{
    Q_ASSERT(!"MUSTDO"); // MUSTDO ImageGalleryConfig::calculate()
}
