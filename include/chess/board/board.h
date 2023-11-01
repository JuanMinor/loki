//
//  board.h
//  @loki
//
//  Created by Juan Minor on 3/19/23.
//

#ifndef BOARD_H
#define BOARD_H

// @c
#include <stdio.h>

// @loki
#include "include/chess/piece/piece.h"

#define BOARD_SIZE 8

struct Board
{
	struct Piece *board[BOARD_SIZE][BOARD_SIZE];
};

// @public
struct Board *create_board(const char *__placement);
void move(const uint8_t __rank, const uint8_t __file, struct Board *__board, struct Piece *__piece);
void print_board(const struct Board *__board);
void destroy_board(struct Board *__board);

#endif