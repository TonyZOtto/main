#include "EngineApplication.h"
#include "EngineMainWindow.h"

#include "../../libs/ozCore/VersionInfo.h"
#include "../../version.h"
#include "version.h"

int main(int argc, char *argv[])
{
    VersionInfo vi(VER_MAJOR, VER_MINOR, VER_RELEASE, VER_BRANCH,
                   VER_BRANCHNAME, VER_APPNAME, VER_ORGNAME);
    vi.legal(VER_LEGAL);
    EngineApplication a(argc, argv);
    EngineMainWindow w;
    vi.
    a.set(&w);
    w.show();
    return a.exec();
}
