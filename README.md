# Efficiency Comparison - Graham Scan vs. Jarvis March

This project implements and compares two fundamental algorithms for solving the
Convex Hull
problem: the
**Graham Scan** (using QuickSort) and
the **Jarvis March**. The primary goal is to analyze the algorithmic efficiency
of both approaches by
measuring execution time and counting basic operations across various dataset
sizes.

## Project Architecture

### File Structure

* **main.cc**: Entry point. Handles user input, menu selection, and
  coordinates algorithm execution.
* **point.h**: Defines the 'Point' struct, Counters class (for efficiency
  comparison), and helper
  functions
  used by both
  algorithms.
* **graham_scan.cc**: Implementation of the Graham Scan algorithm (sorting
  based on polar angle).
* **jarvis_march.cc**: Implementation of the Jarvis March (Gift Wrapping)
  algorithm.
* **points.txt**: Source file for dataset input.

### System Tested On

* **OS:** Windows 11
* **Compiler:** MinGW w/ GCC 11.0 (x64)
* **IDE:** CLion 2025.2.4

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

6. **Run the executable**
    ~~~bash
   Debug/ConvexHullAlgorithmComparison.exe
    ~~~

## Usage

Upon launch, the program will prompt you to select an input method for the
dataset. Both the Graham Scan and Jarvis March algorithms will process the
**same** set of points to ensure a fair efficiency comparison.

### 1. Random Generation

Select this option to test the algorithms' performance on large datasets.

* You will be prompted to enter the **number of points** to generate.
* The program will randomly generate coordinates (x, y) and **automatically
  save them to 'points.txt'**.
* This is best for observing how execution time scales as $N$ increases.

### 2. File Input

Select this option to test specific datasets or edge cases.

* The program reads the coordinates currently stored in `points.txt`.
* **Note:** If you previously ran "Random Generation", `points.txt` will contain
  that generated dataset.
* **Tip:** You can manually edit `points.txt` in the source folder to test
  specific coordinates (remember to rebuild to update the copy).

**Input File Format:**
The program reads coordinates as a continuous sequence of integers separated by
whitespace (spaces or newlines).

**Example Input:**

~~~text
10 5
2 8 15 22
4 1 7 9 3
1
~~~

### Output

The program will output the following for **both** algorithms:

1. **Convex Hull Points:** The specific coordinates that form the boundary.
2. **Execution Time:** Measured in microseconds.
3. **Basic Operations Count:** The total number of geometric comparisons or
   orientation checks performed.

## Troubleshooting

If the input file ('points.txt') is not updating or the build seems cached:

1. **Force a rebuild**
    ~~~bash
   cmake --build . --target clean
   cmake --build .
   ~~~
2. **Verify file location**
   Ensure 'points.txt' is located in the same directory as the executable.
