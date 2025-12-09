//
// Created by Isabella on 12/06/2025.
//

#include <filesystem>
#include <vector>
#include "Point.h"


Point BottomPoint(vector<Point>& points)
{
    Point bottomPoint = points[0];
    int minIndex = 0;

    for (int i = 1; i < points.size(); i++)
    {
        if (points[i].y < bottomPoint.y)
        {
            bottomPoint = points[i];
            minIndex = i;
        }
        else if (points[i].y == bottomPoint.y)
        {
            if (points[i].x < bottomPoint.x)
            {
                bottomPoint = points[i];
                minIndex = i;
            }
        }
    }
    std::swap(points[0], points[minIndex]);
    return bottomPoint;
}


int Orientation(const Point a, const Point b, const Point c)
{
    if (const float orient = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.
        x); orient == 0) // collinear
        return 0;
    else
    {
        if (orient > 0)    // counter-clockwise
            return 2;
        // clockwise
        return 1;
    }
}


float Distance(const Point a, const Point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}


vector<Point>::size_type Partition(vector<Point>& points,
                                   const vector<Point>::size_type low,
                                   const vector<Point>::size_type high)
{
    const Point pivot = points[high];
    vector<Point>::size_type lastIndex = low - 1;

    for (vector<Point>::size_type i = low; i < high; i++)
    {
        if (const int orient = Orientation(points[0], points[i], pivot); orient
            == 0) // collinear
        {
            const float dist1 = Distance(points[0], points[i]);
            if (const float dist2 = Distance(points[0], pivot); dist1 < dist2)
            {
                lastIndex++;
                std::swap(points[lastIndex], points[i]);
            }
        }
        else if (orient == 2)   // counter-clockwise
        {
            lastIndex++;
            std::swap(points[lastIndex], points[i]);
        }
    }
    std::swap(points[lastIndex + 1], points[high]);
    return lastIndex + 1;
}


void QuickSort(vector<Point>& points, const vector<Point>::size_type low,
               const vector<Point>::size_type high)
{
    if (low < high)
    {
        const vector<Point>::size_type pivotIndex = Partition(points, low, high);

        QuickSort(points, low, pivotIndex - 1);
        QuickSort(points, pivotIndex + 1, high);
    }
}


vector<Point>::size_type FilterCollinearPoints(vector<Point>& points,
                                               const vector<Point>::size_type
                                               listSize)
{
    int newSize = 1;

    for (int i = 2; i < listSize; i++)
    {
        if (const int orient = Orientation(points[0], points[newSize],
                                           points[i]); orient != 0)
        // counter- or clockwise
        {
            newSize++;
            points[newSize] = points[i];
        }
        else
            points[newSize] = points[i];
    }
    return newSize + 1;
}


vector<Point> GrahamScan(vector<Point> &points)
{
    vector<Point>::size_type size = points.size();

    if (size < 3)
    {
        vector<Point> emptyList;
        return emptyList;
    }
    // sort points by increasing polar angle relative to bottom point
    BottomPoint(points);
    QuickSort(points, 1, size - 1);

    const vector<Point>::size_type listSize = FilterCollinearPoints(points, size);
    if (listSize < 3)
    {
        vector<Point> emptyList;
        return emptyList;
    }
    vector<Point> hullPoints;
    hullPoints.push_back(points[0]);
    hullPoints.push_back(points[1]);
    //hullPoints.push_back(points[2]);
    for (int i = 3; i < listSize; i++)
    {
        int orient = Orientation(points[size - 2], points[size - 1], points[i]);
        //const int orient = Orientation();
        while (hullPoints.size() > 1 && orient != 2) // not counter-clockwise
        {
            hullPoints.pop_back();
            size = points.size();
            orient = Orientation(points[size - 2], points.back(),
                                  points[i]);
        }
        hullPoints.push_back(points[i]);
    }
    return hullPoints;
}