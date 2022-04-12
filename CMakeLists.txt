cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

project(
  opengl_playground
)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

set(GLFW_DIR "D:/GLFW")
set(GLEW_DIR "D:/OpenGL")

message(${GLFW_DIR})
message(${GLEW_DIR})

find_package(
  GLFW
  REQUIRED
)

find_package(
  OpenGL
  REQUIRED
)

find_package(
  GLEW
  REQUIRED
)

add_subdirectory(playground)