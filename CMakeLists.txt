cmake_minimum_required(VERSION 3.10)
project(topological_sort)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++23")

include_directories("topological_sort/algorithms/")
include_directories("topological_sort/tests/")

set(SRC_DIR topological_sort/tests/)

set(SRC_LIST
    ${SRC_DIR}/DataSetRegister.cpp 
    ${SRC_DIR}/GraphReader.cpp 
    ${SRC_DIR}/logger.cpp 
    ${SRC_DIR}/../algorithms/algorithms.cpp
    )

add_executable(${PROJECT_NAME}.exe ${SRC_LIST})
