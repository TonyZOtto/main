#pragma once
#include "eIRexe.h"

#include <QObject> // Q_GADGET

#include <QDateTime>
#include <QMetaType>
#include <QString>
#include <QStringList>
#include <QVariant>
#include <QVariantList>

#include "../eIRbase/Boolean.h"
#include "../eIRcore/QQFileInfo.h"
#include "../eIRbase/KeySeg.h"
#include "../eIRbase/Uid.h"

#include "FunctionInfo.h"
#include "LogObject.h"
class Context;
class LogMsgType;

class EIREXE_EXPORT LogItem
{
    Q_GADGET
public: // types
    enum Flag
    {
        $null = 0,
        Message         = 0x00000001,
        Format          = 0x00000002,
        Expect          = 0x00000004,
        Assert          = 0x00000008,
    };
    Q_DECLARE_FLAGS(Flags, Flag);
    Q_FLAG(Flags);

    struct ArgumentInfo
    {
        KeySeg      name;
        QVariant    value;
        QString     text;
    };
    typedef QList<ArgumentInfo> ArgumentInfoList;

public: // ctors
    LogItem(const Context &ctx, const char * pchMessage);
    LogItem(const Context &ctx, const QString msg);
    LogItem(const Context &ctx, const char * pchFormat,
            const char * argName1, const QVariant &argValue1,
            const char * argName2=0, const QVariant &argValue2=QVariant(),
            const char * argName3=0, const QVariant &argValue3=QVariant(),
            const char * argName4=0, const QVariant &argValue4=QVariant());
    LogItem(const Context &ctx, const char * pchFormat,
            const QVariant &argValue1, const QVariant &argValue2=QVariant(),
            const QVariant &argValue3=QVariant(), const QVariant &argValue4=QVariant());
    LogItem(const Context &ctx, const char * pchFormat,
            const QStringList &argNames, const QVariantList &argValues);
    LogItem(const Context &ctx, const LogCompareFlags lcf,      // EXPECT compare
            const char * expText, const QVariant &expValue,
            const char * actText, const QVariant &actValue);
    LogItem(const Context &ctx, const LogCompareFlags lcf,      // EXPECT (bool)
            const char * assText, const QVariant &assValue);

public: // const
    LogMsgType msgtype() const;
    QVariantList argumentVars() const;
    QVariant format() const;
    QVariant format(const Log::OutputFormat fmt) const;

public: // non-const

private: // const
    QVariant formatSingleText() const;
    QVariant formatMultiText() const;
    QString formatPrefix() const;
    QString formatMessage() const;

private: // non-const;
    Flags & flags();
    Index setSequence();
    void set(const Context &ctx);
    void set(const LogLevel lvl);
    void set(const LogCompareFlags lcf);
    void set(const char * pchMessage);
    void set(const QString msg);
    void set(const ArgumentInfoList &args);
    void set(const char * pchFormat, const ArgumentInfoList &args);

public: // QMetaType
    LogItem() = default;
    ~LogItem() = default;
    LogItem(const LogItem &) = default;
    LogItem &operator=(const LogItem &) = default;

private:
    Uid     mUid;
    Boolean mBoolean;
    static Index smNextSequence;

private: // ------------------------ properties ------------------------
    LogLevel            m_level;
    Flags               m_flags;
    QDateTime           m_timestamp;
    Index               m_sequence;
    FunctionInfo        m_functionInfo;
    QQFileInfo          m_fileInfo;
    unsigned            m_fileLine;
    QString             m_message;
    QString             m_format;
    QStringList         m_outputStrings;
    LogCompareFlags     m_compareflags;
    ArgumentInfoList    m_arguments;
    QString             m_debugHead;
    QString             m_debugFoot;
    QStringList         m_debugStrings;
};

Q_DECLARE_METATYPE(LogItem);
Q_DECLARE_OPERATORS_FOR_FLAGS(LogItem::Flags);
typedef LogItem::Flags  LogItemFlags;


