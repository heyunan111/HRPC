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
CMAKE_SOURCE_DIR = /home/hyn/RPC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hyn/RPC/build

# Include any dependencies generated for this target.
include src/CMakeFiles/RPC.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/RPC.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/RPC.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/RPC.dir/flags.make

src/CMakeFiles/RPC.dir/logger.cc.o: src/CMakeFiles/RPC.dir/flags.make
src/CMakeFiles/RPC.dir/logger.cc.o: ../src/logger.cc
src/CMakeFiles/RPC.dir/logger.cc.o: src/CMakeFiles/RPC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hyn/RPC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/RPC.dir/logger.cc.o"
	cd /home/hyn/RPC/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/RPC.dir/logger.cc.o -MF CMakeFiles/RPC.dir/logger.cc.o.d -o CMakeFiles/RPC.dir/logger.cc.o -c /home/hyn/RPC/src/logger.cc

src/CMakeFiles/RPC.dir/logger.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RPC.dir/logger.cc.i"
	cd /home/hyn/RPC/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hyn/RPC/src/logger.cc > CMakeFiles/RPC.dir/logger.cc.i

src/CMakeFiles/RPC.dir/logger.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RPC.dir/logger.cc.s"
	cd /home/hyn/RPC/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hyn/RPC/src/logger.cc -o CMakeFiles/RPC.dir/logger.cc.s

src/CMakeFiles/RPC.dir/rpcApplication.cc.o: src/CMakeFiles/RPC.dir/flags.make
src/CMakeFiles/RPC.dir/rpcApplication.cc.o: ../src/rpcApplication.cc
src/CMakeFiles/RPC.dir/rpcApplication.cc.o: src/CMakeFiles/RPC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hyn/RPC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/RPC.dir/rpcApplication.cc.o"
	cd /home/hyn/RPC/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/RPC.dir/rpcApplication.cc.o -MF CMakeFiles/RPC.dir/rpcApplication.cc.o.d -o CMakeFiles/RPC.dir/rpcApplication.cc.o -c /home/hyn/RPC/src/rpcApplication.cc

src/CMakeFiles/RPC.dir/rpcApplication.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RPC.dir/rpcApplication.cc.i"
	cd /home/hyn/RPC/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hyn/RPC/src/rpcApplication.cc > CMakeFiles/RPC.dir/rpcApplication.cc.i

src/CMakeFiles/RPC.dir/rpcApplication.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RPC.dir/rpcApplication.cc.s"
	cd /home/hyn/RPC/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hyn/RPC/src/rpcApplication.cc -o CMakeFiles/RPC.dir/rpcApplication.cc.s

src/CMakeFiles/RPC.dir/rpcConfig.cc.o: src/CMakeFiles/RPC.dir/flags.make
src/CMakeFiles/RPC.dir/rpcConfig.cc.o: ../src/rpcConfig.cc
src/CMakeFiles/RPC.dir/rpcConfig.cc.o: src/CMakeFiles/RPC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hyn/RPC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/RPC.dir/rpcConfig.cc.o"
	cd /home/hyn/RPC/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/RPC.dir/rpcConfig.cc.o -MF CMakeFiles/RPC.dir/rpcConfig.cc.o.d -o CMakeFiles/RPC.dir/rpcConfig.cc.o -c /home/hyn/RPC/src/rpcConfig.cc

src/CMakeFiles/RPC.dir/rpcConfig.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RPC.dir/rpcConfig.cc.i"
	cd /home/hyn/RPC/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hyn/RPC/src/rpcConfig.cc > CMakeFiles/RPC.dir/rpcConfig.cc.i

src/CMakeFiles/RPC.dir/rpcConfig.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RPC.dir/rpcConfig.cc.s"
	cd /home/hyn/RPC/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hyn/RPC/src/rpcConfig.cc -o CMakeFiles/RPC.dir/rpcConfig.cc.s

# Object files for target RPC
RPC_OBJECTS = \
"CMakeFiles/RPC.dir/logger.cc.o" \
"CMakeFiles/RPC.dir/rpcApplication.cc.o" \
"CMakeFiles/RPC.dir/rpcConfig.cc.o"

# External object files for target RPC
RPC_EXTERNAL_OBJECTS =

../lib/libRPC.a: src/CMakeFiles/RPC.dir/logger.cc.o
../lib/libRPC.a: src/CMakeFiles/RPC.dir/rpcApplication.cc.o
../lib/libRPC.a: src/CMakeFiles/RPC.dir/rpcConfig.cc.o
../lib/libRPC.a: src/CMakeFiles/RPC.dir/build.make
../lib/libRPC.a: src/CMakeFiles/RPC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hyn/RPC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library ../../lib/libRPC.a"
	cd /home/hyn/RPC/build/src && $(CMAKE_COMMAND) -P CMakeFiles/RPC.dir/cmake_clean_target.cmake
	cd /home/hyn/RPC/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RPC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/RPC.dir/build: ../lib/libRPC.a
.PHONY : src/CMakeFiles/RPC.dir/build

src/CMakeFiles/RPC.dir/clean:
	cd /home/hyn/RPC/build/src && $(CMAKE_COMMAND) -P CMakeFiles/RPC.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/RPC.dir/clean

src/CMakeFiles/RPC.dir/depend:
	cd /home/hyn/RPC/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hyn/RPC /home/hyn/RPC/src /home/hyn/RPC/build /home/hyn/RPC/build/src /home/hyn/RPC/build/src/CMakeFiles/RPC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/RPC.dir/depend
