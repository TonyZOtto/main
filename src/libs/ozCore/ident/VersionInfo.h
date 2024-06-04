#pragma once
#include "ozCore.h"

#include <QObject>
#include <QString>
#include <QVersionNumber>

#include "../AText.h"
#include "../Types.h"

class OZCORE_EXPORT VersionInfo : public QObject
{
    Q_GADGET
public: // types
    struct WindowsVersion   { SWORD     word[4]; };
    struct LinuxVersion     { UINT      uint[3]; };
    enum StringOption
    {
        $null                   = 0,
        Dotted                  = 0x00000001,
        WithDotted              = 0x01000000,
        WithDWord               = 0x02000000,
        WithQWord               = 0x04000000,
        WithBranchName          = 0x08000000,
        WithoutFinal            = 0x20000000,
        WithoutReleaseNumber    = 0x40000000,
        WithoutBranch           = 0x80000000,
    };
    Q_DECLARE_FLAGS(StringOptions, StringOption);
    Q_FLAGS(StringOptions);

public: // ctors
    explicit VersionInfo();
    VersionInfo(const BYTE maj, const WORD min, const BYTE rls, const WORD bch,
                const WORD bld, const char * bnm, const char * app, const char * org);

public: // const
    bool isNull() const;
    QString toString(const StringOptions opts=$null) const;
    DWORD toDWord() const;
    QWORD toQWord() const;

public: // non-const
    void clear();
    void set(const BYTE maj, const WORD min, const BYTE rls, const WORD bch,
             const WORD bld, const char * bnm, const char * app, const char * org);
    void company(const UText &co);
    void legal(const UText &leg);

private:
    QString dottedString() const;
    QString releaseString(const StringOptions opts) const;
    QString namedRelease(const char * name, const StringOptions opts) const;
    void setQt();
    void setWindows();

signals:

public: // =============== Properties ===================
    BYTE major() const;
    WORD minor() const;
    BYTE release() const;
    WORD branch() const;
    WORD build() const;
    AText branchname() const;
    AText appname() const;
    AText orgname() const;
    UText company() const;
    UText legal() const;
    QVersionNumber qtVersion() const;
    WindowsVersion windowsVersion() const;
    LinuxVersion linuxVersion() const;

private:
    BYTE            m_major;        // 0..99
    WORD            m_minor;        // 0..999
    BYTE            m_release;      // _A..Z,AA..WW,X0..9A..X,0xA?,0xB?,0xC?,0xF?
    WORD            m_branch;       // 0001..4999 Issue, 5001..5999 Customer
    WORD            m_build;        // ++at Develop,Current,Release,Main
    AText           m_branchname;
    AText           m_appname;
    AText           m_orgname;
    UText           m_company;
    UText           m_legal;
    QVersionNumber  m_qtVersion;
    WindowsVersion  m_windowsVersion;
    LinuxVersion    m_linuxVersion;
    Q_PROPERTY(BYTE major READ major CONSTANT FINAL)
    Q_PROPERTY(WORD minor READ minor CONSTANT FINAL)
    Q_PROPERTY(BYTE release READ release CONSTANT FINAL)
    Q_PROPERTY(WORD branch READ branch CONSTANT FINAL)
    Q_PROPERTY(WORD build READ build CONSTANT FINAL)
    Q_PROPERTY(AText branchname READ branchname CONSTANT FINAL)
    Q_PROPERTY(AText appname READ appname CONSTANT FINAL)
    Q_PROPERTY(AText orgname READ orgname CONSTANT FINAL)
    Q_PROPERTY(UText company READ company CONSTANT FINAL)
    Q_PROPERTY(UText legal READ legal CONSTANT FINAL)
    Q_PROPERTY(QVersionNumber qtVersion READ qtVersion CONSTANT FINAL)
    Q_PROPERTY(WindowsVersion windowsVersion READ windowsVersion CONSTANT FINAL)
};

Q_DECLARE_OPERATORS_FOR_FLAGS(VersionInfo::StringOptions);

