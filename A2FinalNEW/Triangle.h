//
// Created by hugon on 03/12/2018.
//

#ifndef A2FINAL_TRIANGLE_H
#define A2FINAL_TRIANGLE_H

#include "Point.h"

class Triangle : public Shape {
public:
    const ShapeType type = sTriangle;
    Point a;
    Point b;
    Point c;

    Triangle() : a(0, 0), b(0, 1), c(1, 0) {};

    Triangle(Point &A, Point &B, Point &C) : a(A), b(B), c(C) {};

    ShapeType getType() override { return type; }

    double area() override;

    double circumference() override;

    CenterPoint position() override;

    bool isConvex() override { return true; }

    double distance(Shape *) override;

    Triangle& operator=(const Triangle &t);
    std::ostream &operator<<(std::ostream &os);
};


#endif //A2FINAL_TRIANGLE_H
