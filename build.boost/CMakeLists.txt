cmake_minimum_required(VERSION 3.15)
## for find_package
cmake_policy(SET CMP0074 NEW)
## for CMAKE_MSVC_RUNTIME_LIBRARY
cmake_policy(SET CMP0091 NEW)
## project
project(boost-sample)

## option for using static library
## if this value is changed, delete cache and re-configure.
option(WITH_STATIC_LIBRARY "Build with static library" ON)

## configuration of output file location
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

## configuration of library linking
if(WITH_STATIC_LIBRARY)
  ## static library linking
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
  set(Boost_USE_STATIC_LIBS ON)
  set(Boost_USE_STATIC_RUNTIME ON)
else()
  ## dynamic library linking
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
  set(Boost_USE_STATIC_LIBS OFF)
  set(Boost_USE_STATIC_RUNTIME OFF)
endif()

## search boost library
## system environment `BOOST_ROOT` must be set.
find_package(Boost REQUIRED COMPONENTS regex)

## result of finding boost library 
if(NOT Boost_FOUND)
  message(FATAL_ERROR "Boost NOT FOUND")
else()
  message("BOOST Version: ${Boost_VERSION}")
  message("BOOST_ROOT: ${BOOST_ROOT}")
  message("BOOST_INCLUDEDIR: ${Boost_INCLUDE_DIRS}")
  message("BOOST_LIBRARYDIR: ${Boost_LIBRARY_DIRS}")
endif()

## additional library directories for boost.
link_directories("${Boost_LIBRARY_DIRS}")

## additional include directories for boost.
include_directories("${Boost_INCLUDE_DIRS}")

## additional include directories for project.
include_directories("${CMAKE_SOURCE_DIR}/src")

## main source directory
add_subdirectory(src)
