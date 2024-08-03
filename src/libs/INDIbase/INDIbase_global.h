#pragma once

#include <QtCore/qglobal.h>

#if defined(INDIBASE_LIBRARY)
#define INDIBASE_EXPORT Q_DECL_EXPORT
#else
#define INDIBASE_EXPORT Q_DECL_IMPORT
#endif
