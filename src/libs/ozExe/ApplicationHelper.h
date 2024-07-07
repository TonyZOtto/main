#pragma once

#include <QObject>
class CommandLine;
class MainSettings;
class QApplication;
class QCoreApplication;
class QGuiApplication;

#include <VersionInfo.h>

class ApplicationHelper : public QObject
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

private:
    QApplication * mpQApplication=nullptr;
    QCoreApplication * mpQCoreApplication=nullptr;
    QGuiApplication * mpQGuiApplication=nullptr;
    CommandLine * mpCommandLine=nullptr;
    MainSettings * mpMainSettings=nullptr;
    VersionInfo mVersionInfo;
    Type mType=$null;
};


