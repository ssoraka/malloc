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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ssoraka/Desktop/project/malloc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ssoraka/Desktop/project/malloc/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/malloc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/malloc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/malloc.dir/flags.make

CMakeFiles/malloc.dir/src/main.c.o: CMakeFiles/malloc.dir/flags.make
CMakeFiles/malloc.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ssoraka/Desktop/project/malloc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/malloc.dir/src/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc.dir/src/main.c.o   -c /Users/ssoraka/Desktop/project/malloc/src/main.c

CMakeFiles/malloc.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc.dir/src/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ssoraka/Desktop/project/malloc/src/main.c > CMakeFiles/malloc.dir/src/main.c.i

CMakeFiles/malloc.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc.dir/src/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ssoraka/Desktop/project/malloc/src/main.c -o CMakeFiles/malloc.dir/src/main.c.s

CMakeFiles/malloc.dir/src/malloc.c.o: CMakeFiles/malloc.dir/flags.make
CMakeFiles/malloc.dir/src/malloc.c.o: ../src/malloc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ssoraka/Desktop/project/malloc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/malloc.dir/src/malloc.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc.dir/src/malloc.c.o   -c /Users/ssoraka/Desktop/project/malloc/src/malloc.c

CMakeFiles/malloc.dir/src/malloc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc.dir/src/malloc.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ssoraka/Desktop/project/malloc/src/malloc.c > CMakeFiles/malloc.dir/src/malloc.c.i

CMakeFiles/malloc.dir/src/malloc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc.dir/src/malloc.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ssoraka/Desktop/project/malloc/src/malloc.c -o CMakeFiles/malloc.dir/src/malloc.c.s

CMakeFiles/malloc.dir/src/debug.c.o: CMakeFiles/malloc.dir/flags.make
CMakeFiles/malloc.dir/src/debug.c.o: ../src/debug.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ssoraka/Desktop/project/malloc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/malloc.dir/src/debug.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc.dir/src/debug.c.o   -c /Users/ssoraka/Desktop/project/malloc/src/debug.c

CMakeFiles/malloc.dir/src/debug.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc.dir/src/debug.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ssoraka/Desktop/project/malloc/src/debug.c > CMakeFiles/malloc.dir/src/debug.c.i

CMakeFiles/malloc.dir/src/debug.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc.dir/src/debug.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ssoraka/Desktop/project/malloc/src/debug.c -o CMakeFiles/malloc.dir/src/debug.c.s

CMakeFiles/malloc.dir/src/from_libft.c.o: CMakeFiles/malloc.dir/flags.make
CMakeFiles/malloc.dir/src/from_libft.c.o: ../src/from_libft.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ssoraka/Desktop/project/malloc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/malloc.dir/src/from_libft.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc.dir/src/from_libft.c.o   -c /Users/ssoraka/Desktop/project/malloc/src/from_libft.c

CMakeFiles/malloc.dir/src/from_libft.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc.dir/src/from_libft.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ssoraka/Desktop/project/malloc/src/from_libft.c > CMakeFiles/malloc.dir/src/from_libft.c.i

CMakeFiles/malloc.dir/src/from_libft.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc.dir/src/from_libft.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ssoraka/Desktop/project/malloc/src/from_libft.c -o CMakeFiles/malloc.dir/src/from_libft.c.s

CMakeFiles/malloc.dir/src/free.c.o: CMakeFiles/malloc.dir/flags.make
CMakeFiles/malloc.dir/src/free.c.o: ../src/free.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ssoraka/Desktop/project/malloc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/malloc.dir/src/free.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc.dir/src/free.c.o   -c /Users/ssoraka/Desktop/project/malloc/src/free.c

CMakeFiles/malloc.dir/src/free.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc.dir/src/free.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ssoraka/Desktop/project/malloc/src/free.c > CMakeFiles/malloc.dir/src/free.c.i

CMakeFiles/malloc.dir/src/free.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc.dir/src/free.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ssoraka/Desktop/project/malloc/src/free.c -o CMakeFiles/malloc.dir/src/free.c.s

CMakeFiles/malloc.dir/src/show_alloc_mem.c.o: CMakeFiles/malloc.dir/flags.make
CMakeFiles/malloc.dir/src/show_alloc_mem.c.o: ../src/show_alloc_mem.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ssoraka/Desktop/project/malloc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/malloc.dir/src/show_alloc_mem.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc.dir/src/show_alloc_mem.c.o   -c /Users/ssoraka/Desktop/project/malloc/src/show_alloc_mem.c

CMakeFiles/malloc.dir/src/show_alloc_mem.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc.dir/src/show_alloc_mem.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ssoraka/Desktop/project/malloc/src/show_alloc_mem.c > CMakeFiles/malloc.dir/src/show_alloc_mem.c.i

