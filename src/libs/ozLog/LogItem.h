#pragma once
#include "ozCore.h"

#include <QObject>

#include <QString>
#include <QStringList>
#include <QVariant>
#include <QVariantList>

#include "../filesys/QQFileInfo.h"
#include "../ident/KeySeg.h"
#include "Context.h"
#include "FunctionInfo.h"

class OZCORE_EXPORT LogItem : public QObject
{
    Q_GADGET
public: // types
    enum Flag
    {
        $null = 0,
    };
    Q_DECLARE_FLAGS(Flags, Flag);
    Q_FLAG(Flags);

    struct ArgumentInfo
    {
        KeySeg      name;
        QVariant    value;
        QString     info;
    };
    typedef QList<ArgumentInfo> ArgumentInfoList;

public: // ctors
    explicit LogItem();
    LogItem(const Context &ctx, const char * pchMessage);
    LogItem(const Context &ctx, const char * pchFormat,
            const char * argName1, const QVariant &argValue1,
            const char * argName2=0, const QVariant &argValue2=QVariant(),
            const char * argName3=0, const QVariant &argValue3=QVariant(),
            const char * argName4=0, const QVariant &argValue4=QVariant());
    LogItem(const Context &ctx, const char * pchFormat,
            const QStringList &argNames, const QVariantList &argValues);

public:
    void set(const Context &ctx);
    void set(const char * pchMessage);
    void set(const char * pchFormat, const ArgumentInfoList &args);

private: // ------------------------ properties ------------------------
    FunctionInfo        m_functionInfo;
    QQFileInfo          m_fileInfo;
    unsigned            m_fileLine;
    QString             m_category;
    QString             m_message;
    QString             m_format;
    ArgumentInfoList    m_arguments;
    QString             m_debugHead;
    QString             m_debugFoot;
    QStringList         m_debugStrings;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(LogItem::Flags);
