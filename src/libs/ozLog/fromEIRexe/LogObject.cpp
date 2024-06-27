#include "LogObject.h"

#include <QMetaEnum>

#include "../eIRcore/ObjectHelper.h"
#include "LogMsgType.h"


// ======================= static ====================

EIREXE_EXPORT Log::LevelFlags Log::UserFlags = Log::LevelFlags(Log::FlagPrefer | Log::FlagDetail |
                                              Log::FlagDump | Log::FlagInfo |
                                              Log::FlagProgress | Log::FlagInfo |
                                              Log::FlagAssert | Log::FlagError |
                                              Log::FlagFatal);
EIREXE_EXPORT Log::LevelFlags Log::TraceFlags = Log::LevelFlags(Log::FlagTFnArg | Log::FlagTFnLeave |
                                         Log::FlagTFnEnter | Log::FlagTDetail |
                                         Log::FlagTDump | Log::FlagTrace |
                                         Log::FlagTPrefer | Log::FlagExpect |
                                         Log::FlagTWarning | Log::FlagTProgress |
                                         Log::FlagTExpect | Log::FlagTError |
                                         Log::FlagTFatal);

Log::Log(QObject *parent) : QObject{parent} { setObjectName("Log"); }
Log::~Log() {;}

LogMsgType Log::msgType(const Log::Level lvl)
{
    LogMsgType result = LogMsgType::$null;
    switch (lvl)
    {
    case Prefer:    case Detail:    case Dump:
    case Info:      case Progress:              result = LogMsgType::Info;      break;
    case TFnArg:    case TFnLeave:  case TFnEnter:
    case TDetail:   case TDump:     case Trace:
    case TPrefer:   case TInfo:
    case TProgress:                             result = LogMsgType::Debug;     break;
    case Warning:   case TWarning:              result = LogMsgType::Warning;   break;
    case Error:     case TError:
    case Expect:    case TExpect:               result = LogMsgType::Error;     break;
    case Fatal:     case TFatal:                result = LogMsgType::Fatal;     break;
    default:
                                                /* leave $null result */        break;
    }
    return result;
}

QChar Log::levelChar(const Level lvl)
{
    QChar result('?');
    Q_UNUSED(lvl); // TODO Log::levelChar()
    return result;
}

Log::OutputScheme Log::outputScheme(const AText key)
{
    Log::OutputScheme result = Log::$nullOutputScheme;
#if 1
    if ("none" == key)          result = Log::NoneOutputScheme;
    else if ("troll" == key)    result = Log::TrollOutputScheme;
    else if ("file" == key)     result = Log::FileOutputScheme;
    else if ("sql" == key)      result = Log::SqlOutputScheme;
    else qWarning() << "Invalid" << Q_FUNC_INFO << key;
#else // TODO Why MetaEnum not working?
    qInfo() << Q_FUNC_INFO << key;
    QString tScheme = key.first(1).toUpper() + key.mid(1);
    tScheme += "OutputScheme";
    ObjectHelper tOH(new Log);
    tOH.dumpInfo();
    qDebug() << tOH.enumNames(true);
    qDebug() << tOH.enumKeys("Level");
    qDebug() << tScheme << tOH.enumKeys("OutputScheme");
    const QMetaEnum cME = tOH.metaEnum("OutputScheme");
    const int cSchemeIndex = cME.keyToValue(qPrintable(tScheme));
    if (cSchemeIndex > 0)
        result = Log::OutputScheme(cSchemeIndex);
#endif
    return result;
}

Log::OutputFormat Log::outputFormat(const AText key)
{
    Log::OutputFormat result = Log::$nullOutputFormat;
    const AText cKey = key.toLower();
    if      ("txtfile" == cKey)         result = Log::TextFileSingleOutput;
    else if ("mtxtfile" == cKey)        result = Log::TextFileMultiOutput;
    else if ("xmlfile" == cKey)         result = Log::XmlFileOutput;
    else if ("datafile" == cKey)        result = Log::DataFileOutput;
    else if ("textstream" == cKey)      result = Log::StreamFileOutput;
    else if ("sqlrec" == cKey)          result = Log::SqlRecordOutput;
    else if ("sqlxmlfile" == cKey)      result = Log::SqlXmlOutput;
    else if ("nosqlxmlfile" == cKey)    result = Log::NoSqlXmlOutput;
    return result;
}
