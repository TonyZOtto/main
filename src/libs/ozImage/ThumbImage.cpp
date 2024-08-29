#include "ThumbImage.h"

QQSize ThumbImage::smDefaltSize(192);

ThumbImage::ThumbImage()
    : cmAspectMode(Qt::KeepAspectRatio)
    , cmAspectCenter(false) {;}

ThumbImage::ThumbImage(const BaseImage &origImage,
                       const QQSize thumbSize,
                       const Qt::AspectRatioMode aspectMode,
                       const bool aspectCenter,
                       const QColor backColor)
    : cmOrigImage(origImage)
    , cmThumbSize(thumbSize)
    , cmAspectMode(aspectMode)
    , cmAspectCenter(aspectCenter)
    , cmBackColor(backColor)
{
    set();
}

void ThumbImage::defaltSize(const QQSize sz)
{
    smDefaltSize = sz;
}

void ThumbImage::set()
{

}
