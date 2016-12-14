cmake_minimum_required (VERSION 3.4)

# ----- VERSION NUMBER----- #
set(VERSION_MAJOR 0)
set(VERSION_MINOR 9)
set(VERSION_PATCH 0)

# ----- OVERRIDE TO SET STATIC RUNTIME ON MSVC ----- #
set(CMAKE_USER_MAKE_RULES_OVERRIDE ${CMAKE_CURRENT_SOURCE_DIR}/c_flag_overrides.cmake)
set(CMAKE_USER_MAKE_RULES_OVERRIDE_CXX ${CMAKE_CURRENT_SOURCE_DIR}/cxx_flag_overrides.cmake)

# ----- PROJECT ----- #
project (DetectionFormats VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

# ----- SET FOR C++14 STANDARD ----- #
if (NOT MSVC)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
endif (NOT MSVC)

# ----- CMAKE CONFIG HEADER ----- #
# pass some of the CMake settings
# to the source code
configure_file (
    "${PROJECT_SOURCE_DIR}/DetectionFormatsCMakeConfig.h.in"
    "${PROJECT_BINARY_DIR}/DetectionFormatsCMakeConfig.h"
)

# ----- SET INCLUDE DIRECTORIES ----- #
include_directories(${PROJECT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR}/include)
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

# ----- CREATE LIBRARY ----- #
add_library (DetectionFormats STATIC ${SRCS} ${HDRS})

# ----- TARGET PROPERTIES ----- #
set_target_properties(DetectionFormats PROPERTIES
    OUTPUT_NAME DetectionFormats)

# ----- GENERATE ----- #
include(GenerateExportHeader)
generate_export_header(DetectionFormats)

# ----- GLOBAL INCLUDES ----- #
target_include_directories(
    DetectionFormats PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)

# ----- TESTS ----- #
option(RUN_TESTS "Create and run unit tests (requires GTest)" OFF)

if (RUN_TESTS)

    # ----- LOOK FOR GTEST ----- #
    set(GTEST_ROOT "./" CACHE PATH "Path to the google test library")
    find_package(GTest REQUIRED)

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
    add_executable(DetectionFormatsTests ${UNITTEST_SOURCES})
    set_target_properties(DetectionFormatsTests PROPERTIES OUTPUT_NAME DetectionFormats-tests)
    target_link_libraries(DetectionFormatsTests ${GTEST_BOTH_LIBRARIES})
    target_link_libraries(DetectionFormatsTests DetectionFormats)

    # ----- TESTS ----- #
    GTEST_ADD_TESTS(DetectionFormatsTests "" ${UNITTEST_SOURCES})

    # ----- RUN TESTS ----- #
    add_custom_command(TARGET DetectionFormatsTests
        POST_BUILD
        COMMAND DetectionFormatsTests
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Running DetectionFormatsTests" VERBATIM
    )
endif()

# ----- DOCUMENTATION ----- #
option(GENERATE_DOCUMENTATION "Create and install the HTML based API documentation (requires Doxygen)" OFF)

if(GENERATE_DOCUMENTATION)

    # ----- LOOK FOR DOXYGEN ----- #
    find_package(Doxygen REQUIRED)

    set(doxyfile_in ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    configure_file(${doxyfile_in} ${doxyfile} @ONLY)

    add_custom_target(doc ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)

    install(
        DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html
        DESTINATION doc
    )
endif()

# ----- INSTALL RULES ----- #
# Layout. This works for all platforms:
#   * <prefix>/lib/<PROJECT-NAME>
#   * <prefix>/lib/
#   * <prefix>/include/
set(config_install_dir "lib/${PROJECT_NAME}")
set(include_install_dir "include")

set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")

# ----- Configuration ----- #
set(version_config "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake")
set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
set(targets_export_name "${PROJECT_NAME}Targets")
set(namespace "${PROJECT_NAME}::")

# Include module with function 'write_basic_package_version_file'
include(CMakePackageConfigHelpers)

# Configure '<PROJECT-NAME>ConfigVersion.cmake'
# Note: PROJECT_VERSION is used as a VERSION
write_basic_package_version_file(
    "${version_config}" COMPATIBILITY SameMajorVersion
)

# Configure '<PROJECT-NAME>Config.cmake'
# Use variables:
#   * targets_export_name
#   * PROJECT_NAME
configure_package_config_file(
    "Config.cmake.in"
    "${project_config}"
    INSTALL_DESTINATION "${config_install_dir}"
)

# Targets:
#   * <prefix>/lib/libDetectionFormats.a
#   * header location after install: <prefix>/include/*.h
install(
    TARGETS DetectionFormats
    EXPORT "${targets_export_name}"
    LIBRARY DESTINATION "lib"
    ARCHIVE DESTINATION "lib"
    RUNTIME DESTINATION "bin"
    INCLUDES DESTINATION "${include_install_dir}"
)

# Headers:
#   * *.h-> <prefix>/include/*.h
install(
    DIRECTORY ${PROJECT_SOURCE_DIR}/include
    DESTINATION "."
    FILES_MATCHING PATTERN "*.h"
)

install(
    DIRECTORY ${PROJECT_SOURCE_DIR}/lib/rapidjson
    DESTINATION "${include_install_dir}"
    )

# Export headers:
#   * ${CMAKE_CURRENT_BINARY_DIR}/DetectionFormats_export.h -> <prefix>/include/DetectionFormats_export.h
install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/DetectionFormats_export.h"
    DESTINATION "${include_install_dir}"
)

# Config
#   * <prefix>/lib/DetectionFormats/DetectionFormatsConfig.cmake
#   * <prefix>/lib/DetectionFormats/DetectionFormatsConfigVersion.cmake
install(
    FILES "${project_config}" "${version_config}"
    DESTINATION "${config_install_dir}"
)

# Config
#   * <prefix>/lib/DetectionFormats/DetectionFormatsTargets.cmake
install(
    EXPORT "${targets_export_name}"
    NAMESPACE "${namespace}"
    DESTINATION "${config_install_dir}"
)
