#pragma once

#include <QtCore/qglobal.h>

#if defined(OZQTCV_LIBRARY)
#define OZQTCV_EXPORT Q_DECL_EXPORT
#else
#define OZQTCV_EXPORT Q_DECL_IMPORT
#endif
