#pragma once

#include <QObject>

#include "OutputLogUrl.h"
#include "LogObject.h"
class LogItem;

class BaseLogOutput : public QObject
{
    Q_OBJECT
public: // ctors
    explicit BaseLogOutput(QObject *parent = nullptr);
protected:
    BaseLogOutput(const OutputLogUrl &url, QObject *parent = nullptr);

public: // const
    QIODevice::OpenMode mode() const;
    Log::LevelFlags flags() const;
    bool isFlag(const Log::LevelFlag level) const;

public: // virtual
    virtual bool open(const OutputLogUrl &url) = 0;
    virtual bool write(const LogItem &item) = 0;

public: // non-const
    void url(const OutputLogUrl u);
    void mode(const QIODevice::OpenMode m);

signals:

protected:
    OutputLogUrl mUrl;
    QIODevice::OpenMode mOpenMode=QIODevice::NotOpen;
};

inline QIODeviceBase::OpenMode BaseLogOutput::mode() const { return mOpenMode; }
inline Log::LevelFlags BaseLogOutput::flags() const { return mUrl.levelFlags(); }
inline void BaseLogOutput::url(const OutputLogUrl u) { mUrl = u; }
inline void BaseLogOutput::mode(const QIODeviceBase::OpenMode m) { mOpenMode = m; }
