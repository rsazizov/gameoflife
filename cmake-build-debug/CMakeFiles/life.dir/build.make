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
include CMakeFiles/life.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/life.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/life.dir/flags.make

CMakeFiles/life.dir/life.c.o: CMakeFiles/life.dir/flags.make
CMakeFiles/life.dir/life.c.o: ../life.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rsazizov/git/gameoflife/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/life.dir/life.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/life.dir/life.c.o -c /home/rsazizov/git/gameoflife/life.c

CMakeFiles/life.dir/life.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/life.dir/life.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rsazizov/git/gameoflife/life.c > CMakeFiles/life.dir/life.c.i

CMakeFiles/life.dir/life.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/life.dir/life.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rsazizov/git/gameoflife/life.c -o CMakeFiles/life.dir/life.c.s

# Object files for target life
life_OBJECTS = \
"CMakeFiles/life.dir/life.c.o"

# External object files for target life
life_EXTERNAL_OBJECTS =

life: CMakeFiles/life.dir/life.c.o
life: CMakeFiles/life.dir/build.make
life: libansi/liblibansi.a
life: liblife/libliblife.a
life: CMakeFiles/life.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rsazizov/git/gameoflife/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable life"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/life.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/life.dir/build: life
.PHONY : CMakeFiles/life.dir/build

CMakeFiles/life.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/life.dir/cmake_clean.cmake
.PHONY : CMakeFiles/life.dir/clean

CMakeFiles/life.dir/depend:
	cd /home/rsazizov/git/gameoflife/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rsazizov/git/gameoflife /home/rsazizov/git/gameoflife /home/rsazizov/git/gameoflife/cmake-build-debug /home/rsazizov/git/gameoflife/cmake-build-debug /home/rsazizov/git/gameoflife/cmake-build-debug/CMakeFiles/life.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/life.dir/depend

