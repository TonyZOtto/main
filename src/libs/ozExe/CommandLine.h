#pragma once
#include "ozExe.h"

#include <QObject>

#include <QFileInfo>
#include <QList>
#include <QStringList>

#include <KeyMap.h>

#include "SettingsName.h"
class ApplicationHelper;

class OZEXE_EXPORT CommandLine : public QObject
{
    Q_OBJECT
public: // types

public: // ctors
    explicit CommandLine(ApplicationHelper * parent);
    CommandLine(const QStringList aRawArgList,
                         ApplicationHelper * parent);
    CommandLine(int argc, char *argv[],
                ApplicationHelper *parent);

public slots:
    void process();

signals:
    void processing(const QString &arg);
    void including(const QFileInfo &fi);
    void value(const Key &key, const QVariant &var);
    void settingsName(const SettingsName &sn);

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
    ApplicationHelper * mpHelper=nullptr;
    const QStringList cmRawArgumentList;
    const QFileInfo cmExeFileInfo;
    QStringList mProcessingArguments;
    QStringList mPositionalArguments;
    QFileInfoList mPositionalFileInfos;
    SettingsName mSettingsName;
    KeyMap mSettingValuesMap;
};

inline const QStringList CommandLine::rawArgumentList() const  { return cmRawArgumentList; }
inline const SettingsName CommandLine::settingsName() const { return mSettingsName; }
