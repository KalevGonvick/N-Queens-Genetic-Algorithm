# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\kalev\CLionProjects\NQueensGA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\kalev\CLionProjects\NQueensGA\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/NQueensGA.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NQueensGA.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NQueensGA.dir/flags.make

CMakeFiles/NQueensGA.dir/main.cpp.obj: CMakeFiles/NQueensGA.dir/flags.make
CMakeFiles/NQueensGA.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kalev\CLionProjects\NQueensGA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NQueensGA.dir/main.cpp.obj"
	C:\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\NQueensGA.dir\main.cpp.obj -c C:\Users\kalev\CLionProjects\NQueensGA\main.cpp

CMakeFiles/NQueensGA.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NQueensGA.dir/main.cpp.i"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kalev\CLionProjects\NQueensGA\main.cpp > CMakeFiles\NQueensGA.dir\main.cpp.i

CMakeFiles/NQueensGA.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NQueensGA.dir/main.cpp.s"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kalev\CLionProjects\NQueensGA\main.cpp -o CMakeFiles\NQueensGA.dir\main.cpp.s

# Object files for target NQueensGA
NQueensGA_OBJECTS = \
"CMakeFiles/NQueensGA.dir/main.cpp.obj"

# External object files for target NQueensGA
NQueensGA_EXTERNAL_OBJECTS =

NQueensGA.exe: CMakeFiles/NQueensGA.dir/main.cpp.obj
NQueensGA.exe: CMakeFiles/NQueensGA.dir/build.make
NQueensGA.exe: CMakeFiles/NQueensGA.dir/linklibs.rsp
NQueensGA.exe: CMakeFiles/NQueensGA.dir/objects1.rsp
NQueensGA.exe: CMakeFiles/NQueensGA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\kalev\CLionProjects\NQueensGA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable NQueensGA.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\NQueensGA.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NQueensGA.dir/build: NQueensGA.exe

.PHONY : CMakeFiles/NQueensGA.dir/build

CMakeFiles/NQueensGA.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\NQueensGA.dir\cmake_clean.cmake
.PHONY : CMakeFiles/NQueensGA.dir/clean

CMakeFiles/NQueensGA.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\kalev\CLionProjects\NQueensGA C:\Users\kalev\CLionProjects\NQueensGA C:\Users\kalev\CLionProjects\NQueensGA\cmake-build-debug C:\Users\kalev\CLionProjects\NQueensGA\cmake-build-debug C:\Users\kalev\CLionProjects\NQueensGA\cmake-build-debug\CMakeFiles\NQueensGA.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NQueensGA.dir/depend
