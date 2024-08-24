#include "IndexedImage.h"

#include <BrightnessContrast.h>

#include "Grey16Photo.h"

IndexedImage::IndexedImage() {}
IndexedImage::IndexedImage(const QImage aIndexImage)
    : BaseImage(Image::Index, aIndexImage) {;}
IndexedImage::IndexedImage(const BaseImage &other) : BaseImage(other) {;}
IndexedImage::IndexedImage(const Grey16Image &aGrey16,
                       const BrightnessContrast aBC)
    : BaseImage(Image::Index, QImage(aGrey16.size(), QImage::Format_Indexed8))
{
    set(aGrey16, aBC);
}

void IndexedImage::set(const Grey16Image &aGrey16, const BrightnessContrast aBC)
{
    for (Index rix = 0; rix < aGrey16.size().height(); ++rix)
    {
        WORD * pInPixel  = (WORD *)aGrey16.baseImage().scanLine(rix);
        BYTE * pOutPixel = (BYTE *)baseImage().scanLine(rix);
        for (Index cix = 0; cix < aGrey16.size().width(); ++cix)
        {
            const WORD cInPixel = *pInPixel++;
            const WORD cBCPixel = aBC.translate(cInPixel);
            const BYTE cOutPixel = (cBCPixel + 0x80) >> 8;
            *pOutPixel++ = cOutPixel;
        }
    }
}

bool IndexedImage::isPlanar() const
{
    return true;
}
