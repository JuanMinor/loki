//
//  board.h
//  @loki
//
//  Created by Juan Minor on 3/19/23.
//

#ifndef BOARD_H
#define BOARD_H

// @loki
#include "include/core/core.h"

// @loki
void init_logger(LOG_LEVEL __level, const char *__filepath, int __write_file);

void log(LOG_LEVEL __level, const char *__filename, const int __lineno, const char *__format, ...);

#define debug(...) log(DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define info(...) log(INFO, __FILE__, __LINE__, __VA_ARGS__)
#define warn(...) log(WARN, __FILE__, __LINE__, __VA_ARGS__)
#define critical(...) log(CRITICAL, __FILE__, __LINE__, __VA_ARGS__)

#endif