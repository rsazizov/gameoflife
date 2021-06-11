#pragma once

#include "../liblife/board.h"
#include <SDL2/SDL.h>

/**
 * @brief Render a game of life board to a SDL renderer
 *
 * @param renderer SDL renderer to use
 * @param board Board to draw
 */
void UI_draw_board(SDL_Renderer* renderer, Board* board);