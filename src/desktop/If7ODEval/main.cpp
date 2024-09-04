#include <QTimer>

#include <ApplicationHelper.h>
#include <VersionInfo.h>

#include "EvalApplication.h"
#include "EvalMainWindow.h"

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
    EvalApplication a(argc, argv);
    APPH->set(&a);
    APPH->set(vi);
    EvalMainWindow w(&a);
    w.setWindowTitle(vi.toString(VersionInfo::WithLowerVDot
                                 | VersionInfo::WithDotted));
    QTimer::singleShot(500, &a, &EvalApplication::initialize);
    return a.exec();
}
