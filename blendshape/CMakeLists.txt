cmake_minimum_required(VERSION 2.8)

project(FaceReshape)

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2 -g")

find_package(Eigen3)

include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(main main.cpp face_reshape.cpp)
