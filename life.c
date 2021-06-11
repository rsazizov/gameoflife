#include "libui/ui.h"
#include "liblife/board.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <unistd.h>

void usage_and_die() {
  printf("Usage: life <clip|circular>\n");
  exit(1);
}

bool is_clip(int argc, char **argv) {
  if (argc != 2) {
    usage_and_die();
  }

  const char *variant = argv[1];

  if (strcmp(variant, "clip") && strcmp(variant, "circular")) {
    usage_and_die();
  }

  return strcmp(variant, "clip") != 0;
}

int main(int argc, char **argv) {
  bool clip = true; //is_clip(argc, argv);

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL error\n");
    return 1;
  }

  size_t width = 640;
  size_t height = 480;

  Board *board = Board_create(width, height);
  Board_gen_random(board);

  SDL_Window *window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height,
                                        0);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  for (;;) {
    SDL_RenderClear(renderer);

    Board *tmp = board;
    board = Board_make_life(board, clip);
    Board_free(tmp);

    UI_draw_board(renderer, board);

    SDL_RenderPresent(renderer);
  }

  Board_free(board);

  return 0;
}
