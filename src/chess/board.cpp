/*
    board.cpp
    Author: M., Juan
    Date: 10/31/2023
*/

#include <cstring>
#include <iostream>
#include <stdint.h>
#include <unordered_map>

#include "include/chess/board.h"
#include "include/core/core.h"
#include "include/logger/logger.h"
#include "include/pgn/pgn.h"

namespace loki
{
    std::unordered_map<char, std::string> piece_names = {
        {'p', "Pawn"},
        {'n', "Knight"},
        {'b', "Bishop"},
        {'r', "Rook"},
        {'q', "Queen"},
        {'k', "King"}};

    Board::Board(const char *__placement)
    {
        size_t size = std::strlen(__placement);
        uint8_t rank = BOARD_SIZE - 1, file = 0;
        this->board.resize(BOARD_SIZE, std::vector<Piece *>(BOARD_SIZE, nullptr));

        for (size_t i = 0; i < size && rank >= 0; ++i)
        {
            char c = __placement[i];
            if (c == '/')
            {
                rank--;
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
            Piece *piece = new Piece(c, rank, file);
            this->board[rank][file++] = piece;
            std::stringstream ss;
            std::string color = piece->get_color() == WHITE ? "White" : "Black";
            ss << "Created "
               << color
               << " "
               << piece_names.at(std::tolower(c, std::locale()))
               << " in position "
               << this->__get_algebraic_notation__(piece->get_rank(), piece->get_file())
               << " ✅";
            logger::LOG_DEBUG(ss.str());
        }
    }

    Board::~Board()
    {
        for (int rank = BOARD_SIZE - 1; rank >= 0; --rank)
        {
            for (uint8_t file = 0; file < BOARD_SIZE; ++file)
            {
                Piece *piece = this->board.at(rank).at(file);
                if (piece != nullptr)
                {
                    std::stringstream ss;
                    std::string color = piece->get_color() == WHITE ? "White" : "Black";
                    ss << "Destroyed "
                       << color
                       << " "
                       << piece_names.at(std::tolower(piece->get_alias(), std::locale()))
                       << " in position "
                       << this->__get_algebraic_notation__(rank, file)
                       << " ❌";
                    logger::LOG_DEBUG(ss.str());
                    delete piece;
                }
            }
        }
    }

    std::string Board::__get_algebraic_notation__(const uint8_t &__rank, const uint8_t &__file) const
    {
        std::stringstream ss;
        ss << char(97 + __file) << unsigned(__rank);
        return ss.str();
    }

    std::vector<std::vector<Piece *>> Board::get_board(void) const
    {
        return this->board;
    }

    void Board::move(Piece *&__piece, const uint8_t &__rank, const uint8_t &__file)
    {
        std::stringstream ss;
        // @errors
        if (__rank < 0 || __rank >= BOARD_SIZE || __file < 0 || __file >= BOARD_SIZE)
        {
            ss << "Board address <rank, file> <" << unsigned(__rank) << ", " << unsigned(__file) << "> is out of bounds!";
            logger::LOG_ERROR(ss.str());
            return;
        }
        uint8_t rank = __piece->get_rank(), file = __piece->get_file();
        if (this->board[rank][file] == nullptr)
        {
            ss << "Piece holds invalid address <rank, file> <" << unsigned(rank) << ", " << unsigned(file) << ">!";
            logger::LOG_ERROR(ss.str());
            return;
        }

        // @move
        __piece->set_rank(__rank);
        __piece->set_file(__file);
        this->board[__rank][__file] = __piece;
        this->board[rank][file] = nullptr;

        std::string color = __piece->get_color() == WHITE ? "White" : "Black";

        ss << "Moved "
           << color
           << " "
           << piece_names.at(std::tolower(__piece->get_alias(), std::locale()))
           << " from "
           << this->__get_algebraic_notation__(rank, file)
           << " to "
           << this->__get_algebraic_notation__(__rank, __file)
           << " 🚀";

        logger::LOG_INFO(ss.str());

        // @pgn
        ss.str("");
        ss << this->__get_algebraic_notation__(rank + 1, file)
           << " "
           << this->__get_algebraic_notation__(__rank + 1, __file);
        pgn::RECORD(ss.str());
        return;
    }

    void Board::print(void) const
    {
        if (!DEBUG_ENABLED)
        {
            return;
        }
        std::cout << "    ";
        for (uint8_t j = 0; j < BOARD_SIZE; ++j)
        {
            std::cout << char(97 + j) << " ";
        }
        std::cout << "\n";
        for (int i = BOARD_SIZE - 1; i >= 0; i--) // @cannot be size_t or uint8_t **underflow**
        {
            std::cout << unsigned(i + 1) << " - ";
            for (uint8_t j = 0; j < BOARD_SIZE; ++j)
            {
                if (this->board.at(i).at(j))
                {
                    std::cout << this->board.at(i).at(j)->get_alias() << " ";
                    continue;
                }
                std::cout << ". ";
            }
            std::cout << "- " << unsigned(i + 1);
            std::cout << "\n";
        }
        std::cout << "    ";
        for (uint8_t j = 0; j < BOARD_SIZE; ++j)
        {
            std::cout << char(97 + j) << " ";
        }
        std::cout << std::endl;
    }
}
