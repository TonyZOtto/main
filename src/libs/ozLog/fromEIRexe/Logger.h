#pragma once
#include "eIRexe.h"

#include <QObject>

#include <QQueue>
#include <QMap>
#include <QString>
#include <QUrl>
class QVariant;

#include "../eIRbase/Boolean.h"
#include "../eIRbase/Success.h"
#include "../eIRbase/Types.h"
#include "../eIRcore/MutexQueue.h"
#include "LogItem.h"
#include "LogObject.h"
#include "OutputLogUrl.h"
class BaseLogOutput;

class EIREXE_EXPORT Logger : public QObject
{
    Q_OBJECT
public: // types

public: // ctors
    explicit Logger(QObject *parent = nullptr);

public: // const

public slots:

public: // non-const
    Success open(const QString &aOutputLogUrlStrings);
    Success close();
    Success close(const OutputLogUrl aOutputLogUrl);
    bool start();
    bool hookTrollIn();
    bool hookTrollOut();
    void add(const LogItem &aLogItem);

private:

    bool open(const OutputLogUrl &aOutputLogUrl);
    bool openFile(const OutputLogUrl &aOutputLogUrl);
    bool openTroll(const OutputLogUrl &aOutputLogUrl);
    bool openSql(const OutputLogUrl &aOutputLogUrl);

private: // static
    static Boolean compare(const Log::Compare c, const QVariant &expected, const QVariant &actual);
    static Boolean compare(const Log::Compare c, const QPartialOrdering qpo);
    static bool equal(const QPartialOrdering qpo);
    static bool greater(const QPartialOrdering qpo);

signals:
    void queued(const LogItem &li);
    void queueCount(const Count k);
    void queueEmpty();

private:
    MutexQueue<LogItem> mInputItemQueue;
    Log::LevelFlags mMasterOutputLevelFlags = Log::LevelFlags(0);
    QMap<OutputLogUrl, BaseLogOutput *> mUrlOutputMap;
};
