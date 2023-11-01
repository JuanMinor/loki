/*
    board.h
    Author: M., Juan
    Date: 10/31/2023
*/

#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "include/chess/piece.h"

class Board
{
    std::vector<std::vector<Piece *>> board;

public:
    Board(const char *__placement);
    ~Board();

    // @methods
    void print();
};

#endif