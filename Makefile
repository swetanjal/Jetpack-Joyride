# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/tapas/workspace/Sem4/Computer Graphics/Assignments/Assignment 1/Jetpack-Joyride"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/tapas/workspace/Sem4/Computer Graphics/Assignments/Assignment 1/Jetpack-Joyride"

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start "/home/tapas/workspace/Sem4/Computer Graphics/Assignments/Assignment 1/Jetpack-Joyride/CMakeFiles" "/home/tapas/workspace/Sem4/Computer Graphics/Assignments/Assignment 1/Jetpack-Joyride/CMakeFiles/progress.marks"
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start "/home/tapas/workspace/Sem4/Computer Graphics/Assignments/Assignment 1/Jetpack-Joyride/CMakeFiles" 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named graphics_asgn1

# Build rule for target.
graphics_asgn1: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 graphics_asgn1
.PHONY : graphics_asgn1

# fast build rule for target.
graphics_asgn1/fast:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/build
.PHONY : graphics_asgn1/fast

src/ball.o: src/ball.cpp.o

.PHONY : src/ball.o

# target to build an object file
src/ball.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/ball.cpp.o
.PHONY : src/ball.cpp.o

src/ball.i: src/ball.cpp.i

.PHONY : src/ball.i

# target to preprocess a source file
src/ball.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/ball.cpp.i
.PHONY : src/ball.cpp.i

src/ball.s: src/ball.cpp.s

.PHONY : src/ball.s

# target to generate assembly for a file
src/ball.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/ball.cpp.s
.PHONY : src/ball.cpp.s

src/boomerang.o: src/boomerang.cpp.o

.PHONY : src/boomerang.o

# target to build an object file
src/boomerang.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/boomerang.cpp.o
.PHONY : src/boomerang.cpp.o

src/boomerang.i: src/boomerang.cpp.i

.PHONY : src/boomerang.i

# target to preprocess a source file
src/boomerang.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/boomerang.cpp.i
.PHONY : src/boomerang.cpp.i

src/boomerang.s: src/boomerang.cpp.s

.PHONY : src/boomerang.s

# target to generate assembly for a file
src/boomerang.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/boomerang.cpp.s
.PHONY : src/boomerang.cpp.s

src/coin.o: src/coin.cpp.o

.PHONY : src/coin.o

# target to build an object file
src/coin.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/coin.cpp.o
.PHONY : src/coin.cpp.o

src/coin.i: src/coin.cpp.i

.PHONY : src/coin.i

# target to preprocess a source file
src/coin.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/coin.cpp.i
.PHONY : src/coin.cpp.i

src/coin.s: src/coin.cpp.s

.PHONY : src/coin.s

# target to generate assembly for a file
src/coin.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/coin.cpp.s
.PHONY : src/coin.cpp.s

src/color.o: src/color.cpp.o

.PHONY : src/color.o

# target to build an object file
src/color.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/color.cpp.o
.PHONY : src/color.cpp.o

src/color.i: src/color.cpp.i

.PHONY : src/color.i

# target to preprocess a source file
src/color.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/color.cpp.i
.PHONY : src/color.cpp.i

src/color.s: src/color.cpp.s

.PHONY : src/color.s

# target to generate assembly for a file
src/color.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/color.cpp.s
.PHONY : src/color.cpp.s

src/dragon.o: src/dragon.cpp.o

.PHONY : src/dragon.o

# target to build an object file
src/dragon.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/dragon.cpp.o
.PHONY : src/dragon.cpp.o

src/dragon.i: src/dragon.cpp.i

.PHONY : src/dragon.i

# target to preprocess a source file
src/dragon.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/dragon.cpp.i
.PHONY : src/dragon.cpp.i

src/dragon.s: src/dragon.cpp.s

.PHONY : src/dragon.s

# target to generate assembly for a file
src/dragon.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/dragon.cpp.s
.PHONY : src/dragon.cpp.s

