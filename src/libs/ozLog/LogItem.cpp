#include "LogItem.h"

#include "LogFileInfo.h"

class LogItemData : public QSharedData
{
public: // types
    struct ArgumentInfo
    {
        QByteArray  name;
        QVariant    value;
        QString     info;
    };
    typedef QList<ArgumentInfo> ArgumentInfoList;

public: // shared pointer data
    QByteArray          dQFuncInfo;
    LogFileInfo         dFileInfo;
    int                 dFileLine;
    QByteArray          dCategory;
    QString             dMessage;
    QString             dFormat;
    ArgumentInfoList    dArguments;
    QString             dDebugHead;
    QStringList         dDebugStrings;
    QString             dDebugFoot;

};

// shared data members
LogItem::LogItem() : data(new LogItemData) {;}
LogItem::LogItem(const LogItem &rhs) : data{rhs.data} {;}
LogItem::~LogItem() {;}
LogItem &LogItem::operator=(const LogItem &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

