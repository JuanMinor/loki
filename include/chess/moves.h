/*
    moves.h
    Author: M., Juan
    Date: 10/31/2023
*/

#ifndef MOVES_H
#define MOVES_H

#include <ctype.h>
#include <stdint.h>
#include <vector>

#include "include/chess/board.h"
#include "include/chess/fen.h"
#include "include/chess/piece.h"

namespace loki
{
    class Move
    {
        uint8_t rank;
        uint8_t file;

    public:
        Move(uint8_t &__rank, uint8_t &__file);
        ~Move();

        // @methods
        uint8_t get_rank(void) const;
        uint8_t get_file(void) const;
    };

    class Moves
    {
        // @methods
        void __pawn__(const Piece *&__piece, const Board *&__board, const Fen *&__fen, std::vector<const Move &> &__moves) const;

    public:
        Moves();
        ~Moves();

        // @methods
        const std::vector<const Move &> generate(const Piece *&__piece, const Board *&__board, const Fen *&__fen) const;
    };
}

#endif