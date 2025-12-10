/*
 *
 */

#include <fstream>
#include <iostream>
#include "point.h"
//#include "GrahamScan.cpp"
//#include "JarvisMarch.cpp"

int main()
{
    // Open input file
    std::ifstream InputFile;
    InputFile.open("Z:/CLionProjects/ConvexHullAlgorithmComparison/points.txt");
    if (!InputFile.is_open())
    {
        std::cerr << "ERROR: File not found." << std::endl;
        return 1;
    }

    // Read each x,y value from file into Point object, store in points vector
    vector<Point> points;
    while (!InputFile.eof())
    {
        std::string xStr, yStr;
        InputFile >> xStr >> yStr;
        const float x = std::stof(xStr);
        const float y = std::stof(yStr);
        Point p = {x, y};
        points.push_back(p);
    }

    // Call function to perform Graham Scan
    // Convex hull not possible with fewer than 3 points
    if (std::stack<Point> grahamHull = GrahamScan(points); grahamHull.size() < 3)
    {
        std::cerr << "ERROR: At least 3 points required to compute convex hull."
            << std::endl;
        return 1;
    }

    // Print each point on the convex hull
    else
    {
        std::cout << "Convex Hull Found:" << std::endl;
        while (!grahamHull.empty())
        {
            auto [x, y] = grahamHull.top();
            std::cout << "(" << x << ", " << y << ")" << std::endl;
            grahamHull.pop();
        }
    }
    //std::vector<Point> jarvisHull;  // invoke jarvis march

    // Close input file
    InputFile.close();
    if (InputFile.is_open())
    {
        std::cerr << "ERROR: File could not be closed." << std::endl;
    }
    return 0;
}