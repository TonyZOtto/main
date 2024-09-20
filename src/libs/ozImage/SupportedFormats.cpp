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
    const FormatFlags cFlags =  parseFlags($nullFlag, bas);
    qInfo() << Q_FUNC_INFO << bas << Qt::hex << cFlags << "was" << mFlags;
    mFlags = cFlags;
}

void SupportedFormats::update(const QString &s)
{
    QString tFormats = s;
    const bool tClear = tFormats.startsWith('=');
    if (tClear) tFormats.removeFirst();
    QByteArrayList tFormatsBAs = SupportedFormats::baList(tFormats);
    update(tFormatsBAs, tClear);
}

void SupportedFormats::update(const QByteArrayList &bas, const bool clear)
{
    const FormatFlags cFlags =  parseFlags(clear ? FormatFlags(0) : mFlags, bas);
    qInfo() << Q_FUNC_INFO << bas << clear
            << Qt::hex << cFlags << "was" << mFlags;
    mFlags = cFlags;
}

// ---------------------- static ---------------------

SupportedFormats::FormatFlags SupportedFormats::parseFlags(
    const FormatFlags ffs, const QByteArrayList &bas)
{
    FormatFlags result = ffs;
    foreach (AText key, bas)
    {
        bool tNeg = key.startsWith('-');
        if (tNeg) key.removeFirst();
        const FormatFlag cFlag = formatFlag(key);
        if (tNeg)
            result &= ~ cFlag;
        else
            result |= cFlag;
    }
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

QByteArrayList SupportedFormats::baList(const QString &s)
{
    QByteArrayList result;
    QStringList tStrings = s.simplified().split(' ');
    while ( ! tStrings.isEmpty())
        result.append(tStrings.takeFirst().toUtf8());
    return result;
}
