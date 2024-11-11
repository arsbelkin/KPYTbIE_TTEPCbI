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
    ${SRC_DIR}/tests_functions.cpp
    ${SRC_DIR}/../algorithms/algorithms.cpp
    ${SRC_DIR}/../algorithms/Demukrone_by_Balpeisov.cpp
    # здесь указывается относительный путь до вашего файла
    # пример:
    # ${SRC_DIR}/../algorithms/topological_sort.cpp
    ${SRC_DIR}/../algorithms/TaryanSort_by_Maslov.cpp
    )

add_executable(${PROJECT_NAME}.exe ${SRC_LIST})
