/*
 *
 */

#include <fstream>
#include <iostream>
#include <vector>
#include "Point.h"
//#include "GrahamScan.cpp"
//#include "JarvisMarch.cpp"

int main()
{
    std::ifstream InputFile;
    InputFile.open("points.txt");
    if (!InputFile.is_open())
    {
        std::cerr << "ERROR: File not found." << std::endl;
        return 1;
    }

    vector<Point> points;
    while (!InputFile.eof())   // Read x,y from file until end
    {
        std::string xStr, yStr;
        InputFile >> xStr >> yStr;
        const float x = std::stof(xStr);
        const float y = std::stof(yStr);

        Point p = {x, y};
        points.push_back(p);    // Add Point to points list
    }
    if (vector<Point> grahamHull = GrahamScan(points); grahamHull.size() < 3)
    {
        std::cerr << "ERROR: At least 3 points required to compute convex hull."
            << std::endl;
        return 1;
    }
    else
    {
        std::cout << "Convex Hull Found:" << std::endl;
        while (!grahamHull.empty())
        {
            auto [x, y] = grahamHull.back();
            std::cout << "(" << x << ", " << y << ")" << std::endl;
            grahamHull.pop_back();
        }
    }
    //std::vector<Point> jarvisHull;  // invoke jarvis march

    InputFile.close();
    if (InputFile.is_open())
    {
        std::cerr << "ERROR: File could not be closed." << std::endl;
    }
    return 0;

}