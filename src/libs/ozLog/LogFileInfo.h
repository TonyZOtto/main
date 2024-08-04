#pragma once
#include "ozLog.h"

#include <QFileInfo>

#include <QFile>
#include <QIODevice>
#include <QMetaType>
#include <QString>
#include <QStringList>
#include <QTimeZone>

class OZLOG_EXPORT LogFileInfo : public QFileInfo
{
public: // types


public: // ctors
    LogFileInfo(const QString &fpath);

public: // const
    bool isNull() const;
    bool isSuffix(const QString &sfx) const;
    size_t byteCount() const;
    QStringList infoStrings(int verbosity=-1) const;
    QFile * file(const QIODevice::OpenMode &mode,
                 QObject * parent=nullptr);
    QString permissionsString() const;

    QDateTime born() const;
    QDateTime modified() const;
    QDateTime used() const;
    QDateTime time(const QFile::FileTime ft,
                   const QTimeZone &tz=QTimeZone::LocalTime);

public: // non-const
    QFileInfo & it();

private: // const
    QString flagString(const bool isSet=true) const;

private: // non-const

private:

public: // metatype
    LogFileInfo() = default;
    LogFileInfo(const LogFileInfo &other) = default;
    LogFileInfo &operator = (const LogFileInfo &other) = default;
    ~LogFileInfo() = default;

};

Q_DECLARE_METATYPE(LogFileInfo)

