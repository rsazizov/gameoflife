cmake_minimum_required(VERSION 3.20)
project(gameoflife C)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

set(CMAKE_C_STANDARD 11)

set(DIST "dist.tar.gz")
set(DOC "doc")

add_subdirectory(libui)
add_subdirectory(liblife)
add_subdirectory(tests)

add_executable(life life.c life.h)

target_link_libraries(life libui liblife SDL2::SDL2)
target_include_directories(life PUBLIC ${CMAKE_SOURCE_DIR})

# Doxygen target

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

# Build a list of source files for dist
file(GLOB_RECURSE SOURCE_FILES
        "*.h"
        "*.c"
        )

# Remove CMake garbage
list(FILTER SOURCE_FILES EXCLUDE REGEX ".*CMake*")

# Dist target
set(DIST_TARGETS
        ${DOC} ${CMAKE_BINARY_DIR}/life ${SOURCE_FILES}
        )

add_custom_target(dist ALL
        COMMAND realpath --relative-to=${CMAKE_CURRENT_SOURCE_DIR} ${DIST_TARGETS} | xargs tar -czf ${DIST}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Compressing dist"
        VERBATIM)

add_dependencies(dist doc life)