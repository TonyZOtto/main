#pragma once
#include "ozExe.h"

#include <QObject>

#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QList>
#include <QStringList>

#include "KeyMap.h"
#include "SettingsName.h"
class FileInfo;

class OZEXE_EXPORT CommandLine : public QObject
{
    Q_OBJECT
public: // types

public: // ctors
    explicit CommandLine();
    CommandLine(int argc, char *argv[]);

public: // const
    const QStringList rawArgumentList() const;
    const QStringList positionalArguments() const;
    const SettingsName settingsName() const;
    const SettingsName::List settingsNameList() const;
    const KeyMap settingValues() const;

public: // non-const
    void process();

private: // non-const
    void processIncludeFile(const QString atsArg);
    void processSettingValue(const QString dlrArg);
    void processSettingsName(const QString pctArg);

private: // static
    static QStringList parseRawArguments(int argc, char *argv[]);

signals:
    void processing(const QString &arg);
    void optionSet(const QCommandLineOption &opt);
    void including(const FileInfo &fi);
    void value(const Key &key, const QVariant &var);
    void settingsName(const SettingsName &sn);


private:
    const QString cmExeFileName;
    const QStringList cmRawArgumentList;
    QStringList mCommandArguments;
    QStringList mPositionalArguments;
    SettingsName::List mSettingsNameList;
    KeyMap mSettingValuesMap;
};

inline const QStringList CommandLine::rawArgumentList() const  { return cmRawArgumentList; }
inline const SettingsName::List CommandLine::settingsNameList() const { return mSettingsNameList; }
