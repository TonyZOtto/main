#pragma once

#include <QtCore/qglobal.h>

#if defined(INDIFACE6_LIBRARY)
#define INDIFACE6_EXPORT Q_DECL_EXPORT
#else
#define INDIFACE6_EXPORT Q_DECL_IMPORT
#endif
