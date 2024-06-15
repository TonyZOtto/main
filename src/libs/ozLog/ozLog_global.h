#pragma once

#include <QtCore/qglobal.h>

#if defined(OZLOG_LIBRARY)
#define OZLOG_EXPORT Q_DECL_EXPORT
#else
#define OZLOG_EXPORT Q_DECL_IMPORT
#endif
