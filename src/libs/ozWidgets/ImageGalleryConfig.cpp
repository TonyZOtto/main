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
public:
    QString             dTitle;
    QQSize              dViewCellSize;
    QQSize              dThumbSize;
    int                 dMarkWidth;
    int                 dCellSeparation;
    bool                dIsMultiSelect;
    QColor              dSelectColor;
    Qt::AspectRatioMode dAspectMode;
    bool                dAspectCenter;
    Qt::Orientation     dScrollOrientation;
    Rgba32Table         dMarkColorTable;
    QColor              dEmptyCellColor;
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
    : data(new ImageGalleryConfigData)
{
    Q_ASSERT(!"MUSTDO"); // MUSTDO ImageGalleryConfig::ImageGalleryConfig(aMap)
    Q_UNUSED(aMap);

}

ImageGalleryConfig::ImageGalleryConfig(const QQSize thumbSize,
                                       const QString &aTitle)
    : data(new ImageGalleryConfigData)
{
    data->dTitle = aTitle;
    data->dThumbSize = thumbSize;
    // setDefalts();
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
    Q_UNUSED(aKey); Q_UNUSED(aValue);
    /*
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
    else qWarning() << Q_FUNC_INFO << "Unhandled Config item" << aKey << aValue; */
}


void ImageGalleryConfig::calculate()
{
    QQSize tCellSize(data->dThumbSize);
    tCellSize += 2 * data->dMarkWidth;
    tCellSize += data->dCellSeparation;
    const Qt::Edges cEdges = data->dTitleEdges;
    const int cHeight = data->dTitleHeight;
    if (cEdges.testFlag(Qt::TopEdge))
        tCellSize.height(cHeight + tCellSize.height());
    if (cEdges.testFlag(Qt::BottomEdge))
        tCellSize.height(cHeight + tCellSize.height());
    if (cEdges.testFlag(Qt::LeftEdge))
        tCellSize.width(cHeight + tCellSize.width());
    if (cEdges.testFlag(Qt::RightEdge))
        tCellSize.width(cHeight + tCellSize.width());
    mCellSize = tCellSize;
}

// QSharedDataPointer
ImageGalleryConfig::ImageGalleryConfig() : data(new ImageGalleryConfigData) {;}
ImageGalleryConfig::ImageGalleryConfig(const ImageGalleryConfig &rhs) : data{rhs.data} {;}
ImageGalleryConfig::~ImageGalleryConfig() {}
ImageGalleryConfig &ImageGalleryConfig::operator=(const ImageGalleryConfig &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}
