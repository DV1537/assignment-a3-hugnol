//
// Created by hugon on 03/12/2018.
//

#ifndef A2FINAL_LINE_H
#define A2FINAL_LINE_H

#include "Point.h"

class Line : public Shape {
public:
    const ShapeType type = sLine;
    Point a;
    Point b;

    Line() {
        a.X = 0;
        a.Y = 0;
        b.X = 1;
        b.Y = 1;
    };

    Line(Point &A, Point &B) : a(A), b(B) {};

    ShapeType getType() override { return type; };

    double area() override {return -1; };

    double circumference() override {return 0; };

    CenterPoint position() override;

    bool isConvex() override { return false; };

    double distance(Shape *) override;

    Line &operator=(const Line &);
    std::ostream &operator<<(std::ostream &);
};


#endif //A2FINAL_LINE_H
