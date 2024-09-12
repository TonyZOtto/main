#include "EvalApplication.h"

#include <ApplicationHelper.h>
#include <VersionInfo.h>

#include "../../version.h"
#include "version.h"

EvalApplication::EvalApplication(int &argc, char **argv)
    : WidgetApplication(argc, argv)
{
    qInfo() << Q_FUNC_INFO << Qt::hex << APPH;
    setObjectName("EvalApplication");
    APPH->set(this);
}

void EvalApplication::initialize()
{
    qInfo() << Q_FUNC_INFO;
    VersionInfo vi(VER_MAJOR, VER_MINOR, VER_RELEASE,
                   VER_BRANCH, VER_BUILD, VER_BRANCHNAME,
                   VER_APPNAME, EIRVER_ORGNAME, VER_APPDESC);
    vi.copyright(EIRVER_COPYRIGHT);
    vi.product(EIRVER_PRODUCT);
    APPH->set(vi);
    emit initialized();
}

void EvalApplication::configure()
{
    qInfo() << Q_FUNC_INFO;
    emit configured();
}

void EvalApplication::setup()
{
    qInfo() << Q_FUNC_INFO;
    emit setuped();
}
