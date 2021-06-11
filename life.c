#include "libansi/ansi.h"
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

int main(int argc, char** argv) {
  if (SDL_Init(SDL_INIT_VIDEO) >= 0) {
    printf("SDL was initialized\n");
    return 1;
  }

  if (argc != 2) {
    usage_and_die();
  }

  const char* variant = argv[1];

  if (strcmp(variant, "clip") && strcmp(variant, "circular")) {
    usage_and_die();
  }

  bool clip = strcmp(variant, "clip") != 0;

  Board *board = Board_create(10, 10);

  Board_gen_random(board);

  for (;;) {
    ansi_clear();

    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        ansi_move(i + 1, 2 * j + 1);

        if (!board->grid[i][j]) {
          ansi_black_cell();
          ansi_move(i + 1, 2 * j + 2);
          ansi_black_cell();
        } else {
          ansi_white_cell();
          ansi_move(i + 1, 2 * j + 2);
          ansi_white_cell();
        }
      }
    }

    Board *tmp = board;
    board = Board_make_life(board, clip);
    Board_free(tmp);
    fflush(stdout);

    sleep(1);
  }

  Board_free(board);

  return 0;
}
