cmake_minimum_required (VERSION 3.4)

# ----- VERSION NUMBER----- #
set(VERSION_MAJOR   0   CACHE STRING "DetectionFormats major version number.")
set(VERSION_MINOR   9   CACHE STRING "DetectionFormats minor version number.")
set(VERSION_PATCH   0   CACHE STRING "DetectionFormats patch version number.")
mark_as_advanced(VERSION_MAJOR VERSION_MINOR VERSION_PATCH)

# ----- OPTIONS ----- #
option(test "Build all tests." OFF)

# ----- OVERRIDE TO SET STATIC RUNTIME ON MSVC ----- #
set(CMAKE_USER_MAKE_RULES_OVERRIDE ${CMAKE_CURRENT_SOURCE_DIR}/c_flag_overrides.cmake)
set(CMAKE_USER_MAKE_RULES_OVERRIDE_CXX ${CMAKE_CURRENT_SOURCE_DIR}/cxx_flag_overrides.cmake)

# ----- PROJECT ----- #
project (DetectionFormats)

# ----- SET FOR C++14 STANDARD ----- #
if (NOT MSVC)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
endif (NOT MSVC)

# ----- SET INCLUDE DIRECTORIES ----- #
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/lib)
include_directories(${PROJECT_SOURCE_DIR}/lib/rapidjson)

# ----- SET SOURCE FILES ----- #
set (SRCS ${PROJECT_SOURCE_DIR}/src/util.cpp
    ${PROJECT_SOURCE_DIR}/src/base.cpp
    ${PROJECT_SOURCE_DIR}/src/site.cpp
    ${PROJECT_SOURCE_DIR}/src/source.cpp
    ${PROJECT_SOURCE_DIR}/src/filter.cpp
    ${PROJECT_SOURCE_DIR}/src/amplitude.cpp
    ${PROJECT_SOURCE_DIR}/src/associated.cpp
    ${PROJECT_SOURCE_DIR}/src/hypocenter.cpp
    ${PROJECT_SOURCE_DIR}/src/beam.cpp
    ${PROJECT_SOURCE_DIR}/src/correlation.cpp
    ${PROJECT_SOURCE_DIR}/src/pick.cpp
    ${PROJECT_SOURCE_DIR}/src/detection.cpp
    ${PROJECT_SOURCE_DIR}/src/retract.cpp
)

# ----- SET HEADER FILES ----- #
set (HDRS ${PROJECT_SOURCE_DIR}/include/util.h
    ${PROJECT_SOURCE_DIR}/include/base.h
    ${PROJECT_SOURCE_DIR}/include/site.h
    ${PROJECT_SOURCE_DIR}/include/source.h
    ${PROJECT_SOURCE_DIR}/include/filter.h
    ${PROJECT_SOURCE_DIR}/include/amplitude.h
    ${PROJECT_SOURCE_DIR}/include/associated.h
    ${PROJECT_SOURCE_DIR}/include/hypocenter.h
    ${PROJECT_SOURCE_DIR}/include/beam.h
    ${PROJECT_SOURCE_DIR}/include/correlation.h
    ${PROJECT_SOURCE_DIR}/include/pick.h
    ${PROJECT_SOURCE_DIR}/include/detection.h
    ${PROJECT_SOURCE_DIR}/include/retract.h
)

# ----- SET DEBUG EXTENSION ----- #
if (CMAKE_BUILD_TYPE MATCHES DEBUG)
    message(STATUS "Target is Debug")
    set(DEBUG_EXTENSION "_d")
else (CMAKE_BUILD_TYPE MATCHES DEBUG)
    message(STATUS "Target is Release")
    set(DEBUG_EXTENSION "")
endif (CMAKE_BUILD_TYPE MATCHES DEBUG)

# ----- SET 64 BIT EXTENSION ----- #
if (CMAKE_SIZEOF_VOID_P EQUAL "8")
    message(STATUS "Target is 64 bits")
    set(PLATFORM_EXTENSION "_x64")
else (CMAKE_SIZEOF_VOID_P EQUAL "8")
    message(STATUS "Target is 32 bits")
    set(PLATFORM_EXTENSION "")
endif (CMAKE_SIZEOF_VOID_P EQUAL "8")

# ----- CREATE LIBRARY ----- #
add_library (DetectionFormats STATIC ${SRCS} ${HDRS})
set_target_properties(DetectionFormats PROPERTIES OUTPUT_NAME detection-formats${PLATFORM_EXTENSION}${DEBUG_EXTENSION})

# ----- TESTS ----- #
set(GTEST_ROOT "./" CACHE PATH "Path to the google test library")
find_package(GTest)
option(RUN_TESTS "Create and run unit tests (requires GTest)" ${GTEST_FOUND})

if (RUN_TESTS)

    if (GTEST_FOUND)
        enable_testing()

        # ----- TEST SOURCES ----- #
        set (UNITTEST_SOURCES ${PROJECT_SOURCE_DIR}/tests/correlation_unittest.cpp
            ${PROJECT_SOURCE_DIR}/tests/detection_unittest.cpp
            ${PROJECT_SOURCE_DIR}/tests/pick_unittest.cpp
            ${PROJECT_SOURCE_DIR}/tests/beam_unittest.cpp
            ${PROJECT_SOURCE_DIR}/tests/retract_unittest.cpp
            ${PROJECT_SOURCE_DIR}/tests/associated_unittest.cpp
            ${PROJECT_SOURCE_DIR}/tests/site_unittest.cpp
            ${PROJECT_SOURCE_DIR}/tests/source_unittest.cpp
            ${PROJECT_SOURCE_DIR}/tests/amplitude_unittest.cpp
            ${PROJECT_SOURCE_DIR}/tests/filter_unittest.cpp
            ${PROJECT_SOURCE_DIR}/tests/hypocenter_unittest.cpp
            ${PROJECT_SOURCE_DIR}/tests/main.cpp
        )

        # ----- SET TEST INCLUDE DIRECTORIES ----- #
        include_directories(${GTEST_INCLUDE_DIRS})

        # ----- CREATE TEST EXE ----- #
        add_executable(UnitTests ${UNITTEST_SOURCES})
        set_target_properties(UnitTests PROPERTIES OUTPUT_NAME detection-format-tests${PLATFORM_EXTENSION}${DEBUG_EXTENSION})
        target_link_libraries(UnitTests ${GTEST_BOTH_LIBRARIES})
        target_link_libraries(UnitTests DetectionFormats)

        # ----- TESTS ----- #
        GTEST_ADD_TESTS(UnitTests "" ${UNITTEST_SOURCES})

        # ----- RUN TESTS ----- #
        add_custom_command(TARGET UnitTests
            POST_BUILD
            COMMAND UnitTests
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Running UnitTests" VERBATIM
        )
    endif (GTEST_FOUND)
endif()

# ----- DOCUMENTATION ----- #
find_package(Doxygen)
option(BUILD_DOCUMENTATION "Create and install the HTML based API documentation (requires Doxygen)" ${DOXYGEN_FOUND})

if(BUILD_DOCUMENTATION)

    if(DOXYGEN_FOUND)
        set(doxyfile_in ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
        set(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

        configure_file(${doxyfile_in} ${doxyfile} @ONLY)

        add_custom_target(doc
            COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)

        install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html DESTINATION doc)
    endif()
endif()

# ----- INSTALL ----- #
install(TARGETS DetectionFormats DESTINATION lib)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include DESTINATION ".")
install(DIRECTORY ${PROJECT_SOURCE_DIR}/lib/rapidjson DESTINATION "include")
