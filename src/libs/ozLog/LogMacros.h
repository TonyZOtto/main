#pragma once

#include "LogContext.h"
#include "LogItemObj.h"
#include "LogEngine.h"

#define LOGCATEGORYH(name)
#define LOGCATEGORYHQMT(name, qmt)
#define LOGCATEGORYCPP(name)
#define LOGCTX() LogContext(Q_FILE_INFO, __FILE__, LOG_CATEGORY_NAME, __LINE__)
#define LOGITEMMSG(msg) LogItem(LOGCTX, msg);
#define LOGITEMFMTL(fmt, names, values) LogItem(LOGCTX, fmt, names, values);
#define LOGITEMDUMP(names, values) LogItem(LOGCTX, names, values);
#define LOGADD(item)
