# earthquake-detection-formats CMake configuration file.
cmake_minimum_required (VERSION 3.4)
set(CMAKE_DIR ${CMAKE_CURRENT_LIST_DIR}/cmake/)

# ----- PROJECT VERSION ----- #
include(${CMAKE_DIR}/version.cmake)

# ----- PROJECT ----- #
project (DetectionFormats VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})

#----- BASE FUNCTIONS ----- #
include(${CMAKE_DIR}/base.cmake)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

# ----- CMAKE INCLUDES ----- #
include(ExternalProject)

# ----- SETUP INSTALL LOCATIONS ----- #
set(INSTALL_LOCATION ${CMAKE_INSTALL_PREFIX})

# ----- PREPEND INSTALL LOCATIONS TO MODULE PATH ----- #
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${INSTALL_LOCATION}" )

# ----- OPTIONS ----- #
option(GENERATE_DOCUMENTATION "Create and install the HTML based API documentation" OFF)
option(RUN_TESTS "Create and run unit tests" ON)
option(RUN_CPPCHECK "Run CPP Checks (requires cppcheck installed)" OFF)
option(RUN_CPPLINT "Run CPP Checks (requires cpplint and python installed)" OFF)
option(SUPPORT_COVERAGE "Instrument for Coverage" OFF)
option(RUN_COVERAGE "Run Coverage Report (requires lcov installed)" OFF)
option(GIT_CLONE_PUBLIC "Clone from public git URLs (https)" OFF)

# ----- EXTERNAL LIBRARIES ----- #
# rapidjson
include(${CMAKE_DIR}/include_rapidjson.cmake)

# ----- SET SOURCE FILES ----- #
file(GLOB SRCS ${PROJECT_SOURCE_DIR}/src/*.cpp)

# ----- SET HEADER FILES ----- #
file(GLOB HDRS ${PROJECT_SOURCE_DIR}/include/*.h)

# ----- BUILD LIBRARY ----- #
include(${CMAKE_DIR}/build_lib.cmake)

# ----- RUN CPPCHECK ----- #
include(${CMAKE_DIR}/cppcheck.cmake)

# ----- RUN CPPLINT ----- #
include(${CMAKE_DIR}/cpplint.cmake)

# ----- RUN UNIT TESTS ----- #
file(GLOB TESTS ${PROJECT_SOURCE_DIR}/tests/*.cpp)
# WARNING: linking order of libraries matters for G++
set(TEST_LIBRARIES ${SuperEasyJSON_LIBRARIES} ${util_LIBRARIES} ${DetectionFormats_LIBRARIES})
include(${CMAKE_DIR}/test.cmake)

# ----- GENERATE DOCUMENTATION ----- #
set(DOC_DIRS "${PROJECT_SOURCE_DIR}/include/")
include(${CMAKE_DIR}/documentation.cmake)

# ----- INSTALL LIBRARY ----- #
include(${CMAKE_DIR}/install_lib.cmake)