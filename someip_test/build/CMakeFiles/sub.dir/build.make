# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/mkadam/vsiptst

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mkadam/vsiptst/build

# Include any dependencies generated for this target.
include CMakeFiles/sub.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sub.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sub.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sub.dir/flags.make

CMakeFiles/sub.dir/sub.cpp.o: CMakeFiles/sub.dir/flags.make
CMakeFiles/sub.dir/sub.cpp.o: ../sub.cpp
CMakeFiles/sub.dir/sub.cpp.o: CMakeFiles/sub.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mkadam/vsiptst/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sub.dir/sub.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sub.dir/sub.cpp.o -MF CMakeFiles/sub.dir/sub.cpp.o.d -o CMakeFiles/sub.dir/sub.cpp.o -c /home/mkadam/vsiptst/sub.cpp

CMakeFiles/sub.dir/sub.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sub.dir/sub.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mkadam/vsiptst/sub.cpp > CMakeFiles/sub.dir/sub.cpp.i

CMakeFiles/sub.dir/sub.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sub.dir/sub.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mkadam/vsiptst/sub.cpp -o CMakeFiles/sub.dir/sub.cpp.s

# Object files for target sub
sub_OBJECTS = \
"CMakeFiles/sub.dir/sub.cpp.o"

# External object files for target sub
sub_EXTERNAL_OBJECTS =

sub: CMakeFiles/sub.dir/sub.cpp.o
sub: CMakeFiles/sub.dir/build.make
sub: /home/mkadam/vsomeip/build/libvsomeip3.so.3.3.0
sub: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.74.0
sub: /usr/lib/x86_64-linux-gnu/libboost_log.so.1.74.0
sub: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.74.0
sub: /usr/lib/x86_64-linux-gnu/libboost_atomic.so.1.74.0
sub: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.74.0
sub: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.74.0
sub: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.74.0
sub: CMakeFiles/sub.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mkadam/vsiptst/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sub"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sub.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sub.dir/build: sub
.PHONY : CMakeFiles/sub.dir/build

CMakeFiles/sub.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sub.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sub.dir/clean

CMakeFiles/sub.dir/depend:
	cd /home/mkadam/vsiptst/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mkadam/vsiptst /home/mkadam/vsiptst /home/mkadam/vsiptst/build /home/mkadam/vsiptst/build /home/mkadam/vsiptst/build/CMakeFiles/sub.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sub.dir/depend

