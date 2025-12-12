//
// Created by isabe on 12/06/2025.
//

#include "point.h"

using std::vector;

vector<Point>::size_type FindLeftmostPoint(const vector<Point>& points) {
  vector<Point>::size_type min_index = 0;

  for (vector<Point>::size_type i = 1; i < points.size(); ++i) {
    if (points[i].x < points[min_index].x) {
      min_index = i;
    } else if (points[i].x == points[min_index].x) {
      if (points[i].y < points[min_index].y) {
        min_index = i;
      }
    }
  }
  return min_index;
}

std::vector<Point> JarvisMarchConvexHull(const std::vector<Point>& points) {
  const vector<Point>::size_type start_idx = FindLeftmostPoint(points);
  vector<Point>::size_type current_idx = start_idx;
  std::vector<Point> hull;

  do {
    hull.push_back(points[current_idx]);
    vector<Point>::size_type next_idx = (current_idx + 1) % points.size();

    for (vector<Point>::size_type i = 0; i < points.size(); ++i) {

      Counters::IncrementCounter("orientation");
      if (const int orient = GetOrientation(points[current_idx], points[i],
                                            points[next_idx]); orient == 2) {
        next_idx = i;
      } else if (orient == 0) {

        Counters::IncrementCounter("distance");
        Counters::IncrementCounter("distance");
        if (DistanceSquared(points[current_idx], points[i]) > DistanceSquared(
          points[current_idx], points[next_idx])) {
          next_idx = i;
        }
      }
    }
    current_idx = next_idx;
  } while (current_idx != start_idx);
  return hull;
}
