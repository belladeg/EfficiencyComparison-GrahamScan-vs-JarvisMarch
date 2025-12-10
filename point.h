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

// Computes the orientation of three points. Returns 0 if collinear, 1 if
// clockwise, or 2 if counter-clockwise
int GetOrientation(Point, Point, Point);
// Returns the distance squared between two points.
float DistanceSquared(Point, Point);

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
std::stack<Point> GrahamScanConvexHull(std::vector<Point>&);

// Returns the index of the left-most point in the list.
std::vector<Point>::size_type FindLeftmostPoint(const std::vector<Point>&);
// Performs Jarvis March algorithm on the list of points, returning the list of
// points on the final convex hull.
std::vector<Point> JarvisMarchConvexHull(std::vector<Point>&);

#endif //POINT_H
