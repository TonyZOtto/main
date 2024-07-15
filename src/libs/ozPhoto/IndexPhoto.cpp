#include "IndexPhoto.h"

#include <BrightnessContrast.h>

#include "Grey16Photo.h"

IndexPhoto::IndexPhoto() {}
IndexPhoto::IndexPhoto(const QImage aIndexImage)
    : BasePhoto(Photo::Index, aIndexImage) {;}
IndexPhoto::IndexPhoto(const BasePhoto &other) : BasePhoto(other) {;}
IndexPhoto::IndexPhoto(const Grey16Photo &aGrey16,
                       const BrightnessContrast aBC)
    : BasePhoto(Photo::Index, QImage(aGrey16.size(), QImage::Format_Indexed8))
{
    set(aGrey16, aBC);
}

void IndexPhoto::set(const Grey16Photo &aGrey16, const BrightnessContrast aBC)
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

bool IndexPhoto::isPlanar() const
{
    return true;
}
