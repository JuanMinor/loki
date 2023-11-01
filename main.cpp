/*
    main.cpp
    Author: M., Juan
    Date: 10/31/2023
*/

#include <iostream>

#include "include/chess/fen.h"
#include "include/chess/board.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "No arguments found. Supply a valid FEN string" << std::endl;
        return 1;
    }

    Fen *fen = new Fen(argv[1]);

    Board *board = new Board(fen->get_placement());

    board->print();
    return 0;
}
