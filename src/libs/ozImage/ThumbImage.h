#pragma once
#include "ozImage.h"

#include "BaseImage.h"

#include <QtGlobal>
#include <QColor>

#include <QQSize.h>
#include <SCRect.h>

class OZIMAGE_EXPORT ThumbImage : public BaseImage
{
public:
    ThumbImage();
    ThumbImage(const BaseImage &origImage,
               const QQSize thumbSize=QQSize(),
               const Qt::AspectRatioMode aspectMode=Qt::IgnoreAspectRatio,
               const bool aspectCenter=true,
               const QColor backColor=QColor());
    virtual ~ThumbImage() {;}

public: // const
    BaseImage origImage() const;
    QQSize thumbSize() const;
    Qt::AspectRatioMode aspectMode() const;
    bool aspectCenter() const;
    QColor backColor() const;
    SCRect origRect() const;

public: // static
    static void defaltSize(const QQSize sz);

private:
    void set();

private:
    const BaseImage cmOrigImage;
    const QQSize cmThumbSize;
    const Qt::AspectRatioMode cmAspectMode;
    const bool cmAspectCenter;
    const QColor cmBackColor;
    static QQSize smDefaltSize;
};
