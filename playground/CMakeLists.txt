# CMakeList.txt : CMake project for CMakeProject1, include source and define
# project specific logic here.
#
# Add source to this project's executable.

set(EXECUTABLE_NAME "playground")

set(
  ${EXECUTABLE_NAME}_src
  "playground.cpp"
)

set(
  ${EXECUTABLE_NAME}_header
  "playground.h"
)

add_executable(
  ${EXECUTABLE_NAME}
  ${${EXECUTABLE_NAME}_src}
  ${${EXECUTABLE_NAME}_header}
)

target_include_directories(
  ${EXECUTABLE_NAME}
  PRIVATE ${GLEW_INCLUDE_DIRS}
  PRIVATE ${GLFW_INCLUDE_DIRS}
)

target_link_libraries(
  ${EXECUTABLE_NAME}
  PRIVATE ${OPENGL_LIBRARIES}
  PRIVATE ${GLEW_LIBRARIES}
  PRIVATE ${GLFW_LIBRARIES}
)

# TODO: Add tests and install targets if needed.
