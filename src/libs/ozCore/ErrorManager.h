#pragma once

#include <QObject>

#include <KeyMapT.h>

/* Usage:
 *  In .cpp source
 *      * Outside any function:
 *          Q_GLOBAL_STATIC(ErrorManager, EMGR)
 *      * In AppInstance initialize()
 *          EMGR->initialize();
 */

class ErrorManager : public QObject
{
    Q_OBJECT
public:
    explicit ErrorManager();

signals:

private:
    void fillErrorMap();

private:
    KeyMapT<BaseErrorItem> mKeyErrorItemMap;
};
