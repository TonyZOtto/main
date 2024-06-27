#pragma once
#include "eIRexe.h"

#include <QObject>

#include <QString>

#include "../eIRbase/AText.h"

class LogMsgType;

class EIREXE_EXPORT Log : public QObject
{
    Q_OBJECT
public: // types
    enum Level
    {
        $nullLevel = 0,
        Prefer,         // 01
        TFnArg,         // 02
        TFnLeave,       // 03
        TFnEnter,       // 04
        Level05,        // 05
        TDetail,        // 06
        Detail,         // 07
        Level08,        // 08
        TDump,          // 09
        Dump,           // 10
        Trace,          // 11
        Level12,        // 12
        TPrefer,        // 13
        Level14,        // 14
        TInfo,          // 15
        Info,           // 16
        TWarning,       // 17
        Warning,        // 18
        TProgress,      // 19
        Progress,       // 20
        Level21,        // 21
        TExpect,        // 22
        Expect,         // 23
        Level24,        // 24
        Assert,         // 25
        Level26,        // 26
        TError,         // 27
        Error,          // 28
        TFatal,         // 29
        Fatal,          // 30
        System,         // 31
        $minLevel = Prefer,
        $maxLevel = System,
    };
    Q_ENUM(Level);

    enum LevelFlag
    {
        Flag$Null       = 1 << $nullLevel,
        FlagPrefer      = 1 << Prefer,
        FlagTFnArg      = 1 << TFnArg,
        FlagTFnLeave    = 1 << TFnLeave,
        FlagTFnEnter    = 1 << TFnEnter,
        FlagLevel05     = 1 << Level05,
        FlagTDetail     = 1 << TDetail,
        FlagDetail      = 1 << Detail,
        FlagLevel08     = 1 << Level08,
        FlagTDump       = 1 << TDump,
        FlagDump        = 1 << Dump,
        FlagTrace       = 1 << Trace,
        FlagLevel12     = 1 << Level12,
        FlagTPrefer     = 1 << TPrefer,
        FlagLevel14     = 1 << Level14,
        FlagTInfo       = 1 << TInfo,
        FlagInfo        = 1 << Info,
        FlagTWarning    = 1 << TWarning,
        FlagWarning     = 1 << Warning,
        FlagTProgress   = 1 << TProgress,
        FlagProgress    = 1 << Progress,
        FlagLevel21     = 1 << Level21,
        FlagTExpect     = 1 << TExpect,
        FlagExpect      = 1 << Expect,
        FlagLevel24     = 1 << Level24,
        FlagAssert      = 1 << Assert,
        FlagLevel26     = 1 << Level26,
        FlagTError      = 1 << TError,
        FlagError       = 1 << Error,
        FlagTFatal      = 1 << TFatal,
        FlagFatal       = 1 << Fatal,
        FlagSystem      = 1 << System,
    };
    Q_DECLARE_FLAGS(LevelFlags, LevelFlag);
    Q_ENUM(LevelFlag);
    static LevelFlags UserFlags;
    static LevelFlags TraceFlags;

    enum Compare
    {
        $nullCompare        = 0,
        EqualityMask        = 0x30000000,
        Equals              = 0x30000000,
        NotEqual            = 0x10000000,
        ValueMask           = 0x03000000,
        GreaterThan         = 0x02000000,
        LessThan            = 0x01000000,
        GreaterEqual        = Equals | GreaterThan,
        LessEqual           = Equals | LessThan,
        ExpectMask          = 0x00300000,
        Expectation         = 0x00100000,
        ExpectBit           = 0x00200000,
        ExpectTrue          = Expectation | ExpectBit,
        ExpectFalse         = Expectation | false,
    };
    Q_DECLARE_FLAGS(CompareFlags, Compare);
    Q_ENUM(Compare);

    enum UrlType
    {
        $nullUrlType          = 0,
        OutputUrl             = 101,
        CacheUrl,
    };
    Q_ENUM(UrlType);

    enum OutputScheme
    {
        $nullOutputScheme     = 0,
        NoneOutputScheme      = 201,
        FileOutputScheme,
        TrollOutputScheme,
        SqlOutputScheme,
    };
    Q_ENUM(OutputScheme);

    enum OutputFormat
    {
        $nullOutputFormat       = 0,
        TextFileSingleOutput    = 301,
        TextFileMultiOutput,
        XmlFileOutput,
        DataFileOutput,
        StreamFileOutput,
        SqlRecordOutput,
        SqlXmlOutput,
        NoSqlXmlOutput,
    };
    Q_ENUM(OutputFormat);

public:
    explicit Log(QObject *parent = nullptr);
    ~Log();

public: // static
    static LogMsgType msgType(const Log::Level lvl);
    static QChar levelChar(const Log::Level lvl);
    static OutputScheme outputScheme(const AText key);
    static OutputFormat outputFormat(const AText key);

signals:
};

Q_DECLARE_METATYPE(Log::OutputScheme)

typedef Log::Level          LogLevel;
typedef Log::Compare        LogCompare;
typedef Log::CompareFlags   LogCompareFlags;

