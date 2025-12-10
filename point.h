//
// Created by isabe on 12/06/2025.
//

#ifndef POINT_H
#define POINT_H
#include <stack>
#include <vector>
using std::vector;

struct Point
{
    float x, y;
};

// Returns the orientation of three points, which can be 0
int Orientation(Point, Point, Point);
float Distance(Point, Point);

// Graham Scan functions
Point BottomPoint(vector<Point>&);
vector<Point>::size_type Partition(vector<Point>&, vector<Point>::size_type,
                                   vector<Point>::size_type);
void QuickSort(vector<Point>&, vector<Point>::size_type,
               vector<Point>::size_type);
vector<Point>::size_type FilterCollinearPoints(vector<Point>&,
                                               vector<Point>::size_type);
std::stack<Point> GrahamScan(vector<Point>&);

// Jarvis March functions
int LeftmostPoint(vector<Point>&);
std::stack<Point> JarvisMarch(vector<Point>&);

#endif //POINT_H
