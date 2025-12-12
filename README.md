# Efficiency Comparison - Graham Scan vs. Jarvis March

This project implements and compares two fundamental algorithms for solving the
Convex Hull
problem: the
**Graham Scan** (using QuickSort) and
the **Jarvis March**. The primary goal is to analyze the algorithmic efficiency
of both approaches by
measuring execution time and counting basic operations across various dataset
sizes.

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

2. **Navigate to the project directory**
    ~~~bash
   cd EfficiencyComparison-GrahamScan-vs-JarvisMarch
   ~~~

3. **Create a build directory**
    ~~~bash
   mkdir build
   cd build
   ~~~

4. **Generate build files**
    ~~~bash
    cmake ..
   ~~~

5. **Compile**
    ~~~bash
   cmake --build .
   ~~~

6. **Navigate to the executable**
    ~~~bash
   cd ..
   cd cmake-build-debug/
    ~~~

7. **Run .exe**
    ~~~bash
    ./ConvexHullAlgorithmComparison.exe
    ~~~

## Usage

Upon launch, the program will prompt you to select an input method for the
dataset. Both the Graham Scan and Jarvis March algorithms will process the
**same** set of points to ensure a fair efficiency comparison.

### 1. Random Generation

Select this option to test the algorithms' performance on large datasets.

* You will be prompted to enter the **number of points** to generate.
* The program will randomly generate coordinates (x, y) up to the specified
  limit.
* This is best for observing how execution time scales as $N$ increases.

### 2. File Input

Select this option to test specific datasets or edge cases.