CMakeFiles/malloc.dir/src/show_alloc_mem.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc.dir/src/show_alloc_mem.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ssoraka/Desktop/project/malloc/src/show_alloc_mem.c -o CMakeFiles/malloc.dir/src/show_alloc_mem.c.s

CMakeFiles/malloc.dir/src/store.c.o: CMakeFiles/malloc.dir/flags.make
CMakeFiles/malloc.dir/src/store.c.o: ../src/store.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ssoraka/Desktop/project/malloc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/malloc.dir/src/store.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc.dir/src/store.c.o   -c /Users/ssoraka/Desktop/project/malloc/src/store.c

CMakeFiles/malloc.dir/src/store.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc.dir/src/store.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ssoraka/Desktop/project/malloc/src/store.c > CMakeFiles/malloc.dir/src/store.c.i

CMakeFiles/malloc.dir/src/store.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc.dir/src/store.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ssoraka/Desktop/project/malloc/src/store.c -o CMakeFiles/malloc.dir/src/store.c.s

CMakeFiles/malloc.dir/src/page.c.o: CMakeFiles/malloc.dir/flags.make
CMakeFiles/malloc.dir/src/page.c.o: ../src/page.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ssoraka/Desktop/project/malloc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/malloc.dir/src/page.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc.dir/src/page.c.o   -c /Users/ssoraka/Desktop/project/malloc/src/page.c

CMakeFiles/malloc.dir/src/page.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc.dir/src/page.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ssoraka/Desktop/project/malloc/src/page.c > CMakeFiles/malloc.dir/src/page.c.i

CMakeFiles/malloc.dir/src/page.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc.dir/src/page.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ssoraka/Desktop/project/malloc/src/page.c -o CMakeFiles/malloc.dir/src/page.c.s

CMakeFiles/malloc.dir/src/root.c.o: CMakeFiles/malloc.dir/flags.make
CMakeFiles/malloc.dir/src/root.c.o: ../src/root.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ssoraka/Desktop/project/malloc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/malloc.dir/src/root.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/malloc.dir/src/root.c.o   -c /Users/ssoraka/Desktop/project/malloc/src/root.c

CMakeFiles/malloc.dir/src/root.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/malloc.dir/src/root.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ssoraka/Desktop/project/malloc/src/root.c > CMakeFiles/malloc.dir/src/root.c.i

CMakeFiles/malloc.dir/src/root.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/malloc.dir/src/root.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ssoraka/Desktop/project/malloc/src/root.c -o CMakeFiles/malloc.dir/src/root.c.s

# Object files for target malloc
malloc_OBJECTS = \
"CMakeFiles/malloc.dir/src/main.c.o" \
"CMakeFiles/malloc.dir/src/malloc.c.o" \
"CMakeFiles/malloc.dir/src/debug.c.o" \
"CMakeFiles/malloc.dir/src/from_libft.c.o" \
"CMakeFiles/malloc.dir/src/free.c.o" \
"CMakeFiles/malloc.dir/src/show_alloc_mem.c.o" \
"CMakeFiles/malloc.dir/src/store.c.o" \
"CMakeFiles/malloc.dir/src/page.c.o" \
"CMakeFiles/malloc.dir/src/root.c.o"

# External object files for target malloc
malloc_EXTERNAL_OBJECTS =

malloc: CMakeFiles/malloc.dir/src/main.c.o
malloc: CMakeFiles/malloc.dir/src/malloc.c.o
malloc: CMakeFiles/malloc.dir/src/debug.c.o
malloc: CMakeFiles/malloc.dir/src/from_libft.c.o
malloc: CMakeFiles/malloc.dir/src/free.c.o
malloc: CMakeFiles/malloc.dir/src/show_alloc_mem.c.o
malloc: CMakeFiles/malloc.dir/src/store.c.o
malloc: CMakeFiles/malloc.dir/src/page.c.o
malloc: CMakeFiles/malloc.dir/src/root.c.o
malloc: CMakeFiles/malloc.dir/build.make
malloc: CMakeFiles/malloc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ssoraka/Desktop/project/malloc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable malloc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/malloc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/malloc.dir/build: malloc

.PHONY : CMakeFiles/malloc.dir/build

CMakeFiles/malloc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/malloc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/malloc.dir/clean

CMakeFiles/malloc.dir/depend:
	cd /Users/ssoraka/Desktop/project/malloc/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ssoraka/Desktop/project/malloc /Users/ssoraka/Desktop/project/malloc /Users/ssoraka/Desktop/project/malloc/cmake-build-debug /Users/ssoraka/Desktop/project/malloc/cmake-build-debug /Users/ssoraka/Desktop/project/malloc/cmake-build-debug/CMakeFiles/malloc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/malloc.dir/depend

