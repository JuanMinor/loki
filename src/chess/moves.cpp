/*
    moves.cpp
    Author: M., Juan
    Date: 10/31/2023
*/

#include "include/chess/moves.h"

namespace loki
{
    Move::Move(uint8_t &__rank, uint8_t &__file)
    {
        this->rank = __rank;
        this->file = __file;
    }

    Move::~Move() {}

    Moves::Moves() {}

    Moves::~Moves() {}

    void Moves::__pawn__(const Piece *&__piece, const Board *&__board, const Fen *&__fen, std::vector<const Move &> &__moves) const
    {
        uint8_t rank = __piece->get_rank();
        uint8_t file = __piece->get_file();
        uint8_t color = __piece->get_color();
        char *en_passant = __fen->get_en_passant();
    }

    const std::vector<const Move &> Moves::generate(const Piece *&__piece, const Board *&__board, const Fen *&__fen) const
    {
        std::vector<const Move &> moves = {};
        if (!__piece || !__board)
        {
            return moves;
        }
        switch (__piece->get_alias())
        {
        case 'p':
        case 'P':
            this->__pawn__(__piece, __board, __fen, moves);
            break;
        default:
            break;
        }
        return moves;
    }

}