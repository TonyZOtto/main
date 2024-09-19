#pragma once
#include "ozImage.h"

#include <QObject>
#include <QFlags>

#include <AText.h>
#include <KeySegList.h>
#include <ObjectHelper.h>

class OZIMAGE_EXPORT SupportedFormats : public QObject
{
    Q_GADGET
public: // types
    enum Class
    {
        $nullClass = -1,
        Read,
        Write,
        $maxClass
    };
    Q_ENUM(Class)
    enum Format
    {
        $nullFormat = 0,
        FormatBMP,
        FormatGIF,
        FormatJPG,
        FormatPNG,
        FormatPBM,
        FormatPGM,
        FormatPPM,
        FormatXBM,
        FormatXPM,
        FormatSVG,
        $maxFormat
    };
    Q_ENUM(Format)
    enum FormatSuffix
    {
        $nullSuffix = 0,
        BMP,
        GIF,
        JPG,
        PNG,
        PBM,
        PGM,
        PPM,
        XBM,
        XPM,
        SVG,
        $maxSuffix
    };
    Q_ENUM(FormatSuffix)
    enum FormatFlag
    {
        $nullFlag       = 0,
        FlagBMP         = 1 << FormatBMP,
        FlagGIF         = 1 << FormatGIF,
        FlagJPG         = 1 << FormatJPG,
        FlagPNG         = 1 << FormatPNG,
        FlagPBM         = 1 << FormatPBM,
        FlagPGM         = 1 << FormatPGM,
        FlagPPM         = 1 << FormatPPM,
        FlagXBM         = 1 << FormatXBM,
        FlagXPM         = 1 << FormatXPM,
        FlagSVG         = 1 << FormatSVG,
    };
    Q_DECLARE_FLAGS(FormatFlags, FormatFlag)

public: // ctors
    explicit SupportedFormats(const Class cls=$nullClass);
    SupportedFormats(const Class cls, const QByteArrayList &bas);

public: // const
    bool isNull() const;

public: // non-const
    void set();
    void set(const QByteArrayList &bas);
    void update(const QByteArrayList &bas);

public: // non-const
    ObjectHelper * objectHelper();

private: // static
    FormatFlags parseFlags(const FormatFlags ffs, const QByteArrayList &bas);
    AText formatKey(const FormatFlag ff);
    FormatSuffix formatSuffix(const AText &key);
    FormatFlag formatFlag(const AText &key);

private:
    const Class cmClass;
    FormatFlags mFlags;
    ObjectHelper * mpObjectHelper=nullptr;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(SupportedFormats::FormatFlags)

inline ObjectHelper *SupportedFormats::objectHelper() { Q_ASSERT(mpObjectHelper); return mpObjectHelper; }


