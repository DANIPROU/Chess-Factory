#include "init_board.h"

#include <stdio.h>
#include <stdlib.h>

struct piece *make_piece(int column, int line, int type, int color, int points, int kills, int has_moved)
{
	struct piece *piece = malloc(sizeof(struct piece));
	if (!piece)
	{
		printf("ERROR make_piece: Something unexpected happened at piece memory allocation.\n");
		return NULL;
	}

	piece->column = column;
	piece->line = line;
	piece->type = type;
	piece->color = color;
	piece->points = points;
	piece->kills = kills;
	piece->has_moved = has_moved;
	return piece;
}

struct piece ***init_board()
{
	struct piece ***board = calloc(9, sizeof(struct piece **));
	if  (!board)
	{
		printf("ERROR init_board: Something unexpected happened at 1st calloc call.\n");
		return NULL;
	}

	for (int i = 1 ; i < 9 ; i++)
	{
		board[i] = calloc (9, sizeof(struct piece *));
		if (!board[i])
		{
			for (int j = 1 ; j < i ; j++)
				free(board[j]);
			free(board);
			printf("ERROR init_board: Something unexpected happened at 2nd calloc call.\n");
			return NULL;
		}
	}
	return board;
}

// init board from board

void place_piece(struct piece ***board, struct piece *piece, int col, int line)
{
	// put original square as white/black square
	piece->column = col;
	piece->line = line;
	board[line][col] = piece;
}

// proper display
void display_board(struct piece ***board)
{
	for (int i = 1 ; i < 9 ; i++)
	{
		for (int j = 1 ; j < 9 ; j++)
		{
			printf("%i %i ", i, j);
			if (!(board[i][j]))
				printf("NULL %i\n", (i - 1) * 8 + j);
			else
				printf("%i\n", board[i][j]->type);
		}
		printf("\n");
	}
}

void clear_board(struct piece ***board)
{
	/*
	for (int i = 1 ; i < 9 ; i++)
	{
		for (int j = 1 ; j < 9 ; j++)
		{
			if (board[i][j])
				free(board[i][j]);
		}
	}
	*/
	free(board[2][6]);
}

void free_board(struct piece ***board)
{
	clear_board(board);
	free(board);
}

int main(void)
{
	struct piece ***board = init_board();
	printf("Board is %s!\n", (board == NULL ? "not initialised" : "created"));
	struct piece* king = make_piece(1, 5, KING, 1, 10, 0, 0);
	display_board(board);
	place_piece(board, king, 6, 2);
	display_board(board);
	return 0;
}
