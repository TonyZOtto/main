#include "../../version.h"
#include "version.h"
#include "SandboxApplication.h"
#include "SandboxMainWindow.h"

#include <QTimer>

#include <VersionInfo.h>

int main(int argc, char *argv[])
{
    VersionInfo vi(VER_MAJOR, VER_MINOR, VER_RELEASE, VER_BRANCH, VER_BUILD,
                   VER_BRANCHNAME, VER_APPNAME, VER_ORGNAME, VER_APPDESC);
    SandboxApplication a(argc, argv);
    a.setOrganizationName(VER_ORGNAME);
    a.setApplicationName(VER_APPNAME);
    a.setApplicationVersion(VER_STRING);
    SandboxMainWindow w(&a);
    a.set(&w);
    QTimer::singleShot(200, &a, &SandboxApplication::initialize);
    return a.exec();
}

