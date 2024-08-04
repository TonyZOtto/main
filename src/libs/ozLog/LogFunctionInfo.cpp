#include "LogFunctionInfo.h"

#include <QByteArray>
#include <QByteArrayList>
#include <QChar>
#include <QString>
#include <QStringList>

LogFunctionInfo::LogFunctionInfo() {;}

LogFunctionInfo::LogFunctionInfo(const QByteArray &qFileInfo)
{
    parse(qFileInfo);
}

bool LogFunctionInfo::parse(const QByteArray &aQFuncInfo)
{
    m_qFuncInfo = aQFuncInfo;
    return splitStrings();
}

bool LogFunctionInfo::splitStrings()
{
    bool result = true;
    const QByteArray cFuncInfo = qFuncInfo();
    const int cLParenIndex = cFuncInfo.indexOf('(');
    if (cLParenIndex < 3) return false;
    const QByteArray cLeftSide = cFuncInfo.left(cLParenIndex - 1);
    const QByteArray cRightSide = cFuncInfo.mid(cLParenIndex + 1);
    const int cLeftLastSpaceIndex = cLeftSide.lastIndexOf(' ');
    if (cLeftLastSpaceIndex < 3) return false;
    result &= parseNames(cLeftSide.mid(cLeftLastSpaceIndex + 1));
    result &= parseAnte(cLeftSide.left(cLeftLastSpaceIndex - 1));
    const int cRightLastRParenIndex = cRightSide.lastIndexOf(')');
    if (cRightLastRParenIndex < 0) return false;
    if (cRightLastRParenIndex)
        result &= parseArgs(cRightSide.left(cRightLastRParenIndex));
    else
        m_flags.setFlag(VoidArguments);
    if (cRightLastRParenIndex > 1)
        result &= parsePost(cRightSide.mid(cRightLastRParenIndex + 1));
    return result;
}

bool LogFunctionInfo::parseAnte(const QByteArray &aBA)
{
    bool result = true;
    m_anteString = aBA;
    QByteArrayList tAnteWords = aBA.simplified().split(' ');
    if (tAnteWords.contains("const"))
    {
        m_flags.setFlag(AnteConst);
        tAnteWords.removeAll("const");
    }
    if (tAnteWords.contains("virtual"))
    {
        m_flags.setFlag(Virtual);
        tAnteWords.removeAll("virtual");
    }
    if (tAnteWords.contains("void"))
    {
        m_flags.setFlag(VoidReturn);
        tAnteWords.removeAll("void");
    }
    if (tAnteWords.count() > 1)
        m_returnType = tAnteWords.takeFirst();
    m_anteOther = tAnteWords.join('~');
    return result;
}

bool LogFunctionInfo::parseNames(const QByteArray &aBA)
{
    m_nameString = aBA;
    const QString tNameString(aBA);
    QStringList tNameSWords = tNameString.simplified().split("::");
    QByteArrayList tNameWords;
    foreach (const QString cString, tNameSWords)
        tNameWords << cString.toLocal8Bit();
    if (tNameWords.isEmpty())
        return false;
    m_functionName = tNameWords.takeLast();
    if (tNameWords.count() > 1)
        m_className = tNameWords.takeLast();
    m_namespaces = tNameWords;
    return true;
}

bool LogFunctionInfo::parseArgs(QByteArray aBA)
{
    bool result = true;
    if (aBA.endsWith(" ..."))
    {
        m_flags.setFlag(VarArgs);
        aBA.chop(4);
    }
    const QByteArrayList cArgsList = aBA.split(',');
    m_argumentStrings = cArgsList;
    foreach (const QByteArray cArg, cArgsList)
        m_arguments.append(parseArg(cArg));
    return result;
}

LogFunctionInfo::Argument LogFunctionInfo::parseArg(QByteArray aArg)
{
    Argument result;
    result.string = aArg;

    // find and remove = specified arg default
    const int cIndexEquals = aArg.indexOf('=');
    if (cIndexEquals > 1)
    {
        result.defalt = aArg.mid(cIndexEquals + 1);
        aArg = aArg.left(cIndexEquals - 1);
    }
    QByteArrayList tArgWords = aArg.simplified().split(' ');

    // find and remove const argument specifier
    if (tArgWords.contains("const"))
    {
        tArgWords.removeAll("const");
        result.flags.setFlag(ConstArgument);
    }
    // argument name
    if (tArgWords.count() > 2)
    {
        result.name = tArgWords.last();
        tArgWords.removeLast();
    }
    // argument type
    result.type = tArgWords.join("?");
    return result;
}

bool LogFunctionInfo::parsePost(QByteArray aBA)
{
    bool result = true;
    m_postString = aBA;
    if (aBA.contains("=") && aBA.contains("0"))
    {
        m_flags.setFlag(PureVirtual);
        aBA.replace('=', ' '), aBA.replace('0', ' ');
    }
    QByteArrayList tPostWords = aBA.simplified().split(' ');
    if (tPostWords.contains("constexpr"))
    {
        m_flags.setFlag(PostConstExpr);
        tPostWords.removeAll("constexpr");
    }
    if (tPostWords.contains("const"))
    {
        m_flags.setFlag(PostConst);
        tPostWords.removeAll("const");
    }
    if (tPostWords.contains("override"))
    {
        m_flags.setFlag(Override);
        tPostWords.removeAll("override");
    }
    m_postOther = tPostWords.join('~');
    return result;
}
