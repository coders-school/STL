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
CMAKE_COMMAND = /snap/clion/124/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/124/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dell/stl/module4/homework/appendNewRecipe

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dell/stl/module4/homework/appendNewRecipe/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AppendNewRecipe-ut.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AppendNewRecipe-ut.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AppendNewRecipe-ut.dir/flags.make

CMakeFiles/AppendNewRecipe-ut.dir/test.cpp.o: CMakeFiles/AppendNewRecipe-ut.dir/flags.make
CMakeFiles/AppendNewRecipe-ut.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dell/stl/module4/homework/appendNewRecipe/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AppendNewRecipe-ut.dir/test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AppendNewRecipe-ut.dir/test.cpp.o -c /home/dell/stl/module4/homework/appendNewRecipe/test.cpp

CMakeFiles/AppendNewRecipe-ut.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AppendNewRecipe-ut.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dell/stl/module4/homework/appendNewRecipe/test.cpp > CMakeFiles/AppendNewRecipe-ut.dir/test.cpp.i

CMakeFiles/AppendNewRecipe-ut.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AppendNewRecipe-ut.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dell/stl/module4/homework/appendNewRecipe/test.cpp -o CMakeFiles/AppendNewRecipe-ut.dir/test.cpp.s

CMakeFiles/AppendNewRecipe-ut.dir/AppendNewRecipe.cpp.o: CMakeFiles/AppendNewRecipe-ut.dir/flags.make
CMakeFiles/AppendNewRecipe-ut.dir/AppendNewRecipe.cpp.o: ../AppendNewRecipe.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dell/stl/module4/homework/appendNewRecipe/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/AppendNewRecipe-ut.dir/AppendNewRecipe.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AppendNewRecipe-ut.dir/AppendNewRecipe.cpp.o -c /home/dell/stl/module4/homework/appendNewRecipe/AppendNewRecipe.cpp

CMakeFiles/AppendNewRecipe-ut.dir/AppendNewRecipe.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AppendNewRecipe-ut.dir/AppendNewRecipe.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dell/stl/module4/homework/appendNewRecipe/AppendNewRecipe.cpp > CMakeFiles/AppendNewRecipe-ut.dir/AppendNewRecipe.cpp.i

CMakeFiles/AppendNewRecipe-ut.dir/AppendNewRecipe.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AppendNewRecipe-ut.dir/AppendNewRecipe.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dell/stl/module4/homework/appendNewRecipe/AppendNewRecipe.cpp -o CMakeFiles/AppendNewRecipe-ut.dir/AppendNewRecipe.cpp.s

# Object files for target AppendNewRecipe-ut
AppendNewRecipe__ut_OBJECTS = \
"CMakeFiles/AppendNewRecipe-ut.dir/test.cpp.o" \
"CMakeFiles/AppendNewRecipe-ut.dir/AppendNewRecipe.cpp.o"

# External object files for target AppendNewRecipe-ut
AppendNewRecipe__ut_EXTERNAL_OBJECTS =

AppendNewRecipe-ut: CMakeFiles/AppendNewRecipe-ut.dir/test.cpp.o
AppendNewRecipe-ut: CMakeFiles/AppendNewRecipe-ut.dir/AppendNewRecipe.cpp.o
AppendNewRecipe-ut: CMakeFiles/AppendNewRecipe-ut.dir/build.make
AppendNewRecipe-ut: lib/libgtest_maind.a
AppendNewRecipe-ut: lib/libgtestd.a
AppendNewRecipe-ut: CMakeFiles/AppendNewRecipe-ut.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dell/stl/module4/homework/appendNewRecipe/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable AppendNewRecipe-ut"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AppendNewRecipe-ut.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AppendNewRecipe-ut.dir/build: AppendNewRecipe-ut

.PHONY : CMakeFiles/AppendNewRecipe-ut.dir/build

CMakeFiles/AppendNewRecipe-ut.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AppendNewRecipe-ut.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AppendNewRecipe-ut.dir/clean

CMakeFiles/AppendNewRecipe-ut.dir/depend:
	cd /home/dell/stl/module4/homework/appendNewRecipe/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dell/stl/module4/homework/appendNewRecipe /home/dell/stl/module4/homework/appendNewRecipe /home/dell/stl/module4/homework/appendNewRecipe/cmake-build-debug /home/dell/stl/module4/homework/appendNewRecipe/cmake-build-debug /home/dell/stl/module4/homework/appendNewRecipe/cmake-build-debug/CMakeFiles/AppendNewRecipe-ut.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AppendNewRecipe-ut.dir/depend
