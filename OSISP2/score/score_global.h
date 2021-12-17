#ifndef SCORE_GLOBAL_H
#define SCORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SCORE_LIBRARY)
#  define SCORE_EXPORT Q_DECL_EXPORT
#else
#  define SCORE_EXPORT Q_DECL_IMPORT
#endif

#endif // SCORE_GLOBAL_H
