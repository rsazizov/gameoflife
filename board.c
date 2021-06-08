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

void Board_gen_random(Board *board)
{
    srand(time(NULL));

    for (int i = 0; i < board->height; i++)
    {
        for (int j = 0; j < board->width; j++)
        {
            board->grid[i][j] = rand() & 1;
        }
    }
}

int count_alive_neighbours(Board *board, int i, int j)
{
    int n_alive = 0;

    static int neighbours[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, 0}, {1, -1}, {1, 1}};

    for (int k = 0; k < 8; ++k)
    {
        const int *idx = neighbours[k];

        int x = i + idx[0];
        int y = j + idx[1];

        if (x < 0 || y < 0 || x >= board->height || y >= board->width)
        {
            continue;
        }

        if (board->grid[x][y])
        {
            n_alive++;
        }
    }

    return n_alive;
}

Board *Board_make_life(Board *board)
{
    Board *next_gen = Board_create(board->width, board->height);

    for (int i = 0; i < board->height; i++)
    {
        for (int j = 0; j < board->width; j++)
        {
            int n_alive = count_alive_neighbours(board, i, j);

            if (n_alive == 3)
            {
                next_gen->grid[i][j] = true;
            }
            else if (n_alive == 2 && board->grid[i][j])
            {
                next_gen->grid[i][j] = true;
            }
            else
            {
                next_gen->grid[i][j] = false;
            }
        }
    }

    return next_gen;
}