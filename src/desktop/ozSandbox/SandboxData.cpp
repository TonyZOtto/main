#include "SandboxData.h"

#include <QColor>
#include <QImage>

#include <SCRect.h>

class SandboxDataData : public QSharedData
{
public:
    SCRect d_viewRect;
    QColor d_backColor;
    QImage d_backImage;
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
