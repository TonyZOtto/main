#pragma once

#include "Context.h"
#include "Logger.h"
Q_GLOBAL_STATIC(Logger, LOG);


#define LOGCTX(lvl) Context(Q_FUNC_INFO, __FILE__, __LINE__, lvl)
#define LOGITEMSG(lvl, msg) (LogItem(LOGCTX(lvl), msg))
#define LOGITEMF1(lvl, fmt, arg1) LogItem(LOGCTX(lvl), fmt, #arg1, arg1)
#define LOGITEMF2(lvl, fmt, arg1, arg2) LogItem(LOGCTX(lvl), fmt, #arg1, arg1, #arg2, arg2)
#define LOGITEMF3(lvl, fmt, arg1, arg2, arg3) LogItem(LOGCTX(lvl), fmt, #arg1, arg1, #arg2, arg2, #arg3, arg3)
#define LOGITEMF4(lvl, fmt, arg1, arg2, arg3, arg4) LogItem(LOGCTX(lvl), fmt, #arg1, arg1, #arg2, arg2, #arg3, arg3, #arg4, arg4)
#define LOGITEMFL(lvl, fmt, names, values) LogItem(LOGCTX(lvl), fmt, names, values);
#define LOGITEMXP(lvl, comp, exp, act) LogItem(LOGCTX(lvl), comp, #exp, exp, #act, act);
#define LOGITEMAS(lvl, flag, bexp) LogItem(LOGCTX(lvl), flag, #bexp, bexp);

#define LOGADD(item) LOG->add(item);
#define LOGMSG(lvl, msg) LOGADD(LOGITEMSG(lvl, msg));
#define LOGFMT1(lvl, fmt, arg1) LOGADD(LOGITEMF1(lvl, fmt, arg1));
#define LOGFMT2(lvl, fmt, arg1, arg2) LOGADD(LOGITEMF2(lvl, fmt, arg1, arg2));
#define LOGFMT3(lvl, fmt, arg1, arg2, arg3) LOGADD(LOGITEMF3(lvl, fmt, arg1, arg2, arg3));
#define LOGFMT4(lvl, fmt, arg1, arg2, arg3, arg4) LOGADD(LOGITEMF4(lvl, fmt, arg1, arg2, arg3, arg4));
#define LOGEXPECT(lvl, comp, exp, act) LOGADD(LOGITEMXP(lvl, comp, exp, act));
#define LOGEXPBOOL(lvl, comp, act) LOGADD(LOGITEMXP(lvl, comp, bexp));
#define LOGASSERT(lvl, flag, bexp) LOGADD(LOGITEMAS(lvl, flag, bexp));

