#include "libui/ui.h"
#include "liblife/board.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "life.h"

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

bool should_quit() {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
      case SDL_WINDOWEVENT:
        return event.window.event == SDL_WINDOWEVENT_CLOSE;
      default:
        return false;
    }
  }
}

void read_board_size(size_t *width, size_t *height) {
  printf("Enter board width (in pixels): ");
  scanf("%d", width);

  printf("Enter board height (in pixels): ");
  scanf("%d", height);
}

int main(int argc, char **argv) {
  bool clip = is_clip(argc, argv);

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL error\n");
    return 1;
  }

  size_t width;
  size_t height;

  read_board_size(&width, &height);

  Board *board = Board_create(width, height);
  Board_gen_random(board);

  SDL_Window *window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                        width, height, 0);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  size_t iter = 0;
  for (;;) {
    if (should_quit()) {
      break;
    }

    char title[256];
    sprintf(title, "Game of Life: Iteration = %d", iter);

    SDL_SetWindowTitle(window, title);

    SDL_RenderClear(renderer);

    UI_draw_board(renderer, board);

    Board *tmp = board;
    board = Board_make_life(board, clip);
    Board_free(tmp);

    SDL_RenderPresent(renderer);

    SDL_Delay(10);
    iter++;
  }

  Board_free(board);

  return 0;
}
