const std::vector<Plane> getPlanesFromFile(const std::string& url);

const std::string selectWrongPoints(const std::string& initFileName, const std::vector<Plane>& planes);

const bool isPointAtTheSameSideFromPlanes(const Point& point, const std::vector<Plane>& planes);

const bool isPointOnThePositiveSide(const Point& point, const Plane& plane);

const float dotProduct(const Point& point, const Plane& plane);