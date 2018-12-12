//
// Created by hugon on 03/12/2018.
//

#ifndef A2FINAL_POLYGON_H
#define A2FINAL_POLYGON_H

#include "Point.h"

class Polygon : public Shape {
private:
    int pointsAmount;
    static const int wrapAround = 2;       //Points added at end of array to enable wrap around.
public:
    const ShapeType type = sPolygon;
    Point *points;

    Polygon();

    Polygon(Point [], int pA);

    ~Polygon() {
        delete[] points;
        std::cout << "Deleting Points.." << std::endl;
    };

    ShapeType getType() override { return type; }

    double area() override;

    double circumference() override;

    CenterPoint position() override;

    bool isConvex() override;

    double distance(Shape *) override;

    Polygon &operator=(const Polygon &p);

    Polygon &operator+(const Point &a);

    std::ostream &operator<<(std::ostream &os);
};


#endif //A2FINAL_POLYGON_H
