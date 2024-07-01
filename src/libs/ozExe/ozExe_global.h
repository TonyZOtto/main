#pragma once

#include <QtCore/qglobal.h>

#if defined(OZEXE_LIBRARY)
#define OZEXE_EXPORT Q_DECL_EXPORT
#else
#define OZEXE_EXPORT Q_DECL_IMPORT
#endif
