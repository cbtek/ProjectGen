# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = C:\Dev\tools\cmake\bin\cmake.exe

# The command to remove a file.
RM = C:\Dev\tools\cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Dev\CBTek\cpp\ProjectGen

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Dev\CBTek\cpp\ProjectGen\build

# Include any dependencies generated for this target.
include products/pgen/pgen/CMakeFiles/pgen.dir/depend.make

# Include the progress variables for this target.
include products/pgen/pgen/CMakeFiles/pgen.dir/progress.make

# Include the compile flags for this target's objects.
include products/pgen/pgen/CMakeFiles/pgen.dir/flags.make

products/pgen/pgen/CMakeFiles/pgen.dir/src/main.cpp.obj: products/pgen/pgen/CMakeFiles/pgen.dir/flags.make
products/pgen/pgen/CMakeFiles/pgen.dir/src/main.cpp.obj: products/pgen/pgen/CMakeFiles/pgen.dir/includes_CXX.rsp
products/pgen/pgen/CMakeFiles/pgen.dir/src/main.cpp.obj: ../products/pgen/pgen/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Dev\CBTek\cpp\ProjectGen\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object products/pgen/pgen/CMakeFiles/pgen.dir/src/main.cpp.obj"
	cd /d C:\Dev\CBTek\cpp\ProjectGen\build\products\pgen\pgen && C:\Dev\tools\mingw64\mingw64\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pgen.dir\src\main.cpp.obj -c C:\Dev\CBTek\cpp\ProjectGen\products\pgen\pgen\src\main.cpp

products/pgen/pgen/CMakeFiles/pgen.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pgen.dir/src/main.cpp.i"
	cd /d C:\Dev\CBTek\cpp\ProjectGen\build\products\pgen\pgen && C:\Dev\tools\mingw64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Dev\CBTek\cpp\ProjectGen\products\pgen\pgen\src\main.cpp > CMakeFiles\pgen.dir\src\main.cpp.i

products/pgen/pgen/CMakeFiles/pgen.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pgen.dir/src/main.cpp.s"
	cd /d C:\Dev\CBTek\cpp\ProjectGen\build\products\pgen\pgen && C:\Dev\tools\mingw64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Dev\CBTek\cpp\ProjectGen\products\pgen\pgen\src\main.cpp -o CMakeFiles\pgen.dir\src\main.cpp.s

products/pgen/pgen/CMakeFiles/pgen.dir/src/main.cpp.obj.requires:

.PHONY : products/pgen/pgen/CMakeFiles/pgen.dir/src/main.cpp.obj.requires

products/pgen/pgen/CMakeFiles/pgen.dir/src/main.cpp.obj.provides: products/pgen/pgen/CMakeFiles/pgen.dir/src/main.cpp.obj.requires
	$(MAKE) -f products\pgen\pgen\CMakeFiles\pgen.dir\build.make products/pgen/pgen/CMakeFiles/pgen.dir/src/main.cpp.obj.provides.build
.PHONY : products/pgen/pgen/CMakeFiles/pgen.dir/src/main.cpp.obj.provides

products/pgen/pgen/CMakeFiles/pgen.dir/src/main.cpp.obj.provides.build: products/pgen/pgen/CMakeFiles/pgen.dir/src/main.cpp.obj


# Object files for target pgen
pgen_OBJECTS = \
"CMakeFiles/pgen.dir/src/main.cpp.obj"

# External object files for target pgen
pgen_EXTERNAL_OBJECTS =

../bin/ProjectGen/release/pgen.exe: products/pgen/pgen/CMakeFiles/pgen.dir/src/main.cpp.obj
../bin/ProjectGen/release/pgen.exe: products/pgen/pgen/CMakeFiles/pgen.dir/build.make
../bin/ProjectGen/release/pgen.exe: ../bin/ProjectGen/release/libpgen_utils.a
../bin/ProjectGen/release/pgen.exe: ../bin/ProjectGen/release/libcommon_utils.a
../bin/ProjectGen/release/pgen.exe: products/pgen/pgen/CMakeFiles/pgen.dir/linklibs.rsp
../bin/ProjectGen/release/pgen.exe: products/pgen/pgen/CMakeFiles/pgen.dir/objects1.rsp
../bin/ProjectGen/release/pgen.exe: products/pgen/pgen/CMakeFiles/pgen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Dev\CBTek\cpp\ProjectGen\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ..\..\..\..\bin\ProjectGen\release\pgen.exe"
	cd /d C:\Dev\CBTek\cpp\ProjectGen\build\products\pgen\pgen && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\pgen.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
products/pgen/pgen/CMakeFiles/pgen.dir/build: ../bin/ProjectGen/release/pgen.exe

.PHONY : products/pgen/pgen/CMakeFiles/pgen.dir/build

products/pgen/pgen/CMakeFiles/pgen.dir/requires: products/pgen/pgen/CMakeFiles/pgen.dir/src/main.cpp.obj.requires

.PHONY : products/pgen/pgen/CMakeFiles/pgen.dir/requires

products/pgen/pgen/CMakeFiles/pgen.dir/clean:
	cd /d C:\Dev\CBTek\cpp\ProjectGen\build\products\pgen\pgen && $(CMAKE_COMMAND) -P CMakeFiles\pgen.dir\cmake_clean.cmake
.PHONY : products/pgen/pgen/CMakeFiles/pgen.dir/clean

products/pgen/pgen/CMakeFiles/pgen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Dev\CBTek\cpp\ProjectGen C:\Dev\CBTek\cpp\ProjectGen\products\pgen\pgen C:\Dev\CBTek\cpp\ProjectGen\build C:\Dev\CBTek\cpp\ProjectGen\build\products\pgen\pgen C:\Dev\CBTek\cpp\ProjectGen\build\products\pgen\pgen\CMakeFiles\pgen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : products/pgen/pgen/CMakeFiles/pgen.dir/depend

