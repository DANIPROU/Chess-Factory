#ifndef UTILS_H
#define UTILS_H

enum type {
	W_SQUARE,
	B_SQUARE,
	PAWN,
	BISHOP,
	KNIGHT,
	ROOK,
	QUEEN,
	KING
};

struct piece {
	int column;
	int line;
	enum type type;
	int color;
	int points;
	int kills;
	int has_moved;
};

#endif /* ! UTILS_H */
