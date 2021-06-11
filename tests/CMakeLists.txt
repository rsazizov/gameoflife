include(FindPkgConfig)

pkg_search_module(CUNIT cunit)

if (CUNIT_FOUND)
    message("Found CUnit, adding test target...")

    add_executable(test test.c)
    add_dependencies(test liblife)

    target_link_libraries(test PUBLIC cunit)
else (CUNIT_FOUND)
    message("CUnit was not found on the system, tests are not going to be built....")
endif (CUNIT_FOUND)

