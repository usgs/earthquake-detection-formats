cmake_minimum_required (VERSION 3.4)

# ----- TOP LEVEL CMAKE PROJECT ----- #
project(top-level-earthquake-detection-formats)

# ----- CMAKE INCLUDES ----- #
include(ExternalProject)

# ----- OPTIONS ----- #
option(GENERATE_DOCUMENTATION "Create and install the HTML based API documentation" OFF)
option(RUN_TESTS "Create and run unit tests" ON)

# ----- DIRECTORY FOR EARTHQUAKE DETECTION FORMATS C++ LIB----- #
ExternalProject_Add(
    DetectionFormats
    SOURCE_DIR ${PROJECT_SOURCE_DIR}/cpp/
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}
      -DGENERATE_DOCUMENTATION=${GENERATE_DOCUMENTATION}
      -DRUN_TESTS=${RUN_TESTS}
    UPDATE_COMMAND ""
)
