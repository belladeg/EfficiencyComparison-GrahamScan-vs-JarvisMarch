//
// Created by Isabella on 12/06/2025.
//

//#include <filesystem>
#include "point.h"

using std::vector;

void SwapBottomPoint(vector<Point>& points) {
  vector<Point>::size_type min_index = 0;

  for (vector<Point>::size_type i = 1; i < points.size(); ++i) {
    if (points[i].y < points[min_index].y) {
      min_index = i;
    } else if (points[i].y == points[min_index].y) {
      if (points[i].x < points[min_index].x) {
        min_index = i;
      }
    }
  }
  std::swap(points[0], points[min_index]);
}


vector<Point>::size_type Partition(vector<Point>& points,
                                   const vector<Point>::size_type low,
                                   const vector<Point>::size_type high) {
  const Point pivot = points[high];
  vector<Point>::size_type last_index = low - 1;

  for (vector<Point>::size_type i = low; i < high; ++i) {
    if (const int orient = GetOrientation(points[0], points[i], pivot);
      orient == 0) {
      if (DistanceSquared(points[0], points[i]) < DistanceSquared(
            points[0], pivot)) {
        ++last_index;
        std::swap(points[last_index], points[i]);
      }
    } else if (orient == 2) {
      ++last_index;
      std::swap(points[last_index], points[i]);
    }
  }
  std::swap(points[last_index + 1], points[high]);
  return last_index + 1;
}


void QuickSort(vector<Point>& points, const vector<Point>::size_type low,
               const vector<Point>::size_type high) {
  if (low < high) {
    const vector<Point>::size_type pivot_index = Partition(points, low, high);
    QuickSort(points, low, pivot_index - 1);
    QuickSort(points, pivot_index + 1, high);
  }
}


std::vector<Point> GrahamScanConvexHull(vector<Point> points) {
  const vector<Point>::size_type n = points.size();
  if (n < 3) // Convex hull is not possible.
    return {};

  SwapBottomPoint(points);
  // Sort points by increasing polar angle relative to the bottom point.
  QuickSort(points, 1, n - 1);

  std::vector<Point> hull_stack;
  hull_stack.push_back(points[0]);
  hull_stack.push_back(points[1]);
  hull_stack.push_back(points[2]);
  for (vector<Point>::size_type i = 3; i < n; ++i) {
    while (hull_stack.size() >= 2) {
      Point top = hull_stack.back();
      hull_stack.pop_back();

      if (const Point next_to_top = hull_stack.back(); GetOrientation(
                                                         next_to_top, top,
                                                         points[i]) != 2)
        continue;

      hull_stack.push_back(top);
      break;
    }

    hull_stack.push_back(points[i]);
  }

  return hull_stack;
}
