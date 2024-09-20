#include <QTimer>

#include <ApplicationHelper.h>
#include <VersionInfo.h>

#include "EvalApplication.h"
#include "EvalMainWindow.h"

#include "../../version.h"
#include "version.h"

int main(int argc, char *argv[])
{
    VersionInfo vi(VER_MAJOR, VER_MINOR, VER_RELEASE,
                   VER_BRANCH, VER_BUILD, VER_BRANCHNAME,
                   VER_APPNAME, EIRVER_ORGNAME, VER_APPDESC);
    vi.copyright(EIRVER_COPYRIGHT);
    vi.product(EIRVER_PRODUCT);
    qInfo() << Q_FUNC_INFO << *argv[0] << vi.toString();
    qDebug() << Q_FUNC_INFO << ">>>EvalApplication ctor";
    EvalApplication a(argc, argv);
    vi.updateApp(&a);
    qDebug() << Q_FUNC_INFO << "<<<EvalApplication ctor";
    qDebug() << Q_FUNC_INFO << ">>>EvalMainWindow ctor";
    EvalMainWindow w(&a);
    APPH->set(vi);
    APPH->set(&a);
    APPH->set(&w);
    w.setWindowTitle(vi.toString(VersionInfo::WithLowerVDot));
    qDebug() << Q_FUNC_INFO << "<<<EvalMainWindow ctor";
    qDebug() << Q_FUNC_INFO << "500ms-->EvalApplication::initialize()";
    QTimer::singleShot(500, &a, &EvalApplication::initialize);
    qDebug() << Q_FUNC_INFO << ">>>EvalApplication exec()";
    return a.exec();
}
