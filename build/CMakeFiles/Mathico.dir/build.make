# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/vpert/gitproj/mathico

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vpert/gitproj/mathico/build

# Include any dependencies generated for this target.
include CMakeFiles/Mathico.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Mathico.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Mathico.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Mathico.dir/flags.make

CMakeFiles/Mathico.dir/main.cpp.o: CMakeFiles/Mathico.dir/flags.make
CMakeFiles/Mathico.dir/main.cpp.o: /home/vpert/gitproj/mathico/main.cpp
CMakeFiles/Mathico.dir/main.cpp.o: CMakeFiles/Mathico.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/vpert/gitproj/mathico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Mathico.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Mathico.dir/main.cpp.o -MF CMakeFiles/Mathico.dir/main.cpp.o.d -o CMakeFiles/Mathico.dir/main.cpp.o -c /home/vpert/gitproj/mathico/main.cpp

CMakeFiles/Mathico.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Mathico.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vpert/gitproj/mathico/main.cpp > CMakeFiles/Mathico.dir/main.cpp.i

CMakeFiles/Mathico.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Mathico.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vpert/gitproj/mathico/main.cpp -o CMakeFiles/Mathico.dir/main.cpp.s

CMakeFiles/Mathico.dir/gui/gui.cpp.o: CMakeFiles/Mathico.dir/flags.make
CMakeFiles/Mathico.dir/gui/gui.cpp.o: /home/vpert/gitproj/mathico/gui/gui.cpp
CMakeFiles/Mathico.dir/gui/gui.cpp.o: CMakeFiles/Mathico.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/vpert/gitproj/mathico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Mathico.dir/gui/gui.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Mathico.dir/gui/gui.cpp.o -MF CMakeFiles/Mathico.dir/gui/gui.cpp.o.d -o CMakeFiles/Mathico.dir/gui/gui.cpp.o -c /home/vpert/gitproj/mathico/gui/gui.cpp

CMakeFiles/Mathico.dir/gui/gui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Mathico.dir/gui/gui.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vpert/gitproj/mathico/gui/gui.cpp > CMakeFiles/Mathico.dir/gui/gui.cpp.i

CMakeFiles/Mathico.dir/gui/gui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Mathico.dir/gui/gui.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vpert/gitproj/mathico/gui/gui.cpp -o CMakeFiles/Mathico.dir/gui/gui.cpp.s

CMakeFiles/Mathico.dir/gui/page/tpage.cpp.o: CMakeFiles/Mathico.dir/flags.make
CMakeFiles/Mathico.dir/gui/page/tpage.cpp.o: /home/vpert/gitproj/mathico/gui/page/tpage.cpp
CMakeFiles/Mathico.dir/gui/page/tpage.cpp.o: CMakeFiles/Mathico.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/vpert/gitproj/mathico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Mathico.dir/gui/page/tpage.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Mathico.dir/gui/page/tpage.cpp.o -MF CMakeFiles/Mathico.dir/gui/page/tpage.cpp.o.d -o CMakeFiles/Mathico.dir/gui/page/tpage.cpp.o -c /home/vpert/gitproj/mathico/gui/page/tpage.cpp

CMakeFiles/Mathico.dir/gui/page/tpage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Mathico.dir/gui/page/tpage.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vpert/gitproj/mathico/gui/page/tpage.cpp > CMakeFiles/Mathico.dir/gui/page/tpage.cpp.i

CMakeFiles/Mathico.dir/gui/page/tpage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Mathico.dir/gui/page/tpage.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vpert/gitproj/mathico/gui/page/tpage.cpp -o CMakeFiles/Mathico.dir/gui/page/tpage.cpp.s

CMakeFiles/Mathico.dir/gui/page/buttons/tbuttons.cpp.o: CMakeFiles/Mathico.dir/flags.make
CMakeFiles/Mathico.dir/gui/page/buttons/tbuttons.cpp.o: /home/vpert/gitproj/mathico/gui/page/buttons/tbuttons.cpp
CMakeFiles/Mathico.dir/gui/page/buttons/tbuttons.cpp.o: CMakeFiles/Mathico.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/vpert/gitproj/mathico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Mathico.dir/gui/page/buttons/tbuttons.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Mathico.dir/gui/page/buttons/tbuttons.cpp.o -MF CMakeFiles/Mathico.dir/gui/page/buttons/tbuttons.cpp.o.d -o CMakeFiles/Mathico.dir/gui/page/buttons/tbuttons.cpp.o -c /home/vpert/gitproj/mathico/gui/page/buttons/tbuttons.cpp

