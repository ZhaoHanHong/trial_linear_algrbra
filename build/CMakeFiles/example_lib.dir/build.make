# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\ZHH2\Downloads\trial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\ZHH2\Downloads\trial\build

# Include any dependencies generated for this target.
include CMakeFiles/example_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/example_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/example_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/example_lib.dir/flags.make

CMakeFiles/example_lib.dir/src/matrix.cpp.obj: CMakeFiles/example_lib.dir/flags.make
CMakeFiles/example_lib.dir/src/matrix.cpp.obj: CMakeFiles/example_lib.dir/includes_CXX.rsp
CMakeFiles/example_lib.dir/src/matrix.cpp.obj: C:/Users/ZHH2/Downloads/trial/src/matrix.cpp
CMakeFiles/example_lib.dir/src/matrix.cpp.obj: CMakeFiles/example_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\ZHH2\Downloads\trial\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/example_lib.dir/src/matrix.cpp.obj"
	D:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/example_lib.dir/src/matrix.cpp.obj -MF CMakeFiles\example_lib.dir\src\matrix.cpp.obj.d -o CMakeFiles\example_lib.dir\src\matrix.cpp.obj -c C:\Users\ZHH2\Downloads\trial\src\matrix.cpp

CMakeFiles/example_lib.dir/src/matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/example_lib.dir/src/matrix.cpp.i"
	D:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ZHH2\Downloads\trial\src\matrix.cpp > CMakeFiles\example_lib.dir\src\matrix.cpp.i

CMakeFiles/example_lib.dir/src/matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/example_lib.dir/src/matrix.cpp.s"
	D:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ZHH2\Downloads\trial\src\matrix.cpp -o CMakeFiles\example_lib.dir\src\matrix.cpp.s

CMakeFiles/example_lib.dir/src/poly.cpp.obj: CMakeFiles/example_lib.dir/flags.make
CMakeFiles/example_lib.dir/src/poly.cpp.obj: CMakeFiles/example_lib.dir/includes_CXX.rsp
CMakeFiles/example_lib.dir/src/poly.cpp.obj: C:/Users/ZHH2/Downloads/trial/src/poly.cpp
CMakeFiles/example_lib.dir/src/poly.cpp.obj: CMakeFiles/example_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\ZHH2\Downloads\trial\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/example_lib.dir/src/poly.cpp.obj"
	D:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/example_lib.dir/src/poly.cpp.obj -MF CMakeFiles\example_lib.dir\src\poly.cpp.obj.d -o CMakeFiles\example_lib.dir\src\poly.cpp.obj -c C:\Users\ZHH2\Downloads\trial\src\poly.cpp

CMakeFiles/example_lib.dir/src/poly.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/example_lib.dir/src/poly.cpp.i"
	D:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ZHH2\Downloads\trial\src\poly.cpp > CMakeFiles\example_lib.dir\src\poly.cpp.i

CMakeFiles/example_lib.dir/src/poly.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/example_lib.dir/src/poly.cpp.s"
	D:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ZHH2\Downloads\trial\src\poly.cpp -o CMakeFiles\example_lib.dir\src\poly.cpp.s

# Object files for target example_lib
example_lib_OBJECTS = \
"CMakeFiles/example_lib.dir/src/matrix.cpp.obj" \
"CMakeFiles/example_lib.dir/src/poly.cpp.obj"

# External object files for target example_lib
example_lib_EXTERNAL_OBJECTS =

libexample_lib.a: CMakeFiles/example_lib.dir/src/matrix.cpp.obj
libexample_lib.a: CMakeFiles/example_lib.dir/src/poly.cpp.obj
libexample_lib.a: CMakeFiles/example_lib.dir/build.make
libexample_lib.a: CMakeFiles/example_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\ZHH2\Downloads\trial\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libexample_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles\example_lib.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\example_lib.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/example_lib.dir/build: libexample_lib.a
.PHONY : CMakeFiles/example_lib.dir/build

CMakeFiles/example_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\example_lib.dir\cmake_clean.cmake
.PHONY : CMakeFiles/example_lib.dir/clean

CMakeFiles/example_lib.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\ZHH2\Downloads\trial C:\Users\ZHH2\Downloads\trial C:\Users\ZHH2\Downloads\trial\build C:\Users\ZHH2\Downloads\trial\build C:\Users\ZHH2\Downloads\trial\build\CMakeFiles\example_lib.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/example_lib.dir/depend

