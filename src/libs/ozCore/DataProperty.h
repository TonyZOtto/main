/*! @file DataProperty.h Declarations for DataProperty mechanism

Usage:

#define LOGITEM_DATAPROPS(TND) \
    TND(TimeStamp, TimeStamp, TimeStamp()) \
    TND(LogLevel, Level, LogLevel::Null) \

class EIRCORESHARED_EXPORT LogItem
{
    DECLARE_PARENT_DATAPROPS(LOGITEM_DATAPROPS)
public:
    LogItem(void); // default c'tor
}

class LogItemData : public QSharedData
{
    DECLARE_CHILD_DATAPROPS(LOGITEM_DATAPROPS)
public:
    LogItemData(void)
    {
        DEFINE_DATAPROPS_CTORS(LOGITEM_DATAPROPS)
    }
}


*/

#ifndef DATAPROPERTY_H
#define DATAPROPERTY_H

#define DATAPROP_DECLARE_PARENT(TYPE, NAME, DFLT) \
    public: \
        void init##NAME(void)           { if (data) data->init##NAME(); } \
        void set##NAME(const TYPE v)    { if (data) data->set##NAME(v);    } \
        TYPE get##NAME(void) const      { return (data) ? data->get##NAME() : DFLT; } \
        TYPE * ptr##NAME(void)          { return (data) ? data->ptr##NAME() : 0; } \

#define DATAPROP_DECLARE_CHILD(TYPE, NAME, DFLT) \
    private: \
        TYPE TYPE##_##NAME; \
    public: \
        void init##NAME(void)           { TYPE##_##NAME = DFLT; } \
        void set##NAME(const TYPE v)    { TYPE##_##NAME = v;    } \
        TYPE get##NAME(void) const      { return TYPE##_##NAME; } \
        TYPE * ptr##NAME(void)          { return & TYPE##_##NAME; } \

#define DATAPROP_CTOR(TYPE, NAME, DFLT) \
        TYPE##_##NAME = DFLT; \

#define DECLARE_PARENT_DATAPROPS(DEF) \
        DEF(DATAPROP_DECLARE_PARENT) \

#define DECLARE_CHILD_DATAPROPS(DEF) \
        DEF(DATAPROP_DECLARE_CHILD) \

#define DEFINE_DATAPROPS_CTORS(DEF) \
        DEF(DATAPROP_CTOR) \


#endif // DATAPROPERTY_H
