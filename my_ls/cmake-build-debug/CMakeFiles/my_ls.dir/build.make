# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /snap/clion/98/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/98/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/liza/CLionProjects/my_ls

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/liza/CLionProjects/my_ls/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/my_ls.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_ls.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_ls.dir/flags.make

CMakeFiles/my_ls.dir/main.c.o: CMakeFiles/my_ls.dir/flags.make
CMakeFiles/my_ls.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/liza/CLionProjects/my_ls/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/my_ls.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/my_ls.dir/main.c.o   -c /home/liza/CLionProjects/my_ls/main.c

CMakeFiles/my_ls.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/my_ls.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/liza/CLionProjects/my_ls/main.c > CMakeFiles/my_ls.dir/main.c.i

CMakeFiles/my_ls.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/my_ls.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/liza/CLionProjects/my_ls/main.c -o CMakeFiles/my_ls.dir/main.c.s

# Object files for target my_ls
my_ls_OBJECTS = \
"CMakeFiles/my_ls.dir/main.c.o"

# External object files for target my_ls
my_ls_EXTERNAL_OBJECTS =

my_ls: CMakeFiles/my_ls.dir/main.c.o
my_ls: CMakeFiles/my_ls.dir/build.make
my_ls: CMakeFiles/my_ls.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/liza/CLionProjects/my_ls/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable my_ls"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_ls.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_ls.dir/build: my_ls

.PHONY : CMakeFiles/my_ls.dir/build

CMakeFiles/my_ls.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_ls.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_ls.dir/clean

CMakeFiles/my_ls.dir/depend:
	cd /home/liza/CLionProjects/my_ls/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/liza/CLionProjects/my_ls /home/liza/CLionProjects/my_ls /home/liza/CLionProjects/my_ls/cmake-build-debug /home/liza/CLionProjects/my_ls/cmake-build-debug /home/liza/CLionProjects/my_ls/cmake-build-debug/CMakeFiles/my_ls.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_ls.dir/depend

