#include <CUnit/Basic.h>

#include "../liblife/board.h"

/**
 * @brief Simulate game of life for several iterations
 *
 * @param board Board to simulate
 * @param iters Number of iterations to simulate
 * @param clip see Board_make_life
 *
 * @return Board that is result of iters iterations
 */
Board *make_life_iters(Board *board, size_t iters, bool clip) {
  for (size_t i = 0; i < iters; ++i) {
    board = Board_make_life(board, clip);
  }

  return board;
}

static int init_suite() { return 0; }

static int clean_suite() { return 0; }

/**
 * @brief Test blinker pattern
 *
 * https://cs.stanford.edu/people/eroberts/courses/soco/projects/2001-02/cellular-automata/oscillators/blinker.gif
 */
void test_blinker() {
  Board *result = Board_create(3, 3);

  result->grid[0][1] = true;
  result->grid[1][1] = true;
  result->grid[2][1] = true;

  Board *start = Board_create(3, 3);

  start->grid[1][0] = true;
  start->grid[1][1] = true;
  start->grid[1][2] = true;

  start = Board_make_life(start, true);

  CU_ASSERT(Board_compare(start, result));
}

/**
 * @brief Test toad
 *
 * https://cs.stanford.edu/people/eroberts/courses/soco/projects/2001-02/cellular-automata/oscillators/toad.gif
 */
void test_toad() {
  Board *result = Board_create(4, 4);

  result->grid[1][0] = true;
  result->grid[2][0] = true;
  result->grid[3][1] = true;

  result->grid[0][2] = true;
  result->grid[1][3] = true;
  result->grid[2][3] = true;

  Board *start = Board_create(4, 4);

  start->grid[2][0] = true;
  start->grid[2][1] = true;
  start->grid[2][2] = true;

  start->grid[1][1] = true;
  start->grid[1][2] = true;
  start->grid[1][3] = true;

  start = Board_make_life(start, true);

  CU_ASSERT(Board_compare(start, result));
}

Board *make_glider() {
  Board *glider = Board_create(4, 4);

  glider->grid[1][0] = true;
  glider->grid[2][1] = true;
  glider->grid[2][2] = true;
  glider->grid[1][2] = true;
  glider->grid[0][2] = true;

  return glider;
}

/**
 * @brief Test glider pattern (1st pattern)
 *
 * https://www.researchgate.net/figure/Subsequent-stages-of-the-glider-pattern-on-Conways-Game-of-Life-cellular-automaton-grid_fig1_263596638
 */
void test_glider_1() {
  Board *result = Board_create(4, 4);

  result->grid[0][1] = true;
  result->grid[1][2] = true;
  result->grid[1][3] = true;
  result->grid[2][2] = true;
  result->grid[2][1] = true;

  Board *start = make_glider();

  start = Board_make_life(start, true);

  CU_ASSERT(Board_compare(start, result));
}

/**
 * @brief Test glider pattern (2nd pattern)
 *
 * https://www.researchgate.net/figure/Subsequent-stages-of-the-glider-pattern-on-Conways-Game-of-Life-cellular-automaton-grid_fig1_263596638
 */
void test_glider_2() {
  Board *result = Board_create(4, 4);

  result->grid[0][2] = true;
  result->grid[2][3] = true;
  result->grid[1][3] = true;
  result->grid[2][2] = true;
  result->grid[2][1] = true;

  Board *start = make_glider();

  start = make_life_iters(start, 2, true);

  CU_ASSERT(Board_compare(start, result));
}

int main() {
  if (CUE_SUCCESS != CU_initialize_registry()) {
    return CU_get_error();
  }

  CU_pSuite suite = CU_add_suite("Patterns", init_suite, clean_suite);

  if (!suite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(suite, "Blinker", test_blinker)) ||
      (NULL == CU_add_test(suite, "Toad", test_toad)) ||
      (NULL == CU_add_test(suite, "Glider 1", test_glider_1)) ||
      (NULL == CU_add_test(suite, "Glider 2", test_glider_2))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();

  return CU_get_error();
}
