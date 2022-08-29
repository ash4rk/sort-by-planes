#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "point.hpp"
#include "plane.hpp"
#include "operations.hpp"

#define DIR_PATH "../../resources/"

int main()
{
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

        goodPointsFile.close();
        wrongPointsFile.close();
    }
    std::cout << "The end of program." << std::endl;
    return 0;
}