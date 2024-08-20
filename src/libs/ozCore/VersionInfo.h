#pragma once
#include "ozCore.h"

#include <QSharedDataPointer>

#include <QVersionNumber>
class QCoreApplication;

#include "AText.h"
#include "Types.h"

class VersionInfoData;

class OZCORE_EXPORT VersionInfo
{
public: // types
    struct WindowsVersion   { SWORD     word[4]; };
    struct LinuxVersion     { UINT      uint[3]; };
    enum StringOption
    {
        $null                   = 0,
        Dotted                  = 0x00000001,
        WithLowerVDot           = 0x00000002,
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
    VersionInfo(const BYTE maj, const WORD min, const BYTE rls,
              const WORD bch, const WORD bld, const char * bnm,
              const char * app, const char * org, const char * desc);

public: // const
    BYTE major() const;
    WORD minor() const;        // 0..999
    BYTE release() const;      // _A..Z,AA..WW,X0..9A..X,0xA?,0xB?,0xC?,0xF?
    WORD branch() const;       // 0001..4999 Issue, 5001..5999 Customer
    WORD build() const;        // ++at Develop,Current,Release,Main
    AText branchname() const;
    AText appname() const;
    AText appdesc() const;
    AText orgname() const;
    AText product() const;
    UText company() const;
    UText copyright() const;
    UText legal() const;
    QVersionNumber  qtVersion() const;
    WindowsVersion  windowsVersion() const;
    LinuxVersion    linuxVersion() const;
    bool isNull() const;
    QString toString(const StringOptions opts=$null) const;
    DWORD toDWord() const;
    QWORD toQWord() const;
    bool updateApp(QCoreApplication * pCoreApp) const;


public: // non-const
    void clear();
    void set(const VersionInfo &vi);
    void set(const BYTE maj, const WORD min, const BYTE rls,
             const WORD bch, const WORD bld, const char * bnm,
             const char * app, const char * org,
             const char * desc);
    void company(const UText &co);
    void copyright(const UText &co);
    void legal(const UText &leg);
    void product(const AText &prod);

private:
    QString dottedString() const;
    QString releaseString(const StringOptions opts) const;
    QString namedRelease(const char * name, const StringOptions opts) const;
    void setQt();
    void setWindows();


public: // builtin
    VersionInfo();
    VersionInfo(const VersionInfo &);
    VersionInfo &operator=(const VersionInfo &);
    ~VersionInfo();

private:
    QSharedDataPointer<VersionInfoData> data;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(VersionInfo::StringOptions)

