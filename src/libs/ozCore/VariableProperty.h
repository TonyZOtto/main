/*! @file VariableProperty.h Declarations for VariableProperty mechanism

Usage:

In .h file:
@code
#include <VariableProperty.h>
#include <VariableSet.h>
#include <Ident.h>

#include <LogLevel.h> // as needed
#include <MillisecondTime.h> // as needed

#define LOGITEM_VARPROPS(TKD) \
    TKD(MillisecondTime, TimeStamp, MillisecondTime::current()) \
    TKD(LogLevel, Level, LogLevel::Null) \

class OZCORE_EXPORT LogItem : public VariableSet
{
public:
    LogItem(const Key &setKey) : VariableSet(Ident(setKey)) { ctor(); }
private:
    void ctor();
    DEFINE_VARPROPS(LOGITEM_VARPROPS);
};
@endcode

In .cpp file:
@code
#include "LogItem.h"

void LogItem::ctor(void)
{
    DECLARE_DEFALT_VARPROPS(LOGITEM_VARPROPS);
}

@endcode

*/

#pragma once
#include "ozCore.h"

#define DECLARE_DEFALT_CTOR_VARPROPS(TYPE, KEY, DFLT) \
    set( #KEY, TYPE(DFLT)); \

#define DECLARE_CLASS_VARFUNCTIONS(TYPE, KEY, DFLT) \
    TYPE KEY() const { return TYPE(get( #KEY ).current()); }   \
    void KEY(const TYPE &val) { set( #KEY , Value(val)); }     \
    void KEY##Defalt(void) { KEY(TYPE(DFLT)); }   \

#define DECLARE_DEFALT_VARPROPS(DEF) \
        DEF(DECLARE_DEFALT_CTOR_VARPROPS); \

#define DEFINE_VARPROPS(DEF) \
        DEF(DECLARE_CLASS_VARFUNCTIONS); \

