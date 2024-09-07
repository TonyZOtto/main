#include <QTimer>

#include <ApplicationHelper.h>
#include <VersionInfo.h>

#include "EvalApplication.h"
#include "EvalMainWindow.h"

//Q_GLOBAL_STATIC(ApplicationHelper, APPH)

#include "../../version.h"
#include "version.h"

int main(int argc, char *argv[])
{
    VersionInfo vi(VER_MAJOR, VER_MINOR, VER_RELEASE,
                   VER_BRANCH, VER_BUILD, VER_BRANCHNAME,
                   VER_APPNAME, EIRVER_ORGNAME, VER_APPDESC);
    vi.copyright(EIRVER_COPYRIGHT);
    vi.product(EIRVER_PRODUCT);
    qInfo() << Q_FUNC_INFO << vi.toString();
    qDebug() << Q_FUNC_INFO << ">>>EvalApplication ctor";
    EvalApplication a(argc, argv);
    a.setOrganizationName(vi.orgname());
    a.setApplicationName(vi.appname());
    a.setApplicationVersion(vi.toString());
    qDebug() << Q_FUNC_INFO << "<<<EvalApplication ctor";
    qDebug() << Q_FUNC_INFO << ">>>EvalMainWindow ctor";
    EvalMainWindow w(&a);
    qDebug() << Q_FUNC_INFO << "<<<EvalMainWindow ctor";
    w.setWindowTitle(vi.toString(VersionInfo::WithLowerVDot
                                 | VersionInfo::WithDotted));
//    qDebug() << Q_FUNC_INFO << ">>>ApplicationHelper ctor";
//    APPH->set(&a);
  //  APPH->set(&w);
    //APPH->set(vi);
//    qDebug() << Q_FUNC_INFO << "<<<ApplicationHelper ctor";
    qDebug() << Q_FUNC_INFO << "-->EvalApplication::initialize()";
    QTimer::singleShot(500, &a, &EvalApplication::initialize);
    qDebug() << Q_FUNC_INFO << ">>>EvalApplication exec()";
    return a.exec();
}
