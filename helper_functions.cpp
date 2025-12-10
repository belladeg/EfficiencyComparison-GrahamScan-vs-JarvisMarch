//
// Created by isabe on 12/09/2025.
//

#include "point.h"

int Orientation(const Point a, const Point b, const Point c) {
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

// Function to compute the distance between two points
float Distance(const Point a, const Point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
