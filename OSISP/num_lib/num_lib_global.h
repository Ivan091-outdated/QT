#ifndef NUM_LIB_GLOBAL_H
#define NUM_LIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(NUM_LIB_LIBRARY)
#  define NUM_LIB_EXPORT Q_DECL_EXPORT
#else
#  define NUM_LIB_EXPORT Q_DECL_IMPORT
#endif

#endif // NUM_LIB_GLOBAL_H
