#include <vector>
#include <fstream>
#include "point.hpp"
#include "plane.hpp"
#include "operations.hpp"

const std::vector<Plane> getPlanesFromFile(const std::string& fileName)
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

const bool isPointOnThePositiveSide(const Point& point, const Plane& plane)
{
    return dotProduct(point, plane) > 0;
}

const float dotProduct(const Point& point, const Plane& plane)
{
    return point.x * plane.a + point.y * plane.b + point.z * plane.c + plane.d;
}

const bool isPointAtTheSameSideFromPlanes(const Point& point, const std::vector<Plane>& planes)
{
    for (auto const &plane: planes)
    {
        if (!isPointOnThePositiveSide(point, plane))
        {
            return false;
        }
    }
    return true;
}