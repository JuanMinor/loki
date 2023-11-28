/*
    fen.cpp
    Author: M., Juan
    Date: 10/31/2023
*/

#include <cstring>
#include <cstddef>

#include "include/chess/fen.h"
#include "include/core/core.h"

namespace loki
{
    Fen::Fen(char *__fen)
    {
        std::vector<char *> tokens = this->__split__(__fen, " ");
        this->placement = tokens[0];
        this->color = (*tokens[1] == 'w' || *tokens[1] == 'W') ? WHITE : BLACK;
        this->castling = tokens[2];
        this->en_passant = tokens[3];
        this->halfmove_clock = (uint8_t)(*tokens[4] - '0');
        this->fullmoves = (uint8_t)(*tokens[5] - '0');
    }

    Fen::~Fen() {}

    std::vector<char *> Fen::__split__(char *__fen, const char *__delimiters) const
    {
        std::vector<char *> tokens;
        char *token = strtok(__fen, __delimiters);
        while (token != nullptr)
        {
            tokens.emplace_back(token);
            token = strtok(nullptr, __delimiters);
        }
        return tokens;
    }

    char *Fen::get_placement(void) const
    {
        return this->placement;
    }

    char *Fen::get_castling(void) const
    {
        return this->castling;
    }

    char *Fen::get_en_passant(void) const
    {
        return this->en_passant;
    }

    uint8_t Fen::get_color(void) const
    {
        return this->color;
    }

    uint8_t Fen::get_halfmove_clock(void) const
    {
        return this->halfmove_clock;
    }

    uint8_t Fen::get_fullmoves(void) const
    {
        return this->fullmoves;
    }
}