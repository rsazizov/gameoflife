#include <CUnit/Basic.h>

#include "common.h"
#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <errno.h>
#include "server.h"
#include "client.h"
#include <sys/select.h>

static int init_suite() { return 0; }

static int clean_suite() { return 0; }

void test_dummy() {
  CU_ASSERT(1);
}

int main() {
  if (CUE_SUCCESS != CU_initialize_registry()) {
    return CU_get_error();
  }

  CU_pSuite suite = CU_add_suite("Suite_1", init_suite, clean_suite);

  if (!suite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if ((NULL == CU_add_test(suite, "Client can read pid", test_dummy))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();

  return CU_get_error();
}
