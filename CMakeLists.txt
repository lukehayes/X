cmake_minimum_required(VERSION 3.30)
project(X)

# -----------------------------------------------------------------------------
# Variables
#
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(INCLUDE_DIRS "include")
set(X_DIR "${PROJECT_SOURCE_DIR}/src/X")
set(BIN_NAME "X")

# -----------------------------------------------------------------------------
# Find SDL library.
#
find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)

# Find OpenGL library.
find_package(OpenGL REQUIRED)

# -----------------------------------------------------------------------------
# Set the project include directories.
#
include_directories(${INCLUDE_DIRS})

add_executable(${BIN_NAME} main.cpp)

# -----------------------------------------------------------------------------
# Build X_System library
#
set(X_LIB_SYSTEM "X_SYSTEM")

add_library(${X_LIB_SYSTEM} STATIC
  "${X_DIR}/Util.cpp"
  "${X_DIR}/App.cpp"
  "${X_DIR}/Window.cpp"
)

# -----------------------------------------------------------------------------
# Link in the libraies the binary needs.
#
target_link_libraries(${BIN_NAME} ${X_LIB_SYSTEM})

# Link SDL3
target_link_libraries(${BIN_NAME} SDL3::SDL3)

# Link OpenGL
target_link_libraries(${BIN_NAME} ${OPENGL_LIBRARY})
