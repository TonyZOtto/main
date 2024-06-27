#pragma once

#include "LogItem.h"
#include "Logger.h"
#include "LogObject.h"
#include "LogMacros.h"

#define PROGRESS(msg) LOGMSG(Log::Progress, msg); LOGMSG(Log::TProgress, msg);
#define INFO(msg) LOGMSG(Log::Info, msg); LOGMSG(Log::TInfo, msg);
#define DETAIL(msg) LOGMSG(Log::Detail, msg); LOGMSG(Log::TDetail, msg);
#define TRACE(msg) LOGMSG(Log::Trace, msg);
#define TWARN(msg) LOGMSG(Log::Warning, msg);

#define WPOINTER(typ, pexp) { if (nullptr==(typ*)(exp)) \
    LOGITEMF2(Log::TWarning, "'%\1' pointer to %2 is null", #pexp, #typ); }

#define WEXPECTEQ(exp, act) LOGEXPECT(TWarning, Log::Equals, exp, act)
#define TEXPECTEQ(exp, act) LOGEXPECT(TWarning, Log::Equals, exp, act)
#define FEXPECTEQ(exp, act) LOGEXPECT(TWarning, Log::Equals, exp, act)
#define WEXPECTNE(exp, act) LOGEXPECT(TWarning, Log::NotEqual, exp, act)
#define TEXPECTNE(exp, act) LOGEXPECT(TWarning, Log::NotEqual, exp, act)
#define FEXPECTNE(exp, act) LOGEXPECT(TWarning, Log::NotEqual, exp, act)
#define WEXPECTLT(exp, act) LOGEXPECT(TWarning, Log::LessThan, exp, act)
#define TEXPECTLT(exp, act) LOGEXPECT(TWarning, Log::LessThan, exp, act)
#define FEXPECTLT(exp, act) LOGEXPECT(TWarning, Log::LessThan, exp, act)
#define WEXPECTLE(exp, act) LOGEXPECT(TWarning, Log::LessEqual, exp, act)
#define TEXPECTLE(exp, act) LOGEXPECT(TWarning, Log::LessEqual, exp, act)
#define FEXPECTLE(exp, act) LOGEXPECT(TWarning, Log::LessEqual, exp, act)
#define WEXPECTGT(exp, act) LOGEXPECT(TWarning, Log::GreaterThan, exp, act)
#define TEXPECTGT(exp, act) LOGEXPECT(TWarning, Log::GreaterThan, exp, act)
#define FEXPECTGT(exp, act) LOGEXPECT(TWarning, Log::GreaterThan, exp, act)
#define WEXPECTGE(exp, act) LOGEXPECT(TWarning, Log::GreaterEqual, exp, act)
#define TEXPECTGE(exp, act) LOGEXPECT(TWarning, Log::GreaterEqual, exp, act)
#define FEXPECTGE(exp, act) LOGEXPECT(TWarning, Log::GreaterEqual, exp, act)

#define PREFER(bexp) LOGASSERT(Prefer, Log::ExpectTrue, bexp)
#define PREFERNOT(bexp) LOGASSERT(Prefer, Log::ExpectFalse, bexp)
#define WEXPECT(bexp) LOGASSERT(Log::TWarning, Log::ExpectTrue, bexp)
#define WEXPECTNOT(bexp) LOGASSERT(TWarning, Log::ExpectFalse, bexp)
#define ASSERT(bexpr) LOGASSERT(Assert, Log::ExpectTrue, bexp)
#define ASSERTNOT(bexpr) LOGASSERT(Assert, Log::ExpectFalse, bexp)
