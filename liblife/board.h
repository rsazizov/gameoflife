#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Representation of a board
 *
 */
typedef struct board {
    int height;  /**< Height of the board (in cells) */
    int width;   /**< Width of the board (in cells) */
    bool **grid; /**< The grid itself (pointers to pointers */
} Board;

/**
 * @brief Generate a new board of size width x height
 *
 * @param width Width of the board (in cells)
 * @param height Height of the board (in cells)
 *
 * @return Pointer to the created board
 *
 */
Board *Board_create(int width, int height);

/**
 *
 * @brief Free an allocated board
 *
 * @param board Board to free
 */
void Board_free(Board *board);

/**
 *
 * @brief Randomize a board (in-place)
 *
 * @param board Board to randomize
 *
 */
void Board_gen_random(Board *board);

/**
 *
 * @brief Count alive neighbours according to the rules of life
 *
 * @param board Board to use
 * @param i Row of the cell to be counted
 * @param j Column of the cell to be counted
 * @param clip Clip the board when calculating alive neighbours
 * @return Number of alive neighbours
 *
 */
int Board_count_alive_neighbours(Board *board, int i, int j, bool clip);

/**
 *
 * @brief Run the game for 1 epoch according to the rules of the game
 *
 * Input board is not modified
 *
 * @param board Board to use
 * @param clip Clip the board when calculating alive neighbours
 * @return A new board that is the result of applying the rules to the board
 *
 */
Board *Board_make_life(Board *board, bool clip);