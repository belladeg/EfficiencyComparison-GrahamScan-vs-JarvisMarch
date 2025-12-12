cmake_minimum_required(VERSION 3.5...4.0)
project(ConvexHullAlgorithmComparison)

set(CMAKE_CXX_STANDARD 17)

add_executable(ConvexHullAlgorithmComparison main.cc Point.h graham_scan.cc
        jarvis_march.cc points.txt)

configure_file(${CMAKE_SOURCE_DIR}/points.txt ${CMAKE_BINARY_DIR}/points.txt COPYONLY)
