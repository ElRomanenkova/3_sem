# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/82/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/82/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/liza/CLionProjects/my_cat

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liza/CLionProjects/my_cat/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/my_cat.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_cat.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_cat.dir/flags.make

CMakeFiles/my_cat.dir/main.c.o: CMakeFiles/my_cat.dir/flags.make
CMakeFiles/my_cat.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liza/CLionProjects/my_cat/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/my_cat.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/my_cat.dir/main.c.o   -c /home/liza/CLionProjects/my_cat/main.c

CMakeFiles/my_cat.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_cat.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/liza/CLionProjects/my_cat/main.c > CMakeFiles/my_cat.dir/main.c.i

CMakeFiles/my_cat.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_cat.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/liza/CLionProjects/my_cat/main.c -o CMakeFiles/my_cat.dir/main.c.s

# Object files for target my_cat
my_cat_OBJECTS = \
"CMakeFiles/my_cat.dir/main.c.o"

# External object files for target my_cat
my_cat_EXTERNAL_OBJECTS =

my_cat: CMakeFiles/my_cat.dir/main.c.o
my_cat: CMakeFiles/my_cat.dir/build.make
my_cat: CMakeFiles/my_cat.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liza/CLionProjects/my_cat/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable my_cat"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_cat.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_cat.dir/build: my_cat

.PHONY : CMakeFiles/my_cat.dir/build

CMakeFiles/my_cat.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_cat.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_cat.dir/clean

CMakeFiles/my_cat.dir/depend:
	cd /home/liza/CLionProjects/my_cat/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liza/CLionProjects/my_cat /home/liza/CLionProjects/my_cat /home/liza/CLionProjects/my_cat/cmake-build-debug /home/liza/CLionProjects/my_cat/cmake-build-debug /home/liza/CLionProjects/my_cat/cmake-build-debug/CMakeFiles/my_cat.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_cat.dir/depend

