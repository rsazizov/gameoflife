add_library(liblife board.h board.c)
target_include_directories (liblife PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})