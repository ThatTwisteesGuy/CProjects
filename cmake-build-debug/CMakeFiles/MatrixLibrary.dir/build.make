# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = "E:\CLion 2024.1.4\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "E:\CLion 2024.1.4\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\matthew\CLionProjects\CProjects

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\matthew\CLionProjects\CProjects\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MatrixLibrary.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MatrixLibrary.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MatrixLibrary.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MatrixLibrary.dir/flags.make

CMakeFiles/MatrixLibrary.dir/MatrixFunctions.c.obj: CMakeFiles/MatrixLibrary.dir/flags.make
CMakeFiles/MatrixLibrary.dir/MatrixFunctions.c.obj: C:/Users/matthew/CLionProjects/CProjects/MatrixFunctions.c
CMakeFiles/MatrixLibrary.dir/MatrixFunctions.c.obj: CMakeFiles/MatrixLibrary.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\matthew\CLionProjects\CProjects\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/MatrixLibrary.dir/MatrixFunctions.c.obj"
	"E:\CLion 2024.1.4\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MatrixLibrary.dir/MatrixFunctions.c.obj -MF CMakeFiles\MatrixLibrary.dir\MatrixFunctions.c.obj.d -o CMakeFiles\MatrixLibrary.dir\MatrixFunctions.c.obj -c C:\Users\matthew\CLionProjects\CProjects\MatrixFunctions.c

CMakeFiles/MatrixLibrary.dir/MatrixFunctions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/MatrixLibrary.dir/MatrixFunctions.c.i"
	"E:\CLion 2024.1.4\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\matthew\CLionProjects\CProjects\MatrixFunctions.c > CMakeFiles\MatrixLibrary.dir\MatrixFunctions.c.i

CMakeFiles/MatrixLibrary.dir/MatrixFunctions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/MatrixLibrary.dir/MatrixFunctions.c.s"
	"E:\CLion 2024.1.4\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\matthew\CLionProjects\CProjects\MatrixFunctions.c -o CMakeFiles\MatrixLibrary.dir\MatrixFunctions.c.s

CMakeFiles/MatrixLibrary.dir/main.c.obj: CMakeFiles/MatrixLibrary.dir/flags.make
CMakeFiles/MatrixLibrary.dir/main.c.obj: C:/Users/matthew/CLionProjects/CProjects/main.c
CMakeFiles/MatrixLibrary.dir/main.c.obj: CMakeFiles/MatrixLibrary.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\matthew\CLionProjects\CProjects\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/MatrixLibrary.dir/main.c.obj"
	"E:\CLion 2024.1.4\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MatrixLibrary.dir/main.c.obj -MF CMakeFiles\MatrixLibrary.dir\main.c.obj.d -o CMakeFiles\MatrixLibrary.dir\main.c.obj -c C:\Users\matthew\CLionProjects\CProjects\main.c

CMakeFiles/MatrixLibrary.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/MatrixLibrary.dir/main.c.i"
	"E:\CLion 2024.1.4\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\matthew\CLionProjects\CProjects\main.c > CMakeFiles\MatrixLibrary.dir\main.c.i

CMakeFiles/MatrixLibrary.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/MatrixLibrary.dir/main.c.s"
	"E:\CLion 2024.1.4\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\matthew\CLionProjects\CProjects\main.c -o CMakeFiles\MatrixLibrary.dir\main.c.s

# Object files for target MatrixLibrary
MatrixLibrary_OBJECTS = \
"CMakeFiles/MatrixLibrary.dir/MatrixFunctions.c.obj" \
"CMakeFiles/MatrixLibrary.dir/main.c.obj"

# External object files for target MatrixLibrary
MatrixLibrary_EXTERNAL_OBJECTS =

MatrixLibrary.exe: CMakeFiles/MatrixLibrary.dir/MatrixFunctions.c.obj
MatrixLibrary.exe: CMakeFiles/MatrixLibrary.dir/main.c.obj
MatrixLibrary.exe: CMakeFiles/MatrixLibrary.dir/build.make
MatrixLibrary.exe: CMakeFiles/MatrixLibrary.dir/linkLibs.rsp
MatrixLibrary.exe: CMakeFiles/MatrixLibrary.dir/objects1.rsp
MatrixLibrary.exe: CMakeFiles/MatrixLibrary.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\matthew\CLionProjects\CProjects\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable MatrixLibrary.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MatrixLibrary.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MatrixLibrary.dir/build: MatrixLibrary.exe
.PHONY : CMakeFiles/MatrixLibrary.dir/build

CMakeFiles/MatrixLibrary.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MatrixLibrary.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MatrixLibrary.dir/clean

CMakeFiles/MatrixLibrary.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\matthew\CLionProjects\CProjects C:\Users\matthew\CLionProjects\CProjects C:\Users\matthew\CLionProjects\CProjects\cmake-build-debug C:\Users\matthew\CLionProjects\CProjects\cmake-build-debug C:\Users\matthew\CLionProjects\CProjects\cmake-build-debug\CMakeFiles\MatrixLibrary.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/MatrixLibrary.dir/depend

