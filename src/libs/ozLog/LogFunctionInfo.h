#pragma once
#include "ozLog.h"

#include <QObject>

#include <QByteArray>
#include <QByteArrayList>
#include <QByteArrayList>

class OZLOG_EXPORT LogFunctionInfo
{
    Q_GADGET
public: // types
    enum Flag
    {
        $null = 0,
        AnteConst       = 0x80000000,
        Virtual         = 0x40000000,
        VoidReturn      = 0x08000000,

        VoidArguments   = 0x00000800,
        ConstArgument   = 0x00000200,
        VarArgs         = 0x00000100,

        PostConst       = 0x00000080,
        PostConstExpr   = 0x00000080,
        Override        = 0x00000040,
        PureVirtual     = 0x00000020,
    };
    Q_DECLARE_FLAGS(Flags, Flag)
    Q_FLAG(Flags)

    struct Argument
    {
        QByteArray      string;
        QByteArray      type;
        QByteArray      name;
        QByteArray      defalt;
        Flags           flags;
    };
    typedef QList<Argument> ArgumentList;

public: // ctors
    explicit LogFunctionInfo();
    LogFunctionInfo(const QByteArray &qFileInfo);

public: // non-const
    bool parse(const QByteArray &aQFuncInfo);

private:
    bool splitStrings();
    bool parseAnte(const QByteArray &aBA);
    bool parseNames(const QByteArray &aBA);
    bool parseArgs(QByteArray aBA);
    Argument parseArg(QByteArray aArg);
    bool parsePost(QByteArray aBA);

    // ------------------------ properties ------------------------
private:
    QByteArray      m_functionName;
    QByteArray      m_className;
    QByteArrayList  m_namespaces;
    ArgumentList    m_arguments;
    QByteArray      m_returnType;
    QByteArray      m_anteOther;
    QByteArray      m_postOther;
    Flags           m_flags;

    // temporaries
    QByteArray         m_qFuncInfo;
    QByteArray         m_anteString;
    QByteArray         m_nameString;
    QByteArrayList     m_argumentStrings;
    QByteArray         m_postString;

    Q_PROPERTY(QByteArray functionName READ functionName CONSTANT FINAL)
    Q_PROPERTY(QByteArray className READ className CONSTANT FINAL)
    Q_PROPERTY(QByteArrayList namespaces READ namespaces CONSTANT FINAL)
    Q_PROPERTY(ArgumentList arguments READ arguments CONSTANT FINAL)
    Q_PROPERTY(QByteArray ante READ ante CONSTANT FINAL)
    Q_PROPERTY(QByteArray post READ post CONSTANT FINAL)
    Q_PROPERTY(Flags flags READ flags CONSTANT FINAL)
    Q_PROPERTY(QByteArray qFuncInfo READ qFuncInfo CONSTANT FINAL)
public:
    QByteArray functionName() const;
    QByteArray className() const;
    QByteArrayList namespaces() const;
    ArgumentList arguments() const;
    QByteArray ante() const;
    QByteArray post() const;
    Flags flags() const;
    QByteArray qFuncInfo() const;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(LogFunctionInfo::Flags);

// ------------------------ properties ------------------------

inline QByteArray LogFunctionInfo::functionName() const
{
    return m_functionName;
}

inline QByteArray LogFunctionInfo::className() const
{
    return m_className;
}

inline QByteArrayList LogFunctionInfo::namespaces() const
{
    return m_namespaces;
}

inline LogFunctionInfo::ArgumentList LogFunctionInfo::arguments() const
{
    return m_arguments;
}

inline QByteArray LogFunctionInfo::ante() const
{
    return m_anteOther;
}

inline QByteArray LogFunctionInfo::post() const
{
    return m_postOther;
}

inline LogFunctionInfo::Flags LogFunctionInfo::flags() const
{
    return m_flags;
}

inline QByteArray LogFunctionInfo::qFuncInfo() const
{
    return m_qFuncInfo;
}

