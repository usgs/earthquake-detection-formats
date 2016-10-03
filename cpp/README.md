# C++ 11 Detection Formats Library

This is the C++11 implementation of the library used to generate and parse the Detection Formats.

Dependencies
------
* Detection Formats utilizizes [JSON](www.json.org) for formatting.
* Detection Formats uses a [CMake](http://www.cmake.org/) build script ([CMakeLists.txt](CMakeLists.txt)) for cross platform compilation.  A copy of CMake is not included in this project
* Detection Formats utilizizes [rapidjson](https://github.com/miloyip/rapidjson) to format, parse, and write JSON.  A copy of include/rapidjson is included in this project.
* Detection Formats uses [googletest](https://github.com/google/googletest) for unit testing.  A copy of googletest is not included in this project.

Building
------
The steps to get and build detection-formats using CMake are as follows:
1. Clone detection-formats.
2. Open a command window and change directories to /cpp/
3. Make a build directory `mkdir build`
4. Change to the build directory `cd build`
5. Run CMake `cmake ..`.  If building and running the googletest unit tests on Windows is desired, define the GTEST_ROOT varible to point to your googletest distribution directory `cmake -DGTEST_ROOT=<path to gtest> -Dtest=1 ..`.
6. If you are on a \*nix system, you should now see a Makefile in the current directory.  Just type 'make' to build detection-formats.  'make install' will copy the include files and libraries to the location defined by 'CMAKE_INSTALL_PREFIX'.
7. If you are on Windows and have Visual Studio installed, a `DetectionFormats.sln` file and several `.vcproj` files will be created.  You can then build them using Visual Studio.  Building the INSTALL project will copy the include files and libraries to the location defined by `CMAKE_INSTALL_PREFIX` (add `-DCMAKE_INSTALL_PREFIX=<path to install location>` to cmake call to define install location).
8. Note that for \*nix you must generate seperate build directories for x86 vs x64 compilation specifying the appropriate generator `cmake -G <generator> ..`.

Using
------
Once you are able to build the detection-formats library, you should create a project or build target for your program. Make sure you have the location of detection-formats.h in the header search path. Set program to link with the detection-formats library.
