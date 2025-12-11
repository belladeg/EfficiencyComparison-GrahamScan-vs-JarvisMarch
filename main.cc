/*
 *
 */

#include <fstream>
#include <iostream>
#include "point.h"

using std::vector;

int main() {
  std::ifstream file;
  file.open("Z:/CLionProjects/ConvexHullAlgorithmComparison/points.txt");
  if (!file.is_open()) {
    std::cerr << "ERROR: File not found." << std::endl;
    return 1;
  }

  vector<Point> points;
  while (!file.eof()) {
    std::string x_str, y_str;
    file >> x_str >> y_str;
    try {
      const auto x = std::stof(x_str);
      const auto y = std::stof(y_str);
      Point p = {x, y};
      points.push_back(p);
    } catch (const std::invalid_argument&) {
    }
  }

  // Convex hull is not possible with fewer than 3 points.
  std::vector<Point> graham_hull = GrahamScanConvexHull(points);
  PrintConvexHull(graham_hull, "Graham Scan");

  std::vector<Point> jarvis_hull = JarvisMarchConvexHull(points);
  PrintConvexHull(jarvis_hull, "Jarvis March");

  file.close();
  if (file.is_open()) {
    std::cerr << "ERROR: File could not be closed." << std::endl;
  }
  return 0;
}
