/*
    fen.h
    Author: M., Juan
    Date: 10/31/2023
*/

#ifndef FEN_H
#define FEN_H

#include <stdint.h>
#include <vector>

namespace loki
{
    class Fen
    {
        char *placement;
        char *castling;
        char *en_passant;
        uint8_t color;
        uint8_t halfmove_clock;
        uint8_t fullmoves;
        // @methods
        std::vector<char *> __split__(char *__fen, const char *__delimiters) const;

    public:
        Fen(char *__fen);
        ~Fen();

        // @getters
        char *get_placement(void) const;
        char *get_castling(void) const;
        char *get_en_passant(void) const;
        uint8_t get_color(void) const;
        uint8_t get_halfmove_clock(void) const;
        uint8_t get_fullmoves(void) const;
    };
}

#endif