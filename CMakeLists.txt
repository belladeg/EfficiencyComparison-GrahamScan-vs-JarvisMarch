cmake_minimum_required(VERSION 4.0)
project(ConvexHullAlgorithmComparison)

set(CMAKE_CXX_STANDARD 20)

add_executable(ConvexHullAlgorithmComparison main.cc Point.h graham_scan.cc
        jarvis_march.cc points.txt
)
