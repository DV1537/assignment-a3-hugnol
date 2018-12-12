//
// Created by hugon on 03/12/2018.
//

#ifndef A2FINAL_SHAPE_H
#define A2FINAL_SHAPE_H

#include "Center.h"
#include <string>
#include <cmath>
#include <iostream>
enum ShapeType {sShape = 0, sPoint = 1, sLine = 2, sTriangle = 3, sPolygon = 4};

class Shape {
public:
    virtual ShapeType getType() = 0;

    virtual double area() = 0;

    virtual double circumference() = 0;

    virtual CenterPoint position() = 0;

    virtual bool isConvex() = 0;

    virtual double distance(Shape *) = 0;

};


#endif //A2FINAL_SHAPE_H
