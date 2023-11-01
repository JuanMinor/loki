//
//  piece.h
//  @loki
//
//  Created by Juan Minor on 3/20/23.
//

#ifndef PIECE_H
#define PIECE_H

// @c
#include <stdint.h>

// @loki
#include "include/core/core.h"

struct Piece
{
    char *alias;
    uint8_t value;
    uint8_t color;
    uint8_t rank;
    uint8_t file;
};

// @private
uint8_t __get_value__(const char *__alias);

// @public
struct Piece *create_piece(const char *__alias, uint8_t rank, uint8_t file);
void destroy_piece(struct Piece *__piece);

#endif
