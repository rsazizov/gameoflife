#include "board.h"
#include <string.h>

Board *Board_create(int width, int height)
{
    Board *board = malloc(sizeof(Board));
    memset(board, 0, sizeof(*board));

    board->width = width;
    board->height = height;
    board->grid = (bool **)malloc(board->height * (sizeof(bool *)));

    for (int i = 0; i < board->height; i++)
    {
        board->grid[i] = (bool *)malloc(board->width * sizeof(bool));
    }

    for (int i = 0; i < board->height; i++)
    {
        for (int j = 0; j < board->width; j++)
        {
            board->grid[i][j] = 0;
        }
    }

    return board;
}

void Board_free(Board *board)
{
    for (int i = 0; i < board->height; i++)
    {
        free(board->grid[i]);
    }

    free(board->grid);
    free(board);
}