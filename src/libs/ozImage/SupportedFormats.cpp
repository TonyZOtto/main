#include "SupportedFormats.h"

#include <QImageReader>
#include <QImageWriter>

SupportedFormats::SupportedFormats(const Class cls)
    : cmClass(cls), mpObjectHelper(new ObjectHelper(this)) { set(); }
SupportedFormats::SupportedFormats(const Class cls, const QByteArrayList &bas)
    : cmClass(cls), mpObjectHelper(new ObjectHelper(this)) { set(bas); }

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

// ---------------------- static ---------------------

SupportedFormats::FormatFlags SupportedFormats::parseFlags(const QByteArrayList &bas)
{
    FormatFlags result;
    foreach (const AText key, bas)
        result |= formatFlag(key);
    return result;
}

AText SupportedFormats::formatKey(const FormatFlag ff)
{
    return objectHelper()->enumKey("FormatSuffix", ff);
}

SupportedFormats::FormatSuffix SupportedFormats::formatSuffix(const AText &key)
{
    return FormatSuffix(objectHelper()->enumValue("FormatSuffix", key));
}

SupportedFormats::FormatFlag SupportedFormats::formatFlag(const AText &key)
{
    FormatFlag result = $nullFlag;
    const int cSuffix = formatSuffix(key);
    if (cSuffix >= 0) result = FormatFlag(1 << cSuffix);
    return result;
}
