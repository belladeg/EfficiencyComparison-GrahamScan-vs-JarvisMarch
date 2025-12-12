//
// Created by isabe on 12/06/2025.
//

#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <stack>
#include <vector>

struct Point {
  float x = 0.0;
  float y = 0.0;
};

class Counters {
public:
    static void IncrementCounter(const std::string& counter) {
        if (counter == "orientation") {
            ++orientation_counter;
        } else if (counter == "distance") {
            ++distance_counter;
        }
    }

    static void PrintCounters(const std::string& algorithm) {
        std::cout << algorithm << " orientation_counter: " <<
        orientation_counter << std::endl;
        std::cout << algorithm << " distance_counter: " << distance_counter <<
        std::endl;
    }

    static void ResetCounters() {
        orientation_counter = 0;
        distance_counter = 0;
    }

private:
    inline static int orientation_counter = 0;
    inline static int distance_counter = 0;
};

// Helper functions for both algorithms.
//
// Computes the orientation of three points. Returns 0 if collinear, 1 if
// clockwise, or 2 if counter-clockwise
inline int GetOrientation(const Point a, const Point b, const Point c) {
  if (const float result = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
      result == 0) {
    return 0;
  } else {
    if (result > 0)
      return 2;

    return 1;
  }
}

// Returns the distance squared between two points.
inline float DistanceSquared(const Point a, const Point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

inline void PrintConvexHull(std::vector<Point>& hull_pts, const std::string& algorithm) {
  std::cout << "Convex Hull Found Using " << algorithm << ":" << std::endl;
  while (!hull_pts.empty()) {
    auto [x, y] = hull_pts.back();
    std::cout << "(" << x << ", " << y << ")" << std::endl;
    hull_pts.pop_back();
  }
}

// Graham Scan functions.
//
// Finds the bottom-most point in the list and swaps it with the first point.
void SwapBottomPoint(std::vector<Point>&);
// FIXME add comment documentation
std::vector<Point>::size_type Partition(std::vector<Point>&,
                                        std::vector<Point>::size_type,
                                        std::vector<Point>::size_type);
// Performs QuickSort algorithm on the list of points.
void QuickSort(std::vector<Point>&, std::vector<Point>::size_type,
               std::vector<Point>::size_type);
// Returns the number of points on the convex hull.
/* FIXME std::vector<Point>::size_type FilterCollinearPoints(std::vector<Point>&,
                                                    std::vector<
                                                      Point>::size_type);*/
// Performs Graham Scan algorithm on the list of points, returning the list of
// points on the final convex hull.
std::vector<Point> GrahamScanConvexHull(std::vector<Point>);

// Jarvis March functions.
//
// Returns the index of the left-most point in the list.
std::vector<Point>::size_type FindLeftmostPoint(const std::vector<Point>&);
// Performs Jarvis March algorithm on the list of points, returning the list of
// points on the final convex hull.
std::vector<Point> JarvisMarchConvexHull(const std::vector<Point>&);


#endif //POINT_H
