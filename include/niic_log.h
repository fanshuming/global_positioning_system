#ifndef __NIIC__LOG__H__
#define __NIIC__LOG__H__

#include <stdio.h>

#define OFF   (0)
#define FATAL (1)
#define ERROR (2)
#define WARN  (3)
#define INFO  (4)
#define DEBUG (5)
#define TRACE (6)

#define LOG_LEVEL DEBUG


#define LOG(level, format, ...) \
    if(LOG_LEVEL >= level) { \
        fprintf(stderr, "[%s|%s@%s,%d] " format "\n", \
            #level, __func__, __FILE__, __LINE__, ##__VA_ARGS__ ); \
    }

#endif
