#include "SandboxData.h"

#include <QColor>
#include <QImage>

#include <ColorImage.h>
#include <GreyImage.h>
#include <IndexedImage.h>
#include <SCRect.h>

class SandboxDataData : public QSharedData
{
public:
    SCRect d_viewRect;
    QColor d_backColor;
    ColorImage d_backImage;
    ColorImage d_baseColorImage;
    GreyImage d_baseGreyImage;
    IndexedImage d_baseIndexImage;


};

SandboxData::SandboxData()
    : data(new SandboxDataData)
{}

SandboxData::SandboxData(const SandboxData &rhs)
    : data{rhs.data}
{}

SandboxData &SandboxData::operator=(const SandboxData &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

SandboxData::~SandboxData() {}
