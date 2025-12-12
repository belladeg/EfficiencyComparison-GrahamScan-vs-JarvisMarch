/*
 *
 */

#include <chrono>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>

#include "point.h"

using std::vector;

int main() {
    std::cout << "DEBUG: I am running in this folder: " <<
    std::filesystem::current_path() << std::endl;

    std::cout << "Use random point generator? (Y/N): ";
    char input;
    std::cin >> input;
    if (input == 'Y' || input == 'y') {
        std::ofstream write_file;
        write_file.open("points.txt");
        if (!write_file.is_open()) {
            std::cerr << "ERROR: File not found." << std::endl;
            return 1;
        }

        int num_points;
        do {
            std::cout <<
            "Enter # of random points to generate (min 3, max 1000): ";
            if (std::cin >> num_points; !std::cin.good()) {
                std::cerr << "ERROR: Invalid input." << std::endl;
            } else if (num_points < 3 || num_points > 1000) {
                std::cerr << "ERROR: Input out of bounds." << std::endl;
                num_points = -1;
            }
        } while (std::cin.bad() || num_points == -1);

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> dist(-100.0, 100.0);
        for (auto i = 0; i < num_points; ++i) {
            write_file << std::fixed << std::setprecision(2) << dist(gen) << " "
            << dist(gen) << std::endl;
        }
    }
    std::ifstream file;
    file.open("points.txt");
    if (!file.is_open()) {
        std::cerr << "ERROR: File not found." << std::endl;
        return 1;
    }
    vector<Point> points;
    while (!file.eof()) {
        std::string x_str, y_str;
        file >> x_str >> y_str;
        try {
            const auto x = std::stof(x_str);
            const auto y = std::stof(y_str);
            Point p = {x, y};
            points.push_back(p);
        } catch (const std::invalid_argument&) {}
    }
    // Convex hull is not possible with fewer than 3 points.
    if (points.size() < 3) {
        std::cerr << "ERROR: At least 3 points required to compute convex hull."
        << std::endl;
        return 1;
    }

    auto start = std::chrono::steady_clock::now();
    auto graham_hull = GrahamScanConvexHull(points);
    auto stop = std::chrono::steady_clock::now();
    auto wall_clock_time = std::chrono::duration_cast<
        std::chrono::microseconds>(stop - start);
    PrintConvexHull(graham_hull, "Graham Scan");
    std::cout << "GS wall_clock_time: " << wall_clock_time.count() <<
    " microseconds" << std::endl;

    Counters::PrintCounters("GS");
    Counters::ResetCounters();
    std::cout << std::endl;

    start = std::chrono::steady_clock::now();
    auto jarvis_hull = JarvisMarchConvexHull(points);
    stop = std::chrono::steady_clock::now();
    wall_clock_time = std::chrono::duration_cast<std::chrono::microseconds>(
        stop - start);
    PrintConvexHull(jarvis_hull, "Jarvis March");
    std::cout << "JM wall_clock_time: " << wall_clock_time.count() <<
    " microseconds" << std::endl;

    Counters::PrintCounters("JM");

    //file.clear();
    file.close();
    if (file.is_open()) {
        std::cerr << "ERROR: File could not be closed." << std::endl;
    }
    return 0;
}