CMakeFiles/Mathico.dir/gui/page/buttons/tbuttons.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Mathico.dir/gui/page/buttons/tbuttons.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vpert/gitproj/mathico/gui/page/buttons/tbuttons.cpp > CMakeFiles/Mathico.dir/gui/page/buttons/tbuttons.cpp.i

CMakeFiles/Mathico.dir/gui/page/buttons/tbuttons.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Mathico.dir/gui/page/buttons/tbuttons.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vpert/gitproj/mathico/gui/page/buttons/tbuttons.cpp -o CMakeFiles/Mathico.dir/gui/page/buttons/tbuttons.cpp.s

CMakeFiles/Mathico.dir/gui/page/textboxes/textbox.cpp.o: CMakeFiles/Mathico.dir/flags.make
CMakeFiles/Mathico.dir/gui/page/textboxes/textbox.cpp.o: /home/vpert/gitproj/mathico/gui/page/textboxes/textbox.cpp
CMakeFiles/Mathico.dir/gui/page/textboxes/textbox.cpp.o: CMakeFiles/Mathico.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/vpert/gitproj/mathico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Mathico.dir/gui/page/textboxes/textbox.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Mathico.dir/gui/page/textboxes/textbox.cpp.o -MF CMakeFiles/Mathico.dir/gui/page/textboxes/textbox.cpp.o.d -o CMakeFiles/Mathico.dir/gui/page/textboxes/textbox.cpp.o -c /home/vpert/gitproj/mathico/gui/page/textboxes/textbox.cpp

CMakeFiles/Mathico.dir/gui/page/textboxes/textbox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Mathico.dir/gui/page/textboxes/textbox.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vpert/gitproj/mathico/gui/page/textboxes/textbox.cpp > CMakeFiles/Mathico.dir/gui/page/textboxes/textbox.cpp.i

CMakeFiles/Mathico.dir/gui/page/textboxes/textbox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Mathico.dir/gui/page/textboxes/textbox.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vpert/gitproj/mathico/gui/page/textboxes/textbox.cpp -o CMakeFiles/Mathico.dir/gui/page/textboxes/textbox.cpp.s

CMakeFiles/Mathico.dir/gui/page/slider/slider.cpp.o: CMakeFiles/Mathico.dir/flags.make
CMakeFiles/Mathico.dir/gui/page/slider/slider.cpp.o: /home/vpert/gitproj/mathico/gui/page/slider/slider.cpp
CMakeFiles/Mathico.dir/gui/page/slider/slider.cpp.o: CMakeFiles/Mathico.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/vpert/gitproj/mathico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Mathico.dir/gui/page/slider/slider.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Mathico.dir/gui/page/slider/slider.cpp.o -MF CMakeFiles/Mathico.dir/gui/page/slider/slider.cpp.o.d -o CMakeFiles/Mathico.dir/gui/page/slider/slider.cpp.o -c /home/vpert/gitproj/mathico/gui/page/slider/slider.cpp

CMakeFiles/Mathico.dir/gui/page/slider/slider.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Mathico.dir/gui/page/slider/slider.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vpert/gitproj/mathico/gui/page/slider/slider.cpp > CMakeFiles/Mathico.dir/gui/page/slider/slider.cpp.i

CMakeFiles/Mathico.dir/gui/page/slider/slider.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Mathico.dir/gui/page/slider/slider.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vpert/gitproj/mathico/gui/page/slider/slider.cpp -o CMakeFiles/Mathico.dir/gui/page/slider/slider.cpp.s

CMakeFiles/Mathico.dir/math/polygon.cpp.o: CMakeFiles/Mathico.dir/flags.make
CMakeFiles/Mathico.dir/math/polygon.cpp.o: /home/vpert/gitproj/mathico/math/polygon.cpp
CMakeFiles/Mathico.dir/math/polygon.cpp.o: CMakeFiles/Mathico.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/vpert/gitproj/mathico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Mathico.dir/math/polygon.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Mathico.dir/math/polygon.cpp.o -MF CMakeFiles/Mathico.dir/math/polygon.cpp.o.d -o CMakeFiles/Mathico.dir/math/polygon.cpp.o -c /home/vpert/gitproj/mathico/math/polygon.cpp

