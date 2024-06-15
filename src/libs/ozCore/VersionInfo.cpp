#include "VersionInfo.h"

#include <QChar>

VersionInfo::VersionInfo() { clear(); }

VersionInfo::VersionInfo(const BYTE maj, const WORD min, const BYTE rls, const WORD bch,
                         const WORD bld, const char *bnm, const char *app, const char *org)
{
    set(maj, min, rls, bch, bld, bnm, app, org);
    // TODO company, legal
    // TODO setApp()
}

bool VersionInfo::isNull() const
{
    return 0 == major() && 0 == minor();
}

QString VersionInfo::toString(const StringOptions opts) const
{
    QString result;
    if (opts.testFlag(Dotted))
    {
        result = dottedString();
    }
    else
    {
        result = QString("%1.%2%3").arg(major()).arg(minor(), 2, QChar('0'))
                          .arg(releaseString(opts));
        if (branch() && ! opts.testFlag(WithoutBranch))
        {
            result += QString("+%1").arg(branch(), 4, QChar('0'));
            if (opts.testFlag(WithBranchName))
                result += "-" + branchname();
        }
    }
    if (opts.testFlag(WithDotted))
        result += QString(" [%1]").arg(dottedString());
    if (opts.testFlag(WithDWord))
        result += QString(" [%1]").arg(toDWord(), 8, 16, QChar('0'));
    if (opts.testFlag(WithQWord))
        result += QString(" [%1]").arg(toQWord(), 16, 16, QChar('0'));
    return result;
}

DWORD VersionInfo::toDWord() const
{
    static union
    {
        DWORD       uDWord;
        struct
        {
            BYTE    sMajor;
            WORD    sMinor;
            BYTE    sRelease;
        };
    } stUnion;
    stUnion.sMajor = major(), stUnion.sMinor = minor(), stUnion.sRelease = release();
    return stUnion.uDWord;
}

QWORD VersionInfo::toQWord() const
{
    static union
    {
        QWORD       uQWord;
        struct
        {
            DWORD   sMajMin;
            DWORD   sRelease;
            DWORD   sBranch;
            DWORD   sBuild;
        };
    } stUnion;
    stUnion.sMajMin = major() * 1000 + minor(), stUnion.sRelease = release();
    stUnion.sBranch = branch(), stUnion.sBuild = build();
    return stUnion.uQWord;
}

void VersionInfo::clear()
{
    m_major = m_minor = m_release = m_branch = m_build = 0;
    m_branchname.clear(), m_appname.clear(), m_orgname.clear();
    m_company.clear(), m_legal.clear();
    m_qtVersion = QVersionNumber();
    m_windowsVersion = WindowsVersion{0,0,0,0};
    m_linuxVersion = LinuxVersion{0,0,0};
}

void VersionInfo::set(const BYTE maj, const WORD min, const BYTE rls, const WORD bch,
                      const WORD bld, const char *bnm, const char *app, const char *org)
{
    m_major = maj, m_minor = min, m_release = rls, m_branch = bch, m_build = bld;
    m_branchname = AText(bnm), m_appname = AText(app), m_orgname = AText(org);
    m_linuxVersion = LinuxVersion{maj, min, rls};
    setQt();
    setWindows();
}

// =============== Properties ===================
BYTE VersionInfo::major() const
{
    return m_major;
}

WORD VersionInfo::minor() const
{
    return m_minor;
}

BYTE VersionInfo::release() const
{
    return m_release;
}

WORD VersionInfo::branch() const
{
    return m_branch;
}

WORD VersionInfo::build() const
{
    return m_build;
}

AText VersionInfo::branchname() const
{
    return m_branchname;
}

AText VersionInfo::appname() const
{
    return m_appname;
}

AText VersionInfo::orgname() const
{
    return m_orgname;
}

UText VersionInfo::company() const
{
    return m_company;
}

UText VersionInfo::legal() const
{
    return m_legal;
}

QString VersionInfo::dottedString() const
{
    return QString("%1.%2.%3.%4").arg(1000 * major() + minor(), 4, QChar('0'))
                 .arg(release()).arg(branch()).arg(build());

}

QString VersionInfo::releaseString(const StringOptions opts) const
{
    QString result= QString(".%1").arg(release(), 3, QChar('0'));

    const unsigned cRelease = release();
    if (0 == cRelease || (cRelease >= 0xF0 && opts.testFlag(WithoutFinal)))  result.clear();
    else if (cRelease > 1 && cRelease <=26) result = QString(QChar((BYTE)('A') + release() - 1));
    else if (cRelease >= 0xA0 && cRelease <= 0xAF) result = namedRelease("Alpha", opts);
    else if (cRelease >= 0xB0 && cRelease <= 0xBF) result = namedRelease("Beta", opts);
    else if (cRelease >= 0xC0 && cRelease <= 0xCF) result = namedRelease("RC", opts);
    else if (cRelease >= 0xF0 && cRelease <= 0xFF) result = namedRelease("Final", opts);


    return result;
}

QString VersionInfo::namedRelease(const char *name, const StringOptions opts) const
{
    QString result(name);
    if ( ! opts.testFlag(WithoutReleaseNumber))
        result += QString::number(release() & 0x0F);
    return result;
}

void VersionInfo::setQt()
{
    IntList tIntList;
    tIntList << major() << minor() << release() << branch() << build();
    m_qtVersion = QVersionNumber(tIntList);
}

void VersionInfo::setWindows()
{
    m_windowsVersion = WindowsVersion{SWORD(major() * 1000 + minor()), release(), SWORD(branch()), SWORD(build())};
}

QVersionNumber VersionInfo::qtVersion() const
{
    return m_qtVersion;
}

VersionInfo::WindowsVersion VersionInfo::windowsVersion() const
{
    return m_windowsVersion;
}

VersionInfo::LinuxVersion VersionInfo::linuxVersion() const
{
    return m_linuxVersion;
}
