# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/clion/126/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/126/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ssoraka/Desktop/projects/malloc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ssoraka/Desktop/projects/malloc/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/malloc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/malloc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/malloc.dir/flags.make

CMakeFiles/malloc.dir/src/main.c.o: CMakeFiles/malloc.dir/flags.make
CMakeFiles/malloc.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ssoraka/Desktop/projects/malloc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/malloc.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc.dir/src/main.c.o   -c /home/ssoraka/Desktop/projects/malloc/src/main.c

CMakeFiles/malloc.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ssoraka/Desktop/projects/malloc/src/main.c > CMakeFiles/malloc.dir/src/main.c.i

CMakeFiles/malloc.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ssoraka/Desktop/projects/malloc/src/main.c -o CMakeFiles/malloc.dir/src/main.c.s

CMakeFiles/malloc.dir/src/malloc.c.o: CMakeFiles/malloc.dir/flags.make
CMakeFiles/malloc.dir/src/malloc.c.o: ../src/malloc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ssoraka/Desktop/projects/malloc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/malloc.dir/src/malloc.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc.dir/src/malloc.c.o   -c /home/ssoraka/Desktop/projects/malloc/src/malloc.c

CMakeFiles/malloc.dir/src/malloc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc.dir/src/malloc.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ssoraka/Desktop/projects/malloc/src/malloc.c > CMakeFiles/malloc.dir/src/malloc.c.i

CMakeFiles/malloc.dir/src/malloc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc.dir/src/malloc.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ssoraka/Desktop/projects/malloc/src/malloc.c -o CMakeFiles/malloc.dir/src/malloc.c.s

CMakeFiles/malloc.dir/src/my_test.c.o: CMakeFiles/malloc.dir/flags.make
CMakeFiles/malloc.dir/src/my_test.c.o: ../src/my_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ssoraka/Desktop/projects/malloc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/malloc.dir/src/my_test.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc.dir/src/my_test.c.o   -c /home/ssoraka/Desktop/projects/malloc/src/my_test.c

CMakeFiles/malloc.dir/src/my_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc.dir/src/my_test.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ssoraka/Desktop/projects/malloc/src/my_test.c > CMakeFiles/malloc.dir/src/my_test.c.i

CMakeFiles/malloc.dir/src/my_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc.dir/src/my_test.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ssoraka/Desktop/projects/malloc/src/my_test.c -o CMakeFiles/malloc.dir/src/my_test.c.s

# Object files for target malloc
malloc_OBJECTS = \
"CMakeFiles/malloc.dir/src/main.c.o" \
"CMakeFiles/malloc.dir/src/malloc.c.o" \
"CMakeFiles/malloc.dir/src/my_test.c.o"

# External object files for target malloc
malloc_EXTERNAL_OBJECTS =

malloc: CMakeFiles/malloc.dir/src/main.c.o
malloc: CMakeFiles/malloc.dir/src/malloc.c.o
malloc: CMakeFiles/malloc.dir/src/my_test.c.o
malloc: CMakeFiles/malloc.dir/build.make
malloc: CMakeFiles/malloc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ssoraka/Desktop/projects/malloc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable malloc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/malloc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/malloc.dir/build: malloc

.PHONY : CMakeFiles/malloc.dir/build

CMakeFiles/malloc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/malloc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/malloc.dir/clean

CMakeFiles/malloc.dir/depend:
	cd /home/ssoraka/Desktop/projects/malloc/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ssoraka/Desktop/projects/malloc /home/ssoraka/Desktop/projects/malloc /home/ssoraka/Desktop/projects/malloc/cmake-build-debug /home/ssoraka/Desktop/projects/malloc/cmake-build-debug /home/ssoraka/Desktop/projects/malloc/cmake-build-debug/CMakeFiles/malloc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/malloc.dir/depend

