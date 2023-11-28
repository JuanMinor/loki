/*
    piece.h
    Author: M., Juan
    Date: 10/31/2023
*/

#ifndef PIECE_H
#define PIECE_H

#include <ctype.h>
#include <stdint.h>

namespace loki
{
    class Piece
    {
        char alias;
        uint8_t value;
        uint8_t color;
        uint8_t rank;
        uint8_t file;
        bool moved;

        // @methods
        bool __has_piece_moved__(void) const;

    public:
        Piece(const char &__alias, const uint8_t &__rank, const uint8_t &__file);
        ~Piece();

        // @methods
        char get_alias(void) const;
        uint8_t get_value(void) const;
        uint8_t get_color(void) const;
        uint8_t get_rank(void) const;
        void set_rank(const uint8_t &__rank);
        uint8_t get_file(void) const;
        void set_file(const uint8_t &__file);
        bool get_moved(void) const;
        void set_moved(const bool &__moved);
    };
}

#endif