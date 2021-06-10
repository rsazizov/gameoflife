cmake_minimum_required(VERSION 3.20)
project(gameoflife C)

set(CMAKE_C_STANDARD 11)

add_subdirectory(libansi)
add_subdirectory(liblife)

add_executable(life life.c)

target_link_libraries(life PUBLIC libansi liblife)

find_package(Doxygen)
if (DOXYGEN_FOUND)
    message("Building doc")

    add_custom_target(doc ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            COMMENT "Running Doxygen"
            VERBATIM)
else (DOXYGEN_FOUND)
    message("Doxygen was not found on this system, skipping doc build")
endif (DOXYGEN_FOUND)
