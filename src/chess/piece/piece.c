//
//  piece.c
//  @loki
//
//  Created by Juan Minor on 3/20/23.
//

// @c
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// @loki
#include "include/chess/piece/piece.h"

// @private
uint8_t __get_value__(const char *__alias)
{
    static const uint8_t values[128] = {
        ['P'] = 1, ['p'] = 1, ['N'] = 3, ['n'] = 3, ['B'] = 3, ['b'] = 3, ['R'] = 5, ['r'] = 5, ['Q'] = 9, ['q'] = 9, ['K'] = 25, ['k'] = 25};

    return values[(unsigned char)*__alias];
}

// @public
struct Piece *create_piece(const char *__alias, uint8_t __rank, uint8_t __file)
{
    struct Piece *piece = malloc(sizeof(struct Piece));
    piece->alias = strdup(__alias);
    piece->value = __get_value__(__alias);
    piece->color = isupper(*__alias) ? WHITE : BLACK;
    piece->rank = __rank;
    piece->file = __file;
    return piece;
}

void destroy_piece(struct Piece *__piece)
{
    if (__piece)
    {
        if (__piece->alias)
            free(__piece->alias);
        free(__piece);
    }
    return;
}
