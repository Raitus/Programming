# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Raitus\CLionProjects\11.6.8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Raitus\CLionProjects\11.6.8\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\11_6_8.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\11_6_8.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\11_6_8.dir\flags.make

CMakeFiles\11_6_8.dir\main.cpp.obj: CMakeFiles\11_6_8.dir\flags.make
CMakeFiles\11_6_8.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Raitus\CLionProjects\11.6.8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/11_6_8.dir/main.cpp.obj"
	"C:\PROGRA~2\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.25.28610\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\11_6_8.dir\main.cpp.obj /FdCMakeFiles\11_6_8.dir\ /FS -c C:\Users\Raitus\CLionProjects\11.6.8\main.cpp
<<

CMakeFiles\11_6_8.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/11_6_8.dir/main.cpp.i"
	"C:\PROGRA~2\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.25.28610\bin\Hostx86\x86\cl.exe" > CMakeFiles\11_6_8.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Raitus\CLionProjects\11.6.8\main.cpp
<<

CMakeFiles\11_6_8.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/11_6_8.dir/main.cpp.s"
	"C:\PROGRA~2\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.25.28610\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\11_6_8.dir\main.cpp.s /c C:\Users\Raitus\CLionProjects\11.6.8\main.cpp
<<

# Object files for target 11_6_8
11_6_8_OBJECTS = \
"CMakeFiles\11_6_8.dir\main.cpp.obj"

# External object files for target 11_6_8
11_6_8_EXTERNAL_OBJECTS =

11_6_8.exe: CMakeFiles\11_6_8.dir\main.cpp.obj
11_6_8.exe: CMakeFiles\11_6_8.dir\build.make
11_6_8.exe: CMakeFiles\11_6_8.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Raitus\CLionProjects\11.6.8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 11_6_8.exe"
	"C:\Program Files\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\11_6_8.dir --rc="C:\PROGRA~2\Windows Kits\10\bin\10.0.18362.0\x86\rc.exe" --mt="C:\PROGRA~2\Windows Kits\10\bin\10.0.18362.0\x86\mt.exe" --manifests  -- "C:\PROGRA~2\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.25.28610\bin\Hostx86\x86\link.exe" /nologo @CMakeFiles\11_6_8.dir\objects1.rsp @<<
 /out:11_6_8.exe /implib:11_6_8.lib /pdb:C:\Users\Raitus\CLionProjects\11.6.8\cmake-build-debug\11_6_8.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\11_6_8.dir\build: 11_6_8.exe

.PHONY : CMakeFiles\11_6_8.dir\build

CMakeFiles\11_6_8.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\11_6_8.dir\cmake_clean.cmake
.PHONY : CMakeFiles\11_6_8.dir\clean

CMakeFiles\11_6_8.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Raitus\CLionProjects\11.6.8 C:\Users\Raitus\CLionProjects\11.6.8 C:\Users\Raitus\CLionProjects\11.6.8\cmake-build-debug C:\Users\Raitus\CLionProjects\11.6.8\cmake-build-debug C:\Users\Raitus\CLionProjects\11.6.8\cmake-build-debug\CMakeFiles\11_6_8.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\11_6_8.dir\depend

