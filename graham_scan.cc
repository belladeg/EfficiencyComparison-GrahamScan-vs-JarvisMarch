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
      if (DistanceSquared(points[0], points[i]) < DistanceSquared(points[0],       pivot)) {
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

/* FIXME
vector<Point>::size_type FilterCollinearPoints(
    vector<Point>& points,
    const vector<Point>::size_type n) {
  auto m = 1;  // Modified list size
  for (auto i = 1; i < n; ++i) {
    if (const int orient = GetOrientation(points[0], points[m], points[i]);
        orient != 0) {
      ++m;
      points[m] = points[i];
    } else {
      points[n] = points[i];
    }
  }
  return (n + 1);
}*/


std::stack<Point> GrahamScanConvexHull(vector<Point> points) {
  const vector<Point>::size_type n = points.size();
  if (n < 3) {
    // TODO replace empty_list by returning num
    std::stack<Point> empty_stack;
    return empty_stack;
  }
  // Sort points by increasing polar angle relative to bottom point
  SwapBottomPoint(points);
  QuickSort(points, 1, n - 1);

  /*const vector<Point>::size_type listSize = FilterCollinearPoints(points, size);
  if (listSize < 3)
  {
      vector<Point> emptyList;
      return emptyList;
  }*/
  std::stack<Point> hull;
  hull.push(points[0]);
  hull.push(points[1]);
  hull.push(points[2]);
  for (vector<Point>::size_type i = 3; i < n; i++) {
    while (hull.size() >= 2) {
      Point top = hull.top();
      hull.pop();
      if (const Point next_to_top = hull.top(); GetOrientation(next_to_top, top,
                                                               points[i]) != 2)
        continue;
      hull.push(top);
      break;
    }
    hull.push(points[i]);
  }
  /*
{

  //const int orient = Orientation();
  while (hullPoints.size() > 1 && orient = Orientation(
      points[size - 2], points[size - 1],
      points[i]) != 2) // not counter-clockwise
  {
      hullPoints.pop_back();
      size = points.size();
      orient = Orientation(points[size - 2], points.back(),
                            points[i]);
  }
  hullPoints.push_back(points[i]);
}*/
  return hull;
}
