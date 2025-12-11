/*
 *
 */

#include <fstream>
#include <iostream>
#include "point.h"

using std::vector;

int main() {
  std::ifstream input_file;
  input_file.open("Z:/CLionProjects/ConvexHullAlgorithmComparison/points.txt");
  if (!input_file.is_open()) {  // TODO replace std::cerr
    std::cerr << "ERROR: File not found." << std::endl;
    return 1;
  }

  vector<Point> points;
  while (!input_file.eof()) {
    std::string x_str, y_str;
    input_file >> x_str >> y_str;
    try {
      const auto x = std::stof(x_str);
      const auto y = std::stof(y_str);
      Point p = {x, y};
      points.push_back(p);
    } catch (const std::invalid_argument&) {
      //std::cerr << "ERROR: " << ia.what() << std::endl;
      //continue;
    }
  }

  // Convex hull is not possible with fewer than 3 points.
  if (std::stack<Point> graham_hull = GrahamScanConvexHull(points);
      graham_hull.size() < 3) {
    std::cerr << "ERROR: At least 3 points required to compute convex hull." <<
    std::endl;
    return 1;
  } else {
    std::cout << "Convex Hull Found Using Graham Scan:" << std::endl;
    while (!graham_hull.empty()) {
      auto [x, y] = graham_hull.top();
      std::cout << "(" << x << ", " << y << ")" << std::endl;
      graham_hull.pop();
    }
  }

  if (std::vector<Point> jarvis_hull = JarvisMarchConvexHull(points);
      jarvis_hull.size() < 3) {
    std::cerr << "ERROR: At least 3 points required to compute convex hull." <<
    std::endl;
    return 1;
  } else {
    std::cout << "Convex Hull Found Using Jarvis March:" << std::endl;
    while (!jarvis_hull.empty()) {
      auto [x, y] = jarvis_hull.back();
      std::cout << "(" << x << ", " << y << ")" << std::endl;
      jarvis_hull.pop_back();
    }
  }

  input_file.close();
  if (input_file.is_open()) { // TODO replace std::cerr
    std::cerr << "ERROR: File could not be closed." << std::endl;
  }
  return 0;
}
