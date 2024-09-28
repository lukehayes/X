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
# Find SDL library.
#
find_package(raylib REQUIRED)

# -----------------------------------------------------------------------------
# Set the project include directories.
#
include_directories(${INCLUDE_DIRS})

add_executable(${BIN_NAME} main.cpp)

#add_subdirectory("src")

set(X_LIB "XLIB")

add_library(${X_LIB} SHARED
	"${X_DIR}/Transform.cpp"
	"${X_DIR}/Object.cpp"
	"${X_DIR}/GameObject.cpp"
	"${X_DIR}/Sprite.cpp"
	"${X_DIR}/Game.cpp"
)

# -----------------------------------------------------------------------------
# Link in the libraies the binary needs.
#
target_link_libraries(${BIN_NAME} raylib)
target_link_libraries(${BIN_NAME} ${X_LIB})
