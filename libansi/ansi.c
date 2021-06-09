#include <stdio.h>

void ansi_white_cell() {
  printf("\x1b[47m ");
  printf("\x1b[0;0m");
}

void ansi_black_cell() {
  printf("\x1b[40m ");
  printf("\x1b[0;0m");
}

void ansi_clear() {
  printf("\033[2J");
}

void ansi_move(int i, int j) {
  printf("\033[%d;%dH", i, j);
}
