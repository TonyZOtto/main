#include "StatusConsoleApplication.h"

#include <QtDebug>
#include <QTimer>

#include <QCoreApplication>
#include <QDateTime>
#include <QLibrary>
#include <QLibraryInfo>
#include <QTimeZone>
#include <QVersionNumber>

#include <BaseApplication.h>
#include <ConsoleStdIO.h>
#include <FileInfo.h>
#include <Types.h>

StatusConsoleApplication::StatusConsoleApplication(int argc, char *argv[])
    : ConsoleApplication(argc, argv)
{
    setObjectName("StatusConsole:" + QCoreApplication::applicationName());
    qInfo() << Q_FUNC_INFO << objectName(); // << QCoreApplication::arguments();
    io()->writeline(QString("Hello %1").arg(QCoreApplication::applicationName()));
}

void StatusConsoleApplication::initialize()
{

}

void StatusConsoleApplication::configure()
{

}

void StatusConsoleApplication::start()
{
    qInfo() << Q_FUNC_INFO << objectName();
    mLibraryNames << "ozCore";
    const QDateTime cDT = QDateTime::currentDateTime(QTimeZone::LocalTime);
    const QTimeZone cTZ = QTimeZone(QTimeZone::LocalTime);
    io()->writeline(QString("***Status as of: %1 %2 local")
                      .arg(cDT.toString("ddd yyyy/MM/dd hh:mm:ss"),
                           cTZ.abbreviation(cDT)));
    QTimer::singleShot(50, this, &StatusConsoleApplication::exeInfo);
}

void StatusConsoleApplication::exeInfo()
{
    qInfo() << Q_FUNC_INFO << objectName() << QCoreApplication::arguments();
    io()->writeline("===Executable Information===");
    const QStringList cExeInfoStrings = base()->exeFileInfo().infoStrings();
    io()->writelines(cExeInfoStrings, "   ");

    const QStringList cArgs = qApp->arguments();
    const int nArgs = cArgs.count();
    io()->writeline(QString("---Raw Command Line Argument List: %1---").arg(nArgs - 1));
    for (Index ix = 1; ix < nArgs; ++ix)
        io()->writeline(QString("   %1. %2").arg(ix).arg(cArgs[ix]));
    QTimer::singleShot(50, this, &StatusConsoleApplication::qtInfo);
}

void StatusConsoleApplication::qtInfo()
{
    QVersionNumber tQtVerNum = QLibraryInfo::version();
    io()->writeline("===Qt Information===");
    io()->writeline(QString("   Version:     %1").arg(tQtVerNum.toString()));
    io()->writeline(QString("   Build:       %1 %2")
                        .arg(QLibraryInfo::isSharedBuild() ? "Dynamic" : "Static")
                        .arg(QLibraryInfo::isDebugBuild() ? "Debug" : "Release"));
    io()->writeline("---Paths---");
    io()->writeline(QString("   Prefix:      %1").arg(QLibraryInfo::path(QLibraryInfo::PrefixPath)));
    io()->writeline(QString("   Headers:     %1").arg(QLibraryInfo::path(QLibraryInfo::HeadersPath)));
    io()->writeline(QString("   Libraries:   %1").arg(QLibraryInfo::path(QLibraryInfo::LibrariesPath)));
    io()->writeline(QString("   Binaries:    %1").arg(QLibraryInfo::path(QLibraryInfo::BinariesPath)));
    io()->writeline(QString("   Plugins:     %1").arg(QLibraryInfo::path(QLibraryInfo::PluginsPath)));

    QTimer::singleShot(50, this, &StatusConsoleApplication::libInfo);
}

void StatusConsoleApplication::libInfo()
{
    qInfo() << Q_FUNC_INFO << objectName();
    io()->writeline("===Library Information===");
    foreach (const QString tLibName, mLibraryNames)
    {
        QLibrary tLibrary(tLibName);
        io()->writeline(QString("   %1: %2Loaded %3").arg(tLibName)
                            .arg(tLibrary.isLoaded() ? "" : "NOT ")
                            .arg(tLibrary.errorString()));
    }
    QTimer::singleShot(50, this, &StatusConsoleApplication::finish);

}

void StatusConsoleApplication::finish()
{
    const QDateTime cDT = QDateTime::currentDateTime(QTimeZone::LocalTime);
    const QTimeZone cTZ = QTimeZone(QTimeZone::LocalTime);
    io()->writeline(QString("***Complete as of: %1 %2 local")
                        .arg(cDT.toString("ddd yyyy/MM/dd hh:mm:ss"),
                             cTZ.abbreviation(cDT)));
    exit(0);
}
