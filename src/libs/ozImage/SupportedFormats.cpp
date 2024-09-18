#include "SupportedFormats.h"

#include <QImageReader>
#include <QImageWriter>

SupportedFormats::SupportedFormats(const Class cls)
    : cmClass(cls) { set(); }
SupportedFormats::SupportedFormats(const Class cls, const QByteArrayList &bas)
    : cmClass(cls) { set(bas); }

bool SupportedFormats::isNull() const
{
    return $nullClass == cmClass || $nullFlag == mFlags;
}

void SupportedFormats::set()
{
    switch (cmClass)
    {
    case Read:  set(QImageReader::supportedImageFormats());  break;
    case Write: set(QImageWriter::supportedImageFormats());  break;
    default:
        qWarning() << Q_FUNC_INFO << "Unsupported:" << cmClass;
        break;
    }
}

void SupportedFormats::set(const QByteArrayList &bas)
{
    Q_ASSERT(!"MUSTDO"); // MUSTDO SupportedFormats::set()
    Q_UNUSED(bas);
}

void SupportedFormats::update(const QByteArrayList &bas)
{
    Q_ASSERT(!"MUSTDO"); // MUSTDO SupportedFormats::intersect()
    Q_UNUSED(bas);
}

FormatFlags SupportedFormats::parseFlags(const QByteArrayList &bas)
{

}

AText SupportedFormats::formatName(const FormatFlag ff)
{

}

SupportedFormats::FormatFlag SupportedFormats::formatFlag(const AText &txt)
{

}
