# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rsazizov/git/gameoflife

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rsazizov/git/gameoflife/cmake-build-debug

# Include any dependencies generated for this target.
include liblife/CMakeFiles/liblife.dir/depend.make
# Include the progress variables for this target.
include liblife/CMakeFiles/liblife.dir/progress.make

# Include the compile flags for this target's objects.
include liblife/CMakeFiles/liblife.dir/flags.make

liblife/CMakeFiles/liblife.dir/board.c.o: liblife/CMakeFiles/liblife.dir/flags.make
liblife/CMakeFiles/liblife.dir/board.c.o: ../liblife/board.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rsazizov/git/gameoflife/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object liblife/CMakeFiles/liblife.dir/board.c.o"
	cd /home/rsazizov/git/gameoflife/cmake-build-debug/liblife && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/liblife.dir/board.c.o -c /home/rsazizov/git/gameoflife/liblife/board.c

liblife/CMakeFiles/liblife.dir/board.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/liblife.dir/board.c.i"
	cd /home/rsazizov/git/gameoflife/cmake-build-debug/liblife && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rsazizov/git/gameoflife/liblife/board.c > CMakeFiles/liblife.dir/board.c.i

liblife/CMakeFiles/liblife.dir/board.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/liblife.dir/board.c.s"
	cd /home/rsazizov/git/gameoflife/cmake-build-debug/liblife && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rsazizov/git/gameoflife/liblife/board.c -o CMakeFiles/liblife.dir/board.c.s

# Object files for target liblife
liblife_OBJECTS = \
"CMakeFiles/liblife.dir/board.c.o"

# External object files for target liblife
liblife_EXTERNAL_OBJECTS =

liblife/libliblife.a: liblife/CMakeFiles/liblife.dir/board.c.o
liblife/libliblife.a: liblife/CMakeFiles/liblife.dir/build.make
liblife/libliblife.a: liblife/CMakeFiles/liblife.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rsazizov/git/gameoflife/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libliblife.a"
	cd /home/rsazizov/git/gameoflife/cmake-build-debug/liblife && $(CMAKE_COMMAND) -P CMakeFiles/liblife.dir/cmake_clean_target.cmake
	cd /home/rsazizov/git/gameoflife/cmake-build-debug/liblife && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/liblife.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
liblife/CMakeFiles/liblife.dir/build: liblife/libliblife.a
.PHONY : liblife/CMakeFiles/liblife.dir/build

liblife/CMakeFiles/liblife.dir/clean:
	cd /home/rsazizov/git/gameoflife/cmake-build-debug/liblife && $(CMAKE_COMMAND) -P CMakeFiles/liblife.dir/cmake_clean.cmake
.PHONY : liblife/CMakeFiles/liblife.dir/clean

liblife/CMakeFiles/liblife.dir/depend:
	cd /home/rsazizov/git/gameoflife/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rsazizov/git/gameoflife /home/rsazizov/git/gameoflife/liblife /home/rsazizov/git/gameoflife/cmake-build-debug /home/rsazizov/git/gameoflife/cmake-build-debug/liblife /home/rsazizov/git/gameoflife/cmake-build-debug/liblife/CMakeFiles/liblife.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : liblife/CMakeFiles/liblife.dir/depend

