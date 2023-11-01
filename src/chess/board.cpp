/*
    board.cpp
    Author: M., Juan
    Date: 10/31/2023
*/

#include <cstring>
#include <string>
#include <stdint.h>
#include <iostream>

#include "include/chess/board.h"
#include "include/core/core.h"

Board::Board(const char *__placement)
{
    size_t size = std::strlen(__placement);
    uint8_t rank = 0, file = 0;
    this->board.resize(BOARD_SIZE, std::vector<Piece *>(BOARD_SIZE, nullptr));

    for (size_t i = 0; i < size && rank < BOARD_SIZE; ++i)
    {
        char c = __placement[i];
        if (c == '/')
        {
            rank++;
            file = 0;
            continue;
        }
        if (std::isdigit(c))
        {
            uint8_t empties = c - '0';
            for (uint8_t j = 0; j < empties; ++j)
            {
                this->board[rank][file++] = nullptr;
            }
            continue;
        }
        this->board[rank][file++] = new Piece(c, rank, file);
    }
}

Board::~Board()
{
    for (uint8_t rank = 0; rank < BOARD_SIZE; ++rank)
    {
        for (uint8_t file = 0; file < BOARD_SIZE; ++file)
        {
            Piece *piece = this->board[rank][file];
            if (piece != nullptr)
            {
                delete piece;
            }
        }
    }
}

void Board::print()
{
    for (uint8_t i = 0; i < BOARD_SIZE; ++i)
    {
        for (uint8_t j = 0; j < BOARD_SIZE; ++j)
        {
            if (this->board[i][j])
            {
                std::cout << this->board[i][j]->get_alias() << " ";
                continue;
            }
            std::cout << ". ";
        }
        std::cout << std::endl;
    }
}
