#pragma once
#include "ozExe.h"

#include <QObject>
class CommandLine;
class AppSettings;
class QApplication;
class QCoreApplication;
class QGuiApplication;

#include <VersionInfo.h>

class OZEXE_EXPORT ApplicationHelper : public QObject
{
    Q_OBJECT
public:
    enum Type { $null = 0, App, Core, Gui, $max };
    Q_ENUM(Type)

public:
    explicit ApplicationHelper(QApplication *parent);
    explicit ApplicationHelper(QCoreApplication *parent);
    explicit ApplicationHelper(QGuiApplication *parent);

public slots:

signals:

public: // const
    Type type() const;

public: // non-const
    void set(const VersionInfo vi);

public: // pointers
    QCoreApplication * core();
    QGuiApplication * gui();
    QApplication * app();
    CommandLine * commandLine();
    AppSettings * appSettings();

private:
    QApplication * mpQApplication=nullptr;
    QCoreApplication * mpQCoreApplication=nullptr;
    QGuiApplication * mpQGuiApplication=nullptr;
    CommandLine * mpCommandLine=nullptr;
    AppSettings * mpAppSettings=nullptr;
    VersionInfo mVersionInfo;
    Type mType=$null;
};

inline ApplicationHelper::Type ApplicationHelper::type() const { return mType; }
inline CommandLine *ApplicationHelper::commandLine() { Q_CHECK_PTR(mpCommandLine);  return mpCommandLine; }
inline AppSettings *ApplicationHelper::appSettings() { Q_CHECK_PTR(mpAppSettings);  return mpAppSettings; }


