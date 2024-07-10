#pragma once

#include <QtCore/qglobal.h>

#if defined(OZCOLOR_LIBRARY)
#define OZCOLOR_EXPORT Q_DECL_EXPORT
#else
#define OZCOLOR_EXPORT Q_DECL_IMPORT
#endif
