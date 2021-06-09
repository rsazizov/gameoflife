cmake_minimum_required(VERSION 3.20)
project(gameoflife C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(libansi)
add_subdirectory(liblife)

add_executable(life life.c)

target_link_libraries(life PUBLIC libansi liblife)