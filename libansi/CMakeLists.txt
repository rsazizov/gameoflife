add_library(libansi ansi.h ansi.c)
target_include_directories (libansi PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
