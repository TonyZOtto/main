#include <QCoreApplication>
#include <QDateTime>
#include <QStringList>
#include <QTimer>

#include "StatusConsoleApplication.h"
#include "../../version.h"

int main(int argc, char *argv[])
{
    StatusConsoleApplication a(argc, argv);
    QCoreApplication::setApplicationName("ozStatus");
    QCoreApplication::setApplicationVersion(VER_STRING);
    QCoreApplication::setOrganizationName(VER_ORGNAME);
//    qInfo() << QCoreApplication::applicationFilePath()
  //          << QDateTime::currentDateTime().toString();
    //qInfo() << argc << QString(argv[0]) << QString(argv[1]);
    QTimer::singleShot(500, &a, &StatusConsoleApplication::start);
    return QCoreApplication::exec();
}
