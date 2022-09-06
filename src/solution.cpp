#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

#include "point.hpp"
#include "plane.hpp"
#include "operations.hpp"
#include "solution.hpp"

void Solution::run() {
    std::string initPointsFileName;
    std::string initPlanesFileName;

    std::cout << "Enter points.txt file name:" << std::endl;
    std::cin >> initPointsFileName;
    std::cout << "Enter planes.txt file name:" << std::endl;
    std::cin >> initPlanesFileName;

    std::vector<Plane> planes = getPlanesFromFile(initPlanesFileName.insert(0, DIR_PATH));

    std::string goodPointsFilePath = initPointsFileName;
    goodPointsFilePath = (goodPointsFilePath.insert(0, DIR_PATH)).insert(goodPointsFilePath.length() - 4, "_good");
    std::string wrongPointsFilePath = initPointsFileName;
    wrongPointsFilePath = (wrongPointsFilePath.insert(0, DIR_PATH)).insert(wrongPointsFilePath.length() - 4, "_wrong");
    std::string initPointsFilePath = initPointsFileName.insert(0, DIR_PATH);

    std::ifstream pointsFile(initPointsFilePath);
    std::fstream goodPointsFile;
    std::fstream wrongPointsFile;
    goodPointsFile.open(goodPointsFilePath, std::ios::out);
    wrongPointsFile.open(wrongPointsFilePath, std::ios::out);

    float x, y, z;

    if (goodPointsFile.is_open() && wrongPointsFile.is_open())
    {
        auto start = std::chrono::steady_clock::now();

        while (pointsFile >> x >> y >> z)
        {
            Point point{x, y, z};
            std::cout << "X: " << x << "Y: " << y << "Z: " << z << std::endl;

            if (isPointAtTheSameSideFromPlanes(point, planes))
            {
                goodPointsFile << point.x << " " << point.y << " " << point.z << std::endl;
            }
            else
            {
                wrongPointsFile << point.x << " " << point.y << " " << point.z << std::endl;
            }
        }

        auto end = std::chrono::steady_clock::now();
        auto diff = end - start;
        std::cout << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;

        goodPointsFile.close();
        wrongPointsFile.close();
    }
}