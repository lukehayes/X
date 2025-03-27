cmake_minimum_required(VERSION 3.2)
project(XApp)

# -----------------------------------------------------------------------------
# Variables
#
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(INCLUDE_DIRS "include")
set(X_DIR "${PROJECT_SOURCE_DIR}/src/X")
set(BIN_NAME "X")

# -----------------------------------------------------------------------------
# Set the project include directories.
#
include_directories(${INCLUDE_DIRS})

add_executable(${BIN_NAME} main.cpp)

# -----------------------------------------------------------------------------
# Link in the libraies the binary needs.
#
target_link_libraries(${BIN_NAME} ${X_LIB})
