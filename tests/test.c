#include <CUnit/Basic.h>

#include <unistd.h>
#include "../liblife/board.h"

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
      (NULL == CU_add_test(suite, "Toad", test_toad))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();

  return CU_get_error();
}
