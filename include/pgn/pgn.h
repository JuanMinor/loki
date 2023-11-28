/*
    pgn.h
    Author: M., Juan
    Date: 10/31/2023
*/

#ifndef PGN_H
#define PGN_H

#include <fstream>
#include <iomanip>
#include <string>

namespace pgn
{
    class Pgn
    {
        // @methods
        void __clear_stream_flags__(std::ostream &__os) const;
        std::_Put_time<char> __get_pgn_date__(void) const;
        void __set_metadata__(std::ostream &__os) const;

    public:
        Pgn();
        ~Pgn();

        // @methods
        void update_metadata(const std::string &__tag);
        void record(const std::string &__move) const;
        void create_pgn(void) const;
    };

#define PGN Pgn()

#define RECORD(MOVE) PGN.record(MOVE);
#define CREATE_PGN() PGN.create_pgn();
}

#endif