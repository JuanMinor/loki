//
//  log.c
//  @loki
//
//  Created by Juan Minor on 4/2/23.
//

// @c
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// @loki
#include "include/log/log.h"

static int __LOGGER__ = -1;
