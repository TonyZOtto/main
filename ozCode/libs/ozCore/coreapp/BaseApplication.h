#pragma once
#include "../ozCore.h"

#include <QObject>

#include <QStringList>
class QCoreApplication;
class QGuiApplication;
class QApplication;

#include "../filesys/FileInfo.h"
class ConsoleApplication;
class DesktopApplication;
class WidgetApplication;
class CommandLine;
class ApplicationSettings;

class OZCORE_EXPORT BaseApplication : public QObject
{
    Q_OBJECT
public:
    enum Class { $null = 0, Console, Gui, Widget, $max };
    Q_ENUM(Class);

protected: // ctors
    BaseApplication(int argc, char *argv[], const Class appClass);

public: // const
    const FileInfo exeFileInfo() const;

public: // pointers
    const QCoreApplication *coreApplication() const;
    const QGuiApplication *guiApplication() const;
    const QApplication * widgetApplication() const;
    CommandLine *commandLine() const;
    const ApplicationSettings * applicationSettings() const;

protected:
    void initialize();
    void configure() {;} // MUDTDO
    void start() {;} // MUSTDO
    void finish() {;} // MUSTDO
    void addOption();
    void addOptions() {;} // MUSTDO
    void processOptions();

signals:

private:
    ConsoleApplication * mpConsoleApplication=nullptr;
    DesktopApplication * mpDesktopApplication=nullptr;
    WidgetApplication * mpWidgetApplication=nullptr;
    QCoreApplication * mpQCoreApplication=nullptr;
    QGuiApplication * mpQGuiApplication=nullptr;
    QApplication * mpQApplication=nullptr;
    CommandLine * mpCommandLine=nullptr;
    const ApplicationSettings * cmpApplicationSettings=nullptr;
    const FileInfo cmExeFileInfo;
};

inline const FileInfo BaseApplication::exeFileInfo() const
{
    return cmExeFileInfo;
}

inline const QCoreApplication *BaseApplication::coreApplication() const
{
    Q_CHECK_PTR(mpQCoreApplication); return mpQCoreApplication;
}

inline CommandLine *BaseApplication::commandLine() const
{
    Q_CHECK_PTR(mpCommandLine); return mpCommandLine;
}
