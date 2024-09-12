/*! @file DataProperty.h Declarations for DataProperty mechanism

Usage:

In .h file:
@code
#include <QSharedData>

#include <eirBase/DataProperty.h>

#define LOGITEM_DATAPROPS(TND) \
    TND(MillisecondTime, TimeStamp, MillisecondTime()) \
    TND(LogLevel, Level, LogLevel::Null) \

class LogItemData : public QSharedData
{
    DECLARE_CHILD_DATAPROPS(LOGITEM_DATAPROPS)
public:
    LogItemData(void)
    {
        DEFINE_DATAPROPS_CTORS(LOGITEM_DATAPROPS)
    }
};

class EIRCORESHARED_EXPORT LogItem
{
    DECLARE_PARENT_DATAPROPS(LOGITEM_DATAPROPS)
    DECLARE_DATAPROPS(LogItem, LogItemData)
    LogItem(const int size); // alternate ctor
};
@endcode

In .cpp file:
@code
#include "LogItem.h"

DEFINE_DATAPROPS(LogItem, LogItemData)

LogItem::LogItem(const int size)
    : data(new LogItemData)
    , size_i(size)
{
    ctor();
}

void LogItem::ctor(void)
{
    setTimeStamp(MillisecondTime::current());
}

void VariableSet::dtor(void) {}
@endcode

*/

#ifndef DATAPROPERTY_H
#define DATAPROPERTY_H

#define DATAPROP_DECLARE_PARENT(TYPE, NAME, DFLT) \
    public: \
        void init##NAME(void)               { if (data) data->init##NAME(); } \
        void set##NAME(const TYPE v)        { if (data) data->set##NAME(v);    } \
        TYPE get##NAME(void) const          { return (data) ? data->get##NAME() : DFLT; } \
        TYPE * ptr##NAME(void)              { return (data) ? data->ptr##NAME() : 0; } \
        const TYPE * ptr##NAME(void) const  { return (data) ? data->ptr##NAME() : 0; } \

/*
        TYPE & ref##NAME(void)              { return (data) ? data->ref##NAME() : 0; } \
*/

#define DATAPROP_DECLARE_CHILD(TYPE, NAME, DFLT) \
    private: \
        TYPE TYPE##_##NAME; \
    public: \
        void init##NAME(void)               { TYPE##_##NAME = DFLT; } \
        void set##NAME(const TYPE v)        { TYPE##_##NAME = v;    } \
        TYPE get##NAME(void) const          { return TYPE##_##NAME; } \
        TYPE * ptr##NAME(void)              { return & TYPE##_##NAME; } \
        const TYPE * ptr##NAME(void) const  { return & TYPE##_##NAME; } \

/*
        TYPE & ref##NAME(void)              { return & TYPE##_##NAME; } \
*/

#define DATAPROP_CTOR(TYPE, NAME, DFLT) \
        TYPE##_##NAME = DFLT; \

#define DECLARE_PARENT_DATAPROPS(DEF) \
        DEF(DATAPROP_DECLARE_PARENT) \

#define DECLARE_CHILD_DATAPROPS(DEF) \
        DEF(DATAPROP_DECLARE_CHILD) \

#define DEFINE_DATAPROPS_CTORS(DEF) \
        DEF(DATAPROP_CTOR) \

#define DECLARE_DATAPROPS(CLASS, DATA) \
    public: \
        CLASS(void); \
        CLASS(const CLASS & rhs); \
        CLASS & operator = (const CLASS & rhs); \
        ~CLASS(); \
    private: \
        void ctor(void); \
        void dtor(void); \
        QSharedDataPointer<DATA> data; \

#define DEFINE_DATAPROPS(CLASS, DATA) \
CLASS::CLASS() : data(new DATA) { ctor(); } \
CLASS::CLASS(const CLASS &rhs) : data(rhs.data) {} \
CLASS &CLASS::operator=(const CLASS &rhs) \
{ if (this != &rhs) data.operator=(rhs.data); return *this; } \
CLASS::~CLASS() { dtor(); } \

#endif // DATAPROPERTY_H