CMakeFiles/Mathico.dir/math/polygon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Mathico.dir/math/polygon.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vpert/gitproj/mathico/math/polygon.cpp > CMakeFiles/Mathico.dir/math/polygon.cpp.i

CMakeFiles/Mathico.dir/math/polygon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Mathico.dir/math/polygon.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vpert/gitproj/mathico/math/polygon.cpp -o CMakeFiles/Mathico.dir/math/polygon.cpp.s

CMakeFiles/Mathico.dir/math/vmath.cpp.o: CMakeFiles/Mathico.dir/flags.make
CMakeFiles/Mathico.dir/math/vmath.cpp.o: /home/vpert/gitproj/mathico/math/vmath.cpp
CMakeFiles/Mathico.dir/math/vmath.cpp.o: CMakeFiles/Mathico.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/vpert/gitproj/mathico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Mathico.dir/math/vmath.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Mathico.dir/math/vmath.cpp.o -MF CMakeFiles/Mathico.dir/math/vmath.cpp.o.d -o CMakeFiles/Mathico.dir/math/vmath.cpp.o -c /home/vpert/gitproj/mathico/math/vmath.cpp

CMakeFiles/Mathico.dir/math/vmath.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Mathico.dir/math/vmath.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vpert/gitproj/mathico/math/vmath.cpp > CMakeFiles/Mathico.dir/math/vmath.cpp.i

CMakeFiles/Mathico.dir/math/vmath.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Mathico.dir/math/vmath.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vpert/gitproj/mathico/math/vmath.cpp -o CMakeFiles/Mathico.dir/math/vmath.cpp.s

# Object files for target Mathico
Mathico_OBJECTS = \
"CMakeFiles/Mathico.dir/main.cpp.o" \
"CMakeFiles/Mathico.dir/gui/gui.cpp.o" \
"CMakeFiles/Mathico.dir/gui/page/tpage.cpp.o" \
"CMakeFiles/Mathico.dir/gui/page/buttons/tbuttons.cpp.o" \
"CMakeFiles/Mathico.dir/gui/page/textboxes/textbox.cpp.o" \
"CMakeFiles/Mathico.dir/gui/page/slider/slider.cpp.o" \
"CMakeFiles/Mathico.dir/math/polygon.cpp.o" \
"CMakeFiles/Mathico.dir/math/vmath.cpp.o"

# External object files for target Mathico
Mathico_EXTERNAL_OBJECTS =

Mathico: CMakeFiles/Mathico.dir/main.cpp.o
Mathico: CMakeFiles/Mathico.dir/gui/gui.cpp.o
Mathico: CMakeFiles/Mathico.dir/gui/page/tpage.cpp.o
Mathico: CMakeFiles/Mathico.dir/gui/page/buttons/tbuttons.cpp.o
Mathico: CMakeFiles/Mathico.dir/gui/page/textboxes/textbox.cpp.o
Mathico: CMakeFiles/Mathico.dir/gui/page/slider/slider.cpp.o
Mathico: CMakeFiles/Mathico.dir/math/polygon.cpp.o
Mathico: CMakeFiles/Mathico.dir/math/vmath.cpp.o
Mathico: CMakeFiles/Mathico.dir/build.make
Mathico: CMakeFiles/Mathico.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/vpert/gitproj/mathico/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable Mathico"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Mathico.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Mathico.dir/build: Mathico
.PHONY : CMakeFiles/Mathico.dir/build

CMakeFiles/Mathico.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Mathico.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Mathico.dir/clean

CMakeFiles/Mathico.dir/depend:
	cd /home/vpert/gitproj/mathico/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vpert/gitproj/mathico /home/vpert/gitproj/mathico /home/vpert/gitproj/mathico/build /home/vpert/gitproj/mathico/build /home/vpert/gitproj/mathico/build/CMakeFiles/Mathico.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Mathico.dir/depend
