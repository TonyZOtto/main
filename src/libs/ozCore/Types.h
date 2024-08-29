//!file {ottozcode}/src/libs/ozCore/Types.h Common typedef's
#pragma once

#include <QtGlobal>
#include <QList>
#include <QString>

typedef quint8          BYTE;
typedef quint16         WORD;
typedef float           WORDF;
typedef quint32         TRIBYTE;
typedef quint32         DWORD;
typedef double          DWORDF;
typedef quint64         QWORD;
typedef quint128        OWORD;
typedef qint16          SWORD;
typedef qint32          SDWORD;
typedef qint64          SQWORD;
typedef qint128         SOWORD;
typedef quintptr        NWORD;
typedef qptrdiff        SNWORD;
typedef signed          INT;
typedef unsigned        UINT;
typedef unsigned        Id;

typedef QString         UText;
typedef QWORD           EpochMilliseconds;
typedef qsizetype       Index;
typedef size_t          Seq;
typedef size_t          Count;

typedef QList<int>      IntList;

