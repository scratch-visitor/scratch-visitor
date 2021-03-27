cmake_minimum_required(VERSION 3.10)

## source files.
set(FILE_SOURCES
 "main.cpp"
)
## header files.
set(FILE_HEADERS
)

## this project is for executable file.
add_executable(${CMAKE_PROJECT_NAME}
  ${FILE_SOURCES}
  ${FILE_HEADERS}
)
## additional link libraries for boost.
target_link_libraries(${CMAKE_PROJECT_NAME} ${Boost_LIBRARIES})