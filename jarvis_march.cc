//
// Created by isabe on 12/06/2025.
//

#include "point.h"
using std::vector;

vector<Point>::size_type FindLeftmostPoint(const vector<Point>& points) {
  vector<Point>::size_type minIndex = 0;

  for (vector<Point>::size_type i = 1; i < points.size(); i++) {
    if (points[i].x < points[minIndex].x) {
      minIndex = i;
    } else if (points[i].x == points[minIndex].x) {
      if (points[i].y < points[minIndex].y) {
        minIndex = i;
      }
    }
  }

  return minIndex;
}

std::vector<Point> JarvisMarchConvexHull(const std::vector<Point>& points) {
  const vector<Point>::size_type n = points.size();
  if (n < 3) {
    // TODO replace empty_list by returning num
    std::vector<Point> empty_list;
    return empty_list;
  }

  const vector<Point>::size_type start_idx = FindLeftmostPoint(points);
  vector<Point>::size_type current_idx = start_idx;

  std::vector<Point> hull;
  do {
    hull.push_back(points[current_idx]);

    vector<Point>::size_type next_idx = (current_idx + 1) % n;

    for (vector<Point>::size_type i = 0; i < n; i++) {
      if (const int orient = GetOrientation(points[current_idx], points[i], points[next_idx]); orient == 2) {
        next_idx = i;
      } else if (orient == 0) {
        const float dist1 = DistanceSquared(points[current_idx], points[i]);
        const float dist2 = DistanceSquared(points[current_idx],
                                            points[next_idx]);
        if (dist1 > dist2) {
          next_idx = i;
        }
      }
    }
    current_idx = next_idx;
  } while (current_idx != start_idx);

  return hull;
}
