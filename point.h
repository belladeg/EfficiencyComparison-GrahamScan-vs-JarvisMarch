//
// Created by isabe on 12/06/2025.
//

#ifndef POINT_H
#define POINT_H
#include <stack>
#include <vector>

struct Point {
  float x = 0.0;
  float y = 0.0;
};


// Graham Scan functions.
//
// Finds the bottom-most point in the list and swaps it with the first point.
void SwapBottomPoint(std::vector<Point>&);
// TODO add comment documentation
std::vector<Point>::size_type Partition(std::vector<Point>&,
                                        std::vector<Point>::size_type,
                                        std::vector<Point>::size_type);
// Performs QuickSort algorithm on the list of points.
void QuickSort(std::vector<Point>&, std::vector<Point>::size_type,
               std::vector<Point>::size_type);
// Returns the number of points on the convex hull.
std::vector<Point>::size_type FilterCollinearPoints(std::vector<Point>&,
                                                    std::vector<
                                                      Point>::size_type);
// Performs Graham Scan algorithm on the list of points, returning the list of
// points on the final convex hull.
std::stack<Point> GrahamScanConvexHull(std::vector<Point>);


// Jarvis March functions.
//
// Returns the index of the left-most point in the list.
std::vector<Point>::size_type FindLeftmostPoint(std::vector<Point>&);
// Performs Jarvis March algorithm on the list of points, returning the list of
// points on the final convex hull.
std::vector<Point> JarvisMarchConvexHull(std::vector<Point>&);

// Helper functions for both algorithms.
//
// Computes the orientation of three points. Returns 0 if collinear, 1 if
// clockwise, or 2 if counter-clockwise
inline int GetOrientation(const Point a, const Point b, const Point c) {
  if (const float orient = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
      orient == 0) {
    return 0;
      } else {
        if (orient > 0)  // counter-clockwise
          return 2;
        // clockwise
        return 1;
      }
}

// Returns the distance squared between two points.
inline float DistanceSquared(const Point a, const Point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

#endif //POINT_H
