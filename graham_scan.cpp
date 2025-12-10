//
// Created by Isabella on 12/06/2025.
//

//#include <filesystem>
#include "point.h"


Point BottomPoint(vector<Point>& points)
{
    Point p = points[0];
    int minIndex = 0;

    for (int i = 1; i < points.size(); i++)
    {
        if (points[i].y < p.y)
        {
            p = points[i];
            minIndex = i;
        }
        else if (points[i].y == p.y)
        {
            if (points[i].x < p.x)
            {
                p = points[i];
                minIndex = i;
            }
        }
    }
    std::swap(points[0], points[minIndex]);
    return p;
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
                                               n)
{
    int m = 1;

    for (int i = 1; i < n; i++)
    {
        if (const int orient = Orientation(points[0], points[m],
                                           points[i]); orient != 0)
        // counter- or clockwise
        {
            m++;
            points[m] = points[i];
        }
        else
            points[n] = points[i];
    }
    return n + 1;
}


std::stack<Point> GrahamScan(vector<Point>& points)
{
    vector<Point>::size_type n = points.size();

    if (n < 3)
    {
        std::stack<Point> emptyList;
        return emptyList;
    }
    // sort points by increasing polar angle relative to bottom point
    BottomPoint(points);
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
    for (int i = 3; i < n; i++)
    {
        while (hull.size() >= 2)
        {
            Point top = hull.top(); hull.pop();
            Point nextToTop = hull.top();
            if (Orientation(nextToTop, top, points[i]) != 2)
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