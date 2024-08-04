#pragma once
#include "ozLog.h"

#include <QObject>

/* Usage:
 * #include <LogEngine.h>
 * Q_GLOBAL_STATIC(LogEngine, LOG)
 * LOG->add(LogItem(Log::Progress, "Progress Message"));
*/

class OZLOG_EXPORT LogEngine : public QObject
{
    Q_OBJECT
public: // ctors
    explicit LogEngine();
    ~LogEngine();

public slots:

signals:

public: // const

public: // non-const

private:

};
