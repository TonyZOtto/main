#include <ApplicationHelper.h>
#include <GridMainWindow.h>
#include <VersionInfo.h>
#include <WidgetApplication.h>

Q_GLOBAL_STATIC(ApplicationHelper, APPH)

#include "../../version.h"
#include "version.h"

int main(int argc, char *argv[])
{
    VersionInfo vi(VER_MAJOR, VER_MINOR, VER_RELEASE,
                   VER_BRANCH, VER_BUILD, VER_BRANCHNAME,
                   VER_APPNAME, VER_ORGNAME, VER_APPDESC);
    vi.copyright(EIRVER_COPYRIGHT);
    vi.product(EIRVER_PRODUCT);
    WidgetApplication a(argc, argv);
    APPH->set(&a);
    APPH->set(vi);
    GridMainWindow w(&a);
    w.setWindowTitle(vi.toString(VersionInfo::WithLowerVDot
                                 | VersionInfo::WithDotted));
    w.showMaximized();
    return a.exec();
}
