#pragma once
#include "ozLog.h"

#include <QtGlobal>
#include <QObject>

#include <QFlags>
#include <QString>
#include <QStringList>
#include <QVariant>
#include <QVariantList>

#include "FileInfo.h"
#include "Context.h"
#include "FunctionInfo.h"

class OZLOG_EXPORT LogItem : public QObject
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
    explicit LogItem();
    LogItem(const Context &ctx, const char * pchMessage);
    LogItem(const Context &ctx, const char * pchFormat,
            const char * argName1, const QVariant &argValue1,
            const char * argName2=0, const QVariant &argValue2=QVariant(),
            const char * argName3=0, const QVariant &argValue3=QVariant(),
            const char * argName4=0, const QVariant &argValue4=QVariant());
    LogItem(const Context &ctx,
            const QStringList &argNames, const QVariantList &argValues);
    LogItem(const Context &ctx, const char * pchFormat,
            const QStringList &argNames, const QVariantList &argValues);

public:
    void set(const Context &ctx);
    void set(const char * pchMessage);
    void set(const QStringList &argNameList, const QVariantList &argValueList);
    void set(const char * pchFormat, const ArgumentInfoList &args);

private: // ------------------------ properties ------------------------
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

