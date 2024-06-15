#pragma once

#include "Context.h"
#include "LogItem.h"
#include "Logger.h"

#define LOGCTX() Context(Q_FILE_INFO, __FILE__, __LOG_CONTEXT__, __LINE__)
#define LOGITEM(msg) LogItem(LOGCTX, msg);
#define LOGADD(item)
