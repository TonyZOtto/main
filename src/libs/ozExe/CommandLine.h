#pragma once
#include "ozExe.h"

#include <QObject>

#include <QFileInfo>
#include <QList>
#include <QStringList>

#include "KeyMap.h"
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
    const KeyMap settingValues() const;

private: // non-const
    void processIncludeFile(const QString atsArg);
    void processSettingValue(const QString dlrArg);
    void processSettingsName(const QString pctArg);

private: // static
    static QStringList parseRawArguments(int argc, char *argv[]);

private:
    ApplicationHelper * mpHelper=nullptr;
    const QStringList cmRawArgumentList;
    const QFileInfo cmExeFileInfo;
    QStringList mPositionalArguments;
    QFileInfoList mPositionalFileInfos;
    SettingsName mSettingsName;
    KeyMap mSettingValuesMap;
};

inline const QStringList CommandLine::rawArgumentList() const  { return cmRawArgumentList; }
inline const SettingsName CommandLine::settingsName() const { return mSettingsName; }
