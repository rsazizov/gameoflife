#pragma once

/**
 *
 * @brief Pain the current character white
 *
 * Apply white background and print " "
 *
 */
void ansi_white_cell();

/**
 *
 * @brief Paint the current character black
 *
 * Apply black background and print " "
 *
 */
void ansi_black_cell();

/**
 *
 * @brief Clear screen and go to (1, 1)
 *
 */
void ansi_clear();

/**
 *
 * @brief Move the cursor to line i and col j
 *
 * @param i Line of the cursor
 * @param j Column of the cursor
 */
void ansi_move(int i, int j);