src/enemy1.o: src/enemy1.cpp.o

.PHONY : src/enemy1.o

# target to build an object file
src/enemy1.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/enemy1.cpp.o
.PHONY : src/enemy1.cpp.o

src/enemy1.i: src/enemy1.cpp.i

.PHONY : src/enemy1.i

# target to preprocess a source file
src/enemy1.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/enemy1.cpp.i
.PHONY : src/enemy1.cpp.i

src/enemy1.s: src/enemy1.cpp.s

.PHONY : src/enemy1.s

# target to generate assembly for a file
src/enemy1.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/enemy1.cpp.s
.PHONY : src/enemy1.cpp.s

src/enemy2.o: src/enemy2.cpp.o

.PHONY : src/enemy2.o

# target to build an object file
src/enemy2.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/enemy2.cpp.o
.PHONY : src/enemy2.cpp.o

src/enemy2.i: src/enemy2.cpp.i

.PHONY : src/enemy2.i

# target to preprocess a source file
src/enemy2.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/enemy2.cpp.i
.PHONY : src/enemy2.cpp.i

src/enemy2.s: src/enemy2.cpp.s

.PHONY : src/enemy2.s

# target to generate assembly for a file
src/enemy2.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/enemy2.cpp.s
.PHONY : src/enemy2.cpp.s

src/ground.o: src/ground.cpp.o

.PHONY : src/ground.o

# target to build an object file
src/ground.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/ground.cpp.o
.PHONY : src/ground.cpp.o

src/ground.i: src/ground.cpp.i

.PHONY : src/ground.i

# target to preprocess a source file
src/ground.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/ground.cpp.i
.PHONY : src/ground.cpp.i

src/ground.s: src/ground.cpp.s

.PHONY : src/ground.s

# target to generate assembly for a file
src/ground.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/ground.cpp.s
.PHONY : src/ground.cpp.s

src/ice.o: src/ice.cpp.o

.PHONY : src/ice.o

# target to build an object file
src/ice.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/ice.cpp.o
.PHONY : src/ice.cpp.o

src/ice.i: src/ice.cpp.i

.PHONY : src/ice.i

# target to preprocess a source file
src/ice.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/ice.cpp.i
.PHONY : src/ice.cpp.i

src/ice.s: src/ice.cpp.s

.PHONY : src/ice.s

# target to generate assembly for a file
src/ice.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/ice.cpp.s
.PHONY : src/ice.cpp.s

src/input.o: src/input.cpp.o

.PHONY : src/input.o

# target to build an object file
src/input.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/input.cpp.o
.PHONY : src/input.cpp.o

src/input.i: src/input.cpp.i

.PHONY : src/input.i

# target to preprocess a source file
src/input.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/input.cpp.i
.PHONY : src/input.cpp.i

src/input.s: src/input.cpp.s

.PHONY : src/input.s

# target to generate assembly for a file
src/input.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/input.cpp.s
.PHONY : src/input.cpp.s

src/lives.o: src/lives.cpp.o

.PHONY : src/lives.o

# target to build an object file
src/lives.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/lives.cpp.o
.PHONY : src/lives.cpp.o

src/lives.i: src/lives.cpp.i

.PHONY : src/lives.i

# target to preprocess a source file
src/lives.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/lives.cpp.i
.PHONY : src/lives.cpp.i

src/lives.s: src/lives.cpp.s

.PHONY : src/lives.s

# target to generate assembly for a file
src/lives.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/lives.cpp.s
.PHONY : src/lives.cpp.s

src/magnet.o: src/magnet.cpp.o

.PHONY : src/magnet.o

# target to build an object file
src/magnet.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/magnet.cpp.o
.PHONY : src/magnet.cpp.o

src/magnet.i: src/magnet.cpp.i

.PHONY : src/magnet.i

# target to preprocess a source file
src/magnet.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/magnet.cpp.i
.PHONY : src/magnet.cpp.i

