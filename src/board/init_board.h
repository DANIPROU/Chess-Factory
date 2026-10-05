#ifndef INIT_BOARD_H
#define INIT_BOARD_H

#include "../utils/utils.h"

struct piece *make_piece(int column, int line, int type, int color, int points, int kills, int has_moved);

struct piece ***init_board();
struct piece ***init_board_from_board(struct piece ***board);

void place_piece(struct piece ***board, struct piece *piece, int col, int line);
void display_board(struct piece ***board);

#endif /* ! INIT_BOARD_H */
