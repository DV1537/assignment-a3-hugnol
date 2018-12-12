//
// Created by hugon on 03/12/2018.
//

#ifndef A2FINAL_POINT_H
#define A2FINAL_POINT_H

#include "Shape.h"

class Point : public Shape {
public:
    const ShapeType type = sPoint;
    double X;
    double Y;

    Point() : X(0), Y(0) {};                        //Default Point (Origo)
    Point(double x, double y) : X(x), Y(y) {};                     //Point with default arguments



    ShapeType getType() override { return type; };

    double area() override { return -1; };

    double circumference() override { return 0; };

    CenterPoint position() override;

    bool isConvex() override { return false; };

    double distance(Shape *) override;

    Point &operator=(const Point &p);

    std::ostream &operator<<(std::ostream &os);
};
#endif //A2FINAL_POINT_H
