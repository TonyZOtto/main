#pragma once

#include <QtCore/qglobal.h>

#if defined(OZCORE_LIBRARY)
#define OZCORE_EXPORT Q_DECL_EXPORT
#else
#define OZCORE_EXPORT Q_DECL_IMPORT
#endif
