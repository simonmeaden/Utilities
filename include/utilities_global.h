#pragma once

#include <QtCore/qglobal.h>

#if defined(UTILITIES_LIBRARY)
  #define UTILITIES_SHARED_EXPORT Q_DECL_EXPORT
#else
  #define UTILITIES_SHARED_EXPORT Q_DECL_IMPORT
#endif

