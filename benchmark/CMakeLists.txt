cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(benchmark)

find_package(PCL 1.8 REQUIRED) # find PCL library and define the required version

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

include_directories(${CMAKE_SOURCE_DIR}/include) # include the directory where head files and source files are stored

SET(codes 
    src/main.cpp 
    src/hull_abstraction/reconstructor.cpp 
    src/hull_abstraction/preprocessor.cpp 
    src/pcl_utilization/pcl_utilization.cpp
    src/benchmark/benchmark.cpp
    src/benchmark/math_computing.cpp
    src/benchmark/point_generation.cpp
)

add_executable (hull_abstraction ${codes})
target_link_libraries (hull_abstraction ${PCL_LIBRARIES})
