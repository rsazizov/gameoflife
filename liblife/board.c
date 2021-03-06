#include "board.h"
#include <string.h>

Board *Board_create(int width, int height) {
  Board *board = malloc(sizeof(Board));
  memset(board, 0, sizeof(*board));

  board->width = width;
  board->height = height;
  board->grid = (bool **) malloc(board->height * (sizeof(bool *)));

  for (int i = 0; i < board->height; i++) {
    board->grid[i] = (bool *) malloc(board->width * sizeof(bool));
  }

  for (int i = 0; i < board->height; i++) {
    for (int j = 0; j < board->width; j++) {
      board->grid[i][j] = 0;
    }
  }

  return board;
}

void Board_free(Board *board) {
  for (int i = 0; i < board->height; i++) {
    free(board->grid[i]);
  }

  free(board->grid);
  free(board);
}

void Board_gen_random(Board *board) {
  srand(time(NULL));

  for (int i = 0; i < board->height; i++) {
    for (int j = 0; j < board->width; j++) {
      board->grid[i][j] = rand() & 1;
    }
  }
}

int Board_count_alive_neighbours(Board *board, int i, int j, bool clip) {
  int n_alive = 0;

  static int neighbours[8][2] = {{-1, -1},
                                 {-1, 0},
                                 {-1, 1},
                                 {0,  -1},
                                 {0,  1},
                                 {1,  0},
                                 {1,  -1},
                                 {1,  1}};

  for (int k = 0; k < 8; ++k) {
    const int *idx = neighbours[k];

    int x = i + idx[0];
    int y = j + idx[1];

    if (clip) {
      if (x < 0 || y < 0 || x >= board->height || y >= board->width) {
        continue;
      }
    } else {
      if (x < 0) x += board->height;
      if (x >= board->height) x -= board->height;
      if (y < 0) y += board->width;
      if (y >= board->width) y -= board->width;
    }

    if (board->grid[x][y]) {
      n_alive++;
    }
  }

  return n_alive;
}

Board *Board_make_life(Board *board, bool clip) {
  Board *next_gen = Board_create(board->width, board->height);

  for (int i = 0; i < board->height; i++) {
    for (int j = 0; j < board->width; j++) {
      int n_alive = Board_count_alive_neighbours(board, i, j, clip);

      if (n_alive == 3) {
        next_gen->grid[i][j] = true;
      } else if (n_alive == 2 && board->grid[i][j]) {
        next_gen->grid[i][j] = true;
      } else {
        next_gen->grid[i][j] = false;
      }
    }
  }

  return next_gen;
}

bool Board_compare(Board *a, Board *b) {
  if (a->width != b->width || a->height != b->height) {
    return false;
  }

  for (size_t i = 0; i < a->height; ++i) {
    for (size_t j = 0; j < a->width; ++j) {
      if (a->grid[i][j] != b->grid[i][j]) return false;
    }
  }

  return true;
}