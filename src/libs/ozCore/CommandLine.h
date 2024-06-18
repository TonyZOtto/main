#pragma once
#include "ozCore.h"

#include <QObject>

#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QList>


#include "KeyMap.h"
#include "SettingsName.h"
class BaseApplication;
class QQFileInfo;

class OZCORE_EXPORT CommandLine : public QObject
{
    Q_OBJECT
public: // types
    typedef QList<QCommandLineOption> OptionList;

public: // ctors
    explicit CommandLine(int argc, char *argv[], BaseApplication *parent = nullptr);

public: // const
    const QCommandLineOption option(const QString &name) const;
    const OptionList options() const;
    const QStringList rawArgumentList() const;
    const QStringList positionalArguments() const;
    const SettingsName::List settingsNameList() const;
    const KeyMap settingValues() const;

public: // non-const
    void addOption(const QCommandLineOption &opt);
    void addOptions(const OptionList &opts);
    void set(const OptionList &opts);
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
    void including(const QQFileInfo &fi);
    void value(const Key &key, const QVariant &var);
    void settingsName(const SettingsName &sn);


private:
    const QString cmExeFileName;
    const QStringList cmRawArgumentList;
    OptionList mOptionList;
    QStringList mCommandArguments;
    QStringList mPositionalArguments;
    SettingsName::List mSettingsNameList;
    KeyMap mSettingValuesMap;
};


inline const QStringList CommandLine::rawArgumentList() const
{
    return cmRawArgumentList;
}

inline const SettingsName::List CommandLine::settingsNameList() const
{
    return mSettingsNameList;
}
