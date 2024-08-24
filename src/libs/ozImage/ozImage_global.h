#pragma once
#include <QtCore/qglobal.h>

#if defined(OZIMAGE_LIBRARY)
#define OZIMAGE_EXPORT Q_DECL_EXPORT
#else
#define OZIMAGE_EXPORT Q_DECL_IMPORT
#endif

