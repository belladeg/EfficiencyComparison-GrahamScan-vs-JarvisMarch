cmake_minimum_required(VERSION 4.0)
project(ConvexHullAlgorithmComparison)

set(CMAKE_CXX_STANDARD 23)

add_executable(ConvexHullAlgorithmComparison main.cpp Point.h
        graham_scan.cpp
        jarvis_march.cpp points.txt
        helper_functions.cpp
)
