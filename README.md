# Efficiency Comparison - Graham Scan vs. Jarvis March

This project implements two algorithms to solve the convex hull
problem: the
Graham Scan, using QuickSort, and
the Jarvis March. Input is gathered as a list of ordered pairs that is either
read
from a
file or randomly generated up to a specified limit. The efficiency of each
algorithm is
observed by metrics for execution time and counting basic operations, which
are included in output.

## Installation & Execution

### Prerequisites

* **C++ Compiler:** Any standard compiler (GCC, Clang, MSVC). C++17 or later
  recommended.
* **CMake:** Version 3.5 or higher.
* **IDE:** CLion (recommended) or Visual Studio Code.

### Steps to Run

1. **Clone the repository**
    ~~~bash
   git clone https://github.com/belladeg/EfficiencyComparison-GrahamScan-vs-JarvisMarch.git
    ~~~
2. **Create a build directory**
    ~~~bash
   mkdir build
   cd build
   ~~~
3. **Compile**
    ~~~bash
   cmake ..
   make
   ~~~
4. **Run the executable**
    ~~~bash
   ./ConvexHullAlgorithmComparison.exe

## Usage
