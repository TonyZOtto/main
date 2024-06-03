#include "../../version.h"
#include "version.h"
#include "SandboxMain.h"

#include <QApplication>

#include <VersionInfo.h>

int main(int argc, char *argv[])
{
    VersionInfo vi()
    QApplication a(argc, argv);
    SandboxMain w;
    w.show();
    return a.exec();
}
