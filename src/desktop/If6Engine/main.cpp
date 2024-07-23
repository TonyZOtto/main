#include "EngineApplication.h"
#include "EngineMainWindow.h"

#include "../../libs/ozCore/VersionInfo.h"
#include "../../version.h"
#include "version.h"

int main(int argc, char *argv[])
{
    VersionInfo vi(VER_MAJOR, VER_MINOR, VER_RELEASE,
                   VER_BRANCH, VER_BUILD, VER_BRANCHNAME,
                   VER_APPNAME, VER_ORGNAME);
    vi.copyright(VER_COPYRIGHT);
    vi.legal(VER_LEGAL);
    vi.product(EIRVER_PRODUCT);
    EngineApplication a(argc, argv);
    vi.set(&a);
    a.showMainWindow();
    return a.exec();
}
