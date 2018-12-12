//
// Created by hugon on 2018-12-08.
//

#include <sstream>
#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Polygon.h"

bool InputErrorHandling(const std::string &);

Shape *createShape(const int &digitCount, const std::string &line);

Point CreatePoint(const std::string &);

Line CreateLine(const std::string &);

Triangle CreateTriangle(const std::string &);

Polygon CreatePolygon(const std::string &, int);
