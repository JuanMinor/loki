//
//  core.h
//  @loki
//
//  Created by Juan Minor on 3/19/23.
//

#ifndef CORE_H
#define CORE_H

// @enums
typedef enum
{
    DEBUG,
    INFO,
    WARN,
    CRITICAL
} LOG_LEVEL;

// @debug
#define DEBUG_ENABLED 1
#define LOG_DIR "logs/loki.log"

// @color
#define WHITE 0
#define BLACK 1

#endif
