#pragma once

#include <QtCore/qglobal.h>

#if defined(INDIBASE6_LIBRARY)
#define INDIBASE6_EXPORT Q_DECL_EXPORT
#else
#define INDIBASE6_EXPORT Q_DECL_IMPORT
#endif
