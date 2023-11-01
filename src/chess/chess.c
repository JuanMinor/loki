//
//  chess.c
//  @loki
//
//  Created by Juan Minor on 3/19/23.
//

// @loki
#include "include/chess/chess.h"

// @public
void make_move(const uint8_t __rank, const uint8_t __file, struct Board *__board)
{
    struct Piece *piece = __board->board[7][0];
    move(__rank, __file, __board, piece);
}

void draw(const char *__fen_str)
{
    // @draw board in terminal
    struct Fen *fen = create_fen(__fen_str);
    struct Board *board = create_board(fen->placement);

    print_board(board);

    make_move(4, 3, board);

    print_board(board);

    // @cleanup
    destroy_board(board);
    destroy_fen(fen);

    return;
}