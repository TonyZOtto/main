#include "../../version.h"
#include "version.h"
#include "SandboxMain.h"

#include <QApplication>

#include <ident/VersionInfo.h>

int main(int argc, char *argv[])
{
    VersionInfo vi(VER_MAJOR, VER_MINOR, VER_RELEASE, VER_BRANCH, VER_BUILD,
                   VER_BRANCHNAME, VER_APPNAME, VER_ORGNAME);
    QApplication a(argc, argv);
    a.setOrganizationName(VER_ORGNAME);
    a.setApplicationName(VER_APPNAME);
    a.setApplicationVersion(VER_STRING);
    SandboxMain w;
    w.initialize();
    w.configure();
    w.setup();
    w.objconnect();
    w.start();
    return a.exec();
}
