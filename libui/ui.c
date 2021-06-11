#include "ui.h"

void UI_draw_board(SDL_Renderer *renderer, Board *board) {
  for (size_t y = 0; y < board->height; ++y) {
    for (size_t x = 0; x < board->width; ++x) {
      if (board->grid[y][x]) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
      } else {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      }

      SDL_RenderDrawPoint(renderer, x, y);
    }
  }
}