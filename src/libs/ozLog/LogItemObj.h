#pragma once
#include "ozLog.h"

#include <QtGlobal>
#include <QObject>

#include <QFlags>
#include <QString>
#include <QStringList>
#include <QVariant>
#include <QVariantList>

#include "LogFileInfo.h"
#include "LogContext.h"
#include "LogFunctionInfo.h"

class OZLOG_EXPORT LogItemObj : public QObject
{
    Q_OBJECT
public: // types
    struct ArgumentInfo
    {
        QByteArray  name;
        QVariant    value;
        QString     info;
    };
    typedef QList<ArgumentInfo> ArgumentInfoList;

public: // ctors
    explicit LogItemObj();
    LogItemObj(const LogContext &ctx, const char * pchMessage);
    LogItemObj(const LogContext &ctx, const char * pchFormat,
            const char * argName1, const QVariant &argValue1,
            const char * argName2=0, const QVariant &argValue2=QVariant(),
            const char * argName3=0, const QVariant &argValue3=QVariant(),
            const char * argName4=0, const QVariant &argValue4=QVariant());
    LogItemObj(const LogContext &ctx,
            const QStringList &argNames, const QVariantList &argValues);
    LogItemObj(const LogContext &ctx, const char * pchFormat,
            const QStringList &argNames, const QVariantList &argValues);

public:
    void set(const LogContext &ctx);
    void set(const char * pchMessage);
    void set(const QStringList &argNameList, const QVariantList &argValueList);
    void set(const char * pchFormat, const ArgumentInfoList &args);

private:
    QString             m_qFuncInfo;
    QFileInfo           m_fileInfo;
    int                 m_fileLine;
    QString             m_category;
    QString             m_message;
    QString             m_format;
    ArgumentInfoList    m_arguments;
    QString             m_debugHead;
    QStringList         m_debugStrings;
    QString             m_debugFoot;
};

