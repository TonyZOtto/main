#include "OutputLogUrl.h"

#include "../eIRcore/ObjectHelper.h"

#include "Logger.h"
Q_GLOBAL_STATIC(Logger, LOG);

OutputLogUrl::OutputLogUrl()
    : BaseLogUrl(Log::OutputUrl)
    , mOutputFormat(Log::$nullOutputFormat)
    , mLevelFlags(0)
{
}

OutputLogUrl::OutputLogUrl(const QString &aUrlString)
    : BaseLogUrl(Log::OutputUrl, aUrlString)
{
    mpLogObjectHelper = new ObjectHelper(LOG);
    Q_CHECK_PTR(mpLogObjectHelper);
    mMetaEnum = mpLogObjectHelper->metaEnum("Level");
    mOutputFormat = parseOutputFormat();
    mLevelFlags = parseLevels();
}

OutputLogUrl::OutputLogUrl(const QUrl &aUrl)
    : BaseLogUrl(Log::OutputUrl, aUrl)
{
    mpLogObjectHelper = new ObjectHelper(LOG);
    Q_CHECK_PTR(mpLogObjectHelper);
    mMetaEnum = mpLogObjectHelper->metaEnum("Level");
    mOutputFormat = parseOutputFormat();
    mLevelFlags = parseLevels();
}

Log::OutputFormat OutputLogUrl::parseOutputFormat()
{
    Log::OutputFormat result = Log::$nullOutputFormat;
    if (hasQuery("Format"))
    {
        const QString cFormat = queryValue("Format");
        if ("TextFile" == cFormat)
            result = Log::TextFileSingleOutput;
        else if ("TextFileML" == cFormat)
            result = Log::TextFileMultiOutput;
        else if ("XmlFile" == cFormat)
            result = Log::XmlFileOutput;
        else if ("DataStream" == cFormat)
            result = Log::DataFileOutput;
        else if ("TextStream" == cFormat)
            result = Log::StreamFileOutput;
        else if ("XmlRecord" == cFormat)
            result = Log::SqlRecordOutput;
        else if ("XmlSql" == cFormat)
            result = Log::SqlXmlOutput;
        else if ("XmlNoSql" == cFormat)
            result = Log::NoSqlXmlOutput;
        else
            qWarning() << "Unhandled Log Output Format:" << cFormat;
    }
    return result;
}

Log::LevelFlags OutputLogUrl::parseLevels()
{
    Log::LevelFlags result = Log::LevelFlags(0);
    if (hasQuery("Level"))
    {
        const QString cLevelQueryString = queryValue("Level");
        const QStringList cLevelStrings = cLevelQueryString.split(",");
        foreach (const QString cLevelString, cLevelStrings)
            result |= parseLevelString(cLevelString);
        // TODO Handle TraceFlags and UserFlags
    }
    else
    {
        if ("troll" == scheme())
            result = Log::TraceFlags;
        else if ("file" == scheme())
            result = Log::TraceFlags | Log::UserFlags;
    }
    return result;
}

Log::LevelFlags OutputLogUrl::parseLevelString(const QString &aLevelString)
{
    Log::LevelFlags result = Log::LevelFlags(0);
    if (aLevelString == "User")
    {
        result |= Log::UserFlags;
    }
    else if (aLevelString == "Trace")
    {
        result |= Log::TraceFlags;
    }
    else if (aLevelString.contains('-'))
    {
        const QStringList cFromToStrings = aLevelString.split("-");
        Q_ASSERT(cFromToStrings.count() > 1);
        result = parseLevelString(cFromToStrings[0], cFromToStrings[1]);
    }
    else
    {
        const AText cLevelText(aLevelString);
        const Log::LevelFlag cFlag = Log::LevelFlag(mMetaEnum.keyToValue(cLevelText));
        result.setFlag(cFlag);
    }
    return result;
}

Log::LevelFlags OutputLogUrl::parseLevelString(const QString &aFromString, const QString &aToString)
{
    Log::LevelFlags result = Log::LevelFlags(0);
    Log::Level tFromLevel = Log::$minLevel, tToLevel = Log::$maxLevel;
    if ( ! aFromString.isEmpty())
        tFromLevel = Log::Level(mMetaEnum.keyToValue(AText(aFromString)));
    if ( ! aToString.isEmpty())
        tToLevel = Log::Level(mMetaEnum.keyToValue(AText(aToString)));
    if (tFromLevel > tToLevel)
    {
        Log::Level tTempLevel = tToLevel;
        tToLevel = tFromLevel;
        tFromLevel = tTempLevel;
    }
    for (int tLevelInt = tFromLevel; tLevelInt < tToLevel; ++tLevelInt)
        result.setFlag(Log::LevelFlag(tLevelInt));
    return result;
}
