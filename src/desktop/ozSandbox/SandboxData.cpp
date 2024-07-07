#include "SandboxData.h"

#include <QColor>
#include <QImage>

#include <ColorPhoto.h>
#include <GreyPhoto.h>
#include <SCRect.h>

class SandboxDataData : public QSharedData
{
public:
    SCRect d_viewRect;
    QColor d_backColor;
    ColorPhoto d_backPhoto;
    ColorPhoto d_baseColorPhoto;
    GreyPhoto d_baseGreyPhoto;
    IndexPhoto d_baseIndexPhoto;


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
