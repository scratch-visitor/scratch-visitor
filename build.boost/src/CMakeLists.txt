cmake_minimum_required(VERSION 3.10)

## source files.
FILE(GLOB_RECURSE FILE_SOURCES "*.cpp")
## header files.
FILE(GLOB_RECURSE FILE_HEADERS "*.hpp")

## this project is for executable file.
add_executable(${CMAKE_PROJECT_NAME}
  ${FILE_SOURCES}
  ${FILE_HEADERS}
)
## additional link libraries for boost.
target_link_libraries(${CMAKE_PROJECT_NAME} ${Boost_LIBRARIES})