#include "ThumbImage.h"

QQSize ThumbImage::smDefaltSize(192);

ThumbImage::ThumbImage(const BaseImage &image,
                       const QQSize thumbSize,
                       const Qt::AspectRatioMode aspectMode,
                       const bool aspectCenter,
                       const QColor backColor)
    : cmOrigImage(image)
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
