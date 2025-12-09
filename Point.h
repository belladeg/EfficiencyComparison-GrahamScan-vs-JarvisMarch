//
// Created by isabe on 12/06/2025.
//

#ifndef POINT_H
#define POINT_H

using std::vector;

struct Point
{
    float x, y;
};

Point BottomPoint(vector<Point>&);
int Orientation(Point, Point, Point);
float Distance(Point, Point);
vector<Point>::size_type Partition(vector<Point>&, vector<Point>::size_type, vector<Point>::size_type high);
void QuickSort(std::vector<Point>&, vector<Point>::size_type, vector<Point>::size_type);
vector<Point>::size_type FilterCollinearPoints(vector<Point>&, vector<Point>::size_type);
vector<Point> GrahamScan(vector<Point>&);

#endif //POINT_H
