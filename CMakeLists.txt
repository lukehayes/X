cmake_minimum_required(VERSION 4.0)
project(X)

# -----------------------------------------------------------------------------
# Variables
#
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "-ggdb")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(INCLUDE_DIRS "include")
set(X_SRC_DIR "${PROJECT_SOURCE_DIR}/src/X")
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src/")
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

add_executable(${BIN_NAME} main.cpp
    ## X/GL
    "${SRC_DIR}/glad.c"

    "${X_SRC_DIR}/Util.cpp"

    ## X/App
    "${X_SRC_DIR}/App.cpp"
    "${X_SRC_DIR}/Transform.cpp"

    ## X/GL
    "${X_SRC_DIR}/GL/Shader.cpp"
    "${X_SRC_DIR}/GL/VertexArray.cpp"
    "${X_SRC_DIR}/GL/VertexBuffer.cpp"
    "${X_SRC_DIR}/GL/IndexBuffer.cpp"

    ## X/Gfx
    "${X_SRC_DIR}/Gfx/Renderer.cpp"

    ## X/Model
    "${X_SRC_DIR}/Model/Model.cpp"

    ## X/Camera
    "${X_SRC_DIR}/Camera/Camera2D.cpp"
    "${X_SRC_DIR}/Camera/Camera3D.cpp"
)

# -----------------------------------------------------------------------------
# Link in the libraies the binary needs.
#
target_link_libraries(${BIN_NAME} ${X_LIB})

# Link SDL3
target_link_libraries(${BIN_NAME} SDL3::SDL3)

# Link OpenGL
target_link_libraries(${BIN_NAME} ${OPENGL_LIBRARY})
