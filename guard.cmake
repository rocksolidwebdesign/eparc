file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)

# exe names must be unique anyway so just put them
# in the root of the build dir for easier running
# from the command line
if(EXISTS "${LOC_PATH}")
  message(FATAL_ERROR "Oops! You cannot build in a source directory.")
endif()
