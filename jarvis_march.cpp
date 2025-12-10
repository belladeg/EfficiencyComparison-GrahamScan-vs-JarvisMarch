//
// Created by isabe on 12/06/2025.
//

#include "point.h"

int LeftmostPoint(vector<Point>& points)
{
    int minIndex = 0;

    for (int i = 1; i < points.size(); i++)
    {
        if (points[i].x < points[minIndex].x)
        {
            minIndex = i;
        }
        else if (points[i].x == points[minIndex].x)
        {
            if (points[i].y < points[minIndex].y)
            {
                minIndex = i;
            }
        }
    }

    return minIndex;
}