src/magnet.s: src/magnet.cpp.s

.PHONY : src/magnet.s

# target to generate assembly for a file
src/magnet.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/magnet.cpp.s
.PHONY : src/magnet.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/nonedit.o: src/nonedit.cpp.o

.PHONY : src/nonedit.o

# target to build an object file
src/nonedit.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.o
.PHONY : src/nonedit.cpp.o

src/nonedit.i: src/nonedit.cpp.i

.PHONY : src/nonedit.i

# target to preprocess a source file
src/nonedit.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.i
.PHONY : src/nonedit.cpp.i

src/nonedit.s: src/nonedit.cpp.s

.PHONY : src/nonedit.s

# target to generate assembly for a file
src/nonedit.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/nonedit.cpp.s
.PHONY : src/nonedit.cpp.s

src/other_handlers.o: src/other_handlers.cpp.o

.PHONY : src/other_handlers.o

# target to build an object file
src/other_handlers.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.o
.PHONY : src/other_handlers.cpp.o

src/other_handlers.i: src/other_handlers.cpp.i

.PHONY : src/other_handlers.i

# target to preprocess a source file
src/other_handlers.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.i
.PHONY : src/other_handlers.cpp.i

src/other_handlers.s: src/other_handlers.cpp.s

.PHONY : src/other_handlers.s

# target to generate assembly for a file
src/other_handlers.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/other_handlers.cpp.s
.PHONY : src/other_handlers.cpp.s

src/player.o: src/player.cpp.o

.PHONY : src/player.o

# target to build an object file
src/player.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/player.cpp.o
.PHONY : src/player.cpp.o

src/player.i: src/player.cpp.i

.PHONY : src/player.i

# target to preprocess a source file
src/player.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/player.cpp.i
.PHONY : src/player.cpp.i

src/player.s: src/player.cpp.s

.PHONY : src/player.s

# target to generate assembly for a file
src/player.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/player.cpp.s
.PHONY : src/player.cpp.s

src/propulsion.o: src/propulsion.cpp.o

.PHONY : src/propulsion.o

# target to build an object file
src/propulsion.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/propulsion.cpp.o
.PHONY : src/propulsion.cpp.o

src/propulsion.i: src/propulsion.cpp.i

.PHONY : src/propulsion.i

# target to preprocess a source file
src/propulsion.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/propulsion.cpp.i
.PHONY : src/propulsion.cpp.i

src/propulsion.s: src/propulsion.cpp.s

.PHONY : src/propulsion.s

# target to generate assembly for a file
src/propulsion.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/propulsion.cpp.s
.PHONY : src/propulsion.cpp.s

src/ring.o: src/ring.cpp.o

.PHONY : src/ring.o

# target to build an object file
src/ring.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/ring.cpp.o
.PHONY : src/ring.cpp.o

src/ring.i: src/ring.cpp.i

.PHONY : src/ring.i

# target to preprocess a source file
src/ring.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/ring.cpp.i
.PHONY : src/ring.cpp.i

src/ring.s: src/ring.cpp.s

.PHONY : src/ring.s

# target to generate assembly for a file
src/ring.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/ring.cpp.s
.PHONY : src/ring.cpp.s

src/shield.o: src/shield.cpp.o

.PHONY : src/shield.o

# target to build an object file
src/shield.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/shield.cpp.o
.PHONY : src/shield.cpp.o

src/shield.i: src/shield.cpp.i

.PHONY : src/shield.i

# target to preprocess a source file
src/shield.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/shield.cpp.i
.PHONY : src/shield.cpp.i

src/shield.s: src/shield.cpp.s

.PHONY : src/shield.s

# target to generate assembly for a file
src/shield.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/shield.cpp.s
.PHONY : src/shield.cpp.s

src/timer.o: src/timer.cpp.o

.PHONY : src/timer.o

# target to build an object file
src/timer.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/timer.cpp.o
.PHONY : src/timer.cpp.o

