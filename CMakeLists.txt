cmake_minimum_required(VERSION 3.5)
project(ConvexHullAlgorithmComparison)

set(CMAKE_CXX_STANDARD 17)

add_executable(ConvexHullAlgorithmComparison main.cc Point.h graham_scan.cc
        jarvis_march.cc points.txt)
