#pragma once
#include "ozWidgets.h"

#include <QSharedDataPointer>
#include <QImage>

#include <BaseImage.h>
#include <Key.h>
#include <QQSize.h>
#include <ThumbImage.h>
#include <Types.h>

class ImageGalleryConfig;

class OZWIDGETS_EXPORT ImageGalleryItemData : public QSharedData
{
public:
    Seq             dSeq;
    Key             dKey;
    BaseImage       dOrigImage;
    ThumbImage      dThumbImage;
    bool            dIsSelected;
    bool            dIsMultiSelected;
    Index           dMark;
    QString         dTitleTop;
    QString         dTitleLeft;
    QString         dTitleRight;
    QString         dTitleBottom;
};

class ImageGalleryItem
{
public: // our ctors
    ImageGalleryItem(const QImage &origItem);

public: // const


public: // static

private:
    static Seq smCurrentSeq;
    static ImageGalleryConfig * mpConfig;

    // QSharedData
public:
    ImageGalleryItem();
    ImageGalleryItem(const ImageGalleryItem &);
    ImageGalleryItem &operator=(const ImageGalleryItem &);
    ~ImageGalleryItem();
private:
    QSharedDataPointer<ImageGalleryItemData> data;
};
