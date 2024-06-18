#pragma once
#include "ozLog.h"

#include <QObject>

#include "../ozCore/KeySeg.h"
#include "../ozCore/KeySegList.h"

class OZCORE_EXPORT FunctionInfo : public QObject
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
        VarArgs         = 0x00000100,

        PostConst       = 0x00000080,
        Override        = 0x00000040,
        PureVirtual     = 0x00000020,

    };
    Q_DECLARE_FLAGS(Flags, Flag);
    Q_FLAG(Flags);

    struct Argument
    {
        QString         string;
        AText          type;
        AText          name;
        AText           defalt;
        Flags           flags;
    };
    typedef QList<Argument> ArgumentList;

public: // ctors
    explicit FunctionInfo() {;}
    FunctionInfo(const QString &qFileInfo) { parse(qFileInfo); }

public: // non-const
    void parse(const QString &qFileInfo);

private:
    void splitStrings();
    void parseAnte();
    void parseNames();
    void parseArgs();
    void parsePost();

    // ------------------------ properties ------------------------
private:
    AText          m_functionName;
    AText          m_className;
    AText::List      m_namespaces;
    ArgumentList    m_arguments;
    QString         m_ante;
    QString         m_post;
    Flags           m_flags;

    // temporaries
    QString         m_qFuncInfo;
    QString         m_anteString;
    QString         m_nameString;
    QStringList     m_argumentStrings;
    QString         m_postString;

    Q_PROPERTY(AText functionName READ functionName CONSTANT FINAL)
    Q_PROPERTY(AText className READ className CONSTANT FINAL)
    Q_PROPERTY(AText::List namespaces READ namespaces CONSTANT FINAL)
    Q_PROPERTY(ArgumentList arguments READ arguments CONSTANT FINAL)
    Q_PROPERTY(QString ante READ ante CONSTANT FINAL)
    Q_PROPERTY(QString post READ post CONSTANT FINAL)
    Q_PROPERTY(Flags flags READ flags CONSTANT FINAL)
    Q_PROPERTY(QString qFuncInfo READ qFuncInfo CONSTANT FINAL)
public:
    KeySeg functionName() const;
    KeySeg className() const;
    AText::List namespaces() const;
    ArgumentList arguments() const;
    QString ante() const;
    QString post() const;
    Flags flags() const;
    QString qFuncInfo() const;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(FunctionInfo::Flags);

// ------------------------ properties ------------------------

inline KeySeg FunctionInfo::functionName() const
{
    return m_functionName;
}

inline KeySeg FunctionInfo::className() const
{
    return m_className;
}

inline AText::List FunctionInfo::namespaces() const
{
    return m_namespaces;
}

inline FunctionInfo::ArgumentList FunctionInfo::arguments() const
{
    return m_arguments;
}

inline QString FunctionInfo::ante() const
{
    return m_ante;
}

inline QString FunctionInfo::post() const
{
    return m_post;
}

inline FunctionInfo::Flags FunctionInfo::flags() const
{
    return m_flags;
}

inline QString FunctionInfo::qFuncInfo() const
{
    return m_qFuncInfo;
}