src/timer.i: src/timer.cpp.i

.PHONY : src/timer.i

# target to preprocess a source file
src/timer.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/timer.cpp.i
.PHONY : src/timer.cpp.i

src/timer.s: src/timer.cpp.s

.PHONY : src/timer.s

# target to generate assembly for a file
src/timer.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/timer.cpp.s
.PHONY : src/timer.cpp.s

src/top.o: src/top.cpp.o

.PHONY : src/top.o

# target to build an object file
src/top.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/top.cpp.o
.PHONY : src/top.cpp.o

src/top.i: src/top.cpp.i

.PHONY : src/top.i

# target to preprocess a source file
src/top.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/top.cpp.i
.PHONY : src/top.cpp.i

src/top.s: src/top.cpp.s

.PHONY : src/top.s

# target to generate assembly for a file
src/top.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/top.cpp.s
.PHONY : src/top.cpp.s

src/water.o: src/water.cpp.o

.PHONY : src/water.o

# target to build an object file
src/water.cpp.o:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/water.cpp.o
.PHONY : src/water.cpp.o

src/water.i: src/water.cpp.i

.PHONY : src/water.i

# target to preprocess a source file
src/water.cpp.i:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/water.cpp.i
.PHONY : src/water.cpp.i

src/water.s: src/water.cpp.s

.PHONY : src/water.s

# target to generate assembly for a file
src/water.cpp.s:
	$(MAKE) -f CMakeFiles/graphics_asgn1.dir/build.make CMakeFiles/graphics_asgn1.dir/src/water.cpp.s
.PHONY : src/water.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... graphics_asgn1"
	@echo "... edit_cache"
	@echo "... src/ball.o"
	@echo "... src/ball.i"
	@echo "... src/ball.s"
	@echo "... src/boomerang.o"
	@echo "... src/boomerang.i"
	@echo "... src/boomerang.s"
	@echo "... src/coin.o"
	@echo "... src/coin.i"
	@echo "... src/coin.s"
	@echo "... src/color.o"
	@echo "... src/color.i"
	@echo "... src/color.s"
	@echo "... src/dragon.o"
	@echo "... src/dragon.i"
	@echo "... src/dragon.s"
	@echo "... src/enemy1.o"
	@echo "... src/enemy1.i"
	@echo "... src/enemy1.s"
	@echo "... src/enemy2.o"
	@echo "... src/enemy2.i"
	@echo "... src/enemy2.s"
	@echo "... src/ground.o"
	@echo "... src/ground.i"
	@echo "... src/ground.s"
	@echo "... src/ice.o"
	@echo "... src/ice.i"
	@echo "... src/ice.s"
	@echo "... src/input.o"
	@echo "... src/input.i"
	@echo "... src/input.s"
	@echo "... src/lives.o"
	@echo "... src/lives.i"
	@echo "... src/lives.s"
	@echo "... src/magnet.o"
	@echo "... src/magnet.i"
	@echo "... src/magnet.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/nonedit.o"
	@echo "... src/nonedit.i"
	@echo "... src/nonedit.s"
	@echo "... src/other_handlers.o"
	@echo "... src/other_handlers.i"
	@echo "... src/other_handlers.s"
	@echo "... src/player.o"
	@echo "... src/player.i"
	@echo "... src/player.s"
	@echo "... src/propulsion.o"
	@echo "... src/propulsion.i"
	@echo "... src/propulsion.s"
	@echo "... src/ring.o"
	@echo "... src/ring.i"
	@echo "... src/ring.s"
	@echo "... src/shield.o"
	@echo "... src/shield.i"
	@echo "... src/shield.s"
	@echo "... src/timer.o"
	@echo "... src/timer.i"
	@echo "... src/timer.s"
	@echo "... src/top.o"
	@echo "... src/top.i"
	@echo "... src/top.s"
	@echo "... src/water.o"
	@echo "... src/water.i"
	@echo "... src/water.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

