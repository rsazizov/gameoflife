#include "ansi.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  ansi_clear();

  for (int i = 1; i <= 10; ++i) {
    for (int j = 1; j <= 20; j += 2) {
      ansi_move(i, j);

      if (rand() & 1) {
        ansi_black_cell();
        ansi_move(i, j + 1);
        ansi_black_cell();
      } else {
        ansi_white_cell();
        ansi_move(i, j + 1);
        ansi_white_cell();
      }
    }
  }

  return 0;
}
