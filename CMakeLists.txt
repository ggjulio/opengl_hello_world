# Disable in-source builds to prevent source tree corruption.
# if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
#   message(FATAL_ERROR "
# FATAL: In-source builds are not allowed.
#        You should create a separate directory for build files.
# ")
# endif()

# Disable in source build too
# set(CMAKE_DISABLE_SOURCE_CHANGES ON)
# set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

cmake_minimum_required( VERSION 3.0.0 )
project( opengl_hello_world )

# add_subdirectory(first_window)
