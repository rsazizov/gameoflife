#include "libansi/ansi.h"
#include "liblife/board.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
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
    board = Board_make_life(board, false);
    Board_free(tmp);
    fflush(stdout);

    sleep(1);
  }

  Board_free(board);

  return 0;
}
