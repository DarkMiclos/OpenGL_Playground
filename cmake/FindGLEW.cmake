include(FindPackageHandleStandardArgs)

find_path(
  GLEW_INCLUDE_DIRS
  GL/glew.h
  PATHS $ENV{GLEW_DIR}
  DOC "The path to the directory that contains glew.h"
)

find_library(
  GLEW_LIBRARY
  NAMES glew32
  PATHS $ENV{GLEW_DIR}
  PATH_SUFFIXES lib/Release/x64 lib64 lib/Release/Win32 lib32
  DOC "Find the base GLEW library."
)

set(GLEW_LIBRARIES ${GLEW_LIBRARY})
unset(GLEW_LIBRARY)

find_package_handle_standard_args(
  GLEW
  DEFAULT_MSG
  GLEW_LIBRARIES
  GLEW_INCLUDE_DIRS
)