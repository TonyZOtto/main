#pragma once

#include "Context.h"
#include "LogItem.h"
#include "Logger.h"

#define LOGCTX() Context(Q_FILE_INFO, __FILE__, __LOG_CONTEXT__, __LINE__)
#define LOGITEMMSG(msg) LogItem(LOGCTX, msg);
#define LOGITEMFMTL(fmt, names, values) LogItem(LOGCTX, fmt, names, values);
#define LOGITEMDUMP(names, values) LogItem(LOGCTX, names, values);
#define LOGADD(item)
