#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string DIR_PATH = "../../resources/"; // must be const

struct Point
{
    float x;
    float y;
    float z;
};

struct Plane
{
    float x1, y1, z1;
    float x2, y2, z2;
    float x3, y3, z3;

    float a1 = x2 - x1;
    float b1 = y2 - y1;
    float c1 = z2 - z1;
    float a2 = x3 - x1;
    float b2 = y3 - y1;
    float c2 = z3 - z1;
    float a = b1 * c2 - b2 * c1;
    float b = a2 * c1 - a1 * c2;
    float c = a1 * b2 - b1 * a2;
    float d = (-a * x1 - b * y1 - c * z1);
};

std::vector<Plane> getPlanesFromFile(std::string url);

std::string selectWrongPoints(std::string initFileName, std::vector<Plane> planes);

bool isPointAtTheSameSideFromPlanes(Point point, std::vector<Plane> planes);

bool isPointOnThePositiveSide(Point point, Plane plane);

float dotProduct(Point point, Plane plane);

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

std::vector<Plane> getPlanesFromFile(std::string fileName)
{
    std::ifstream initPlanesFile(fileName);
    float x1, y1, z1, x2, y2, z2, x3, y3, z3;
    std::vector<Plane> planes;
    while (initPlanesFile >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3)
    {
        Plane plane{x1, y1, z1, x2, y2, z2, x3, y3, z3};
        planes.push_back(plane);
    }

    return planes;
}

bool isPointOnThePositiveSide(Point point, Plane plane)
{
    return dotProduct(point, plane) > 0;
}

float dotProduct(Point point, Plane plane)
{
    return point.x * plane.a + point.y * plane.b + point.z * plane.c + plane.d;
}

bool isPointAtTheSameSideFromPlanes(Point point, std::vector<Plane> planes)
{
    for (std::vector<Plane>::iterator it = planes.begin(); it != planes.end(); ++it)
    {
        if (!isPointOnThePositiveSide(point, *it))
        {
            return false;
        }
    }
    return true;
}