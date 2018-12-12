//
// Created by hugon on 03/12/2018.
//

#include "Line.h"

CenterPoint Line::position() {
    double centerX = (a.X + b.X) / 2;
    double centerY = (a.Y + b.Y) / 2;

    CenterPoint lneCenter(centerX, centerY);
    return lneCenter;
}

double Line::distance(Shape *s) {
    CenterPoint sCenter = s->position();    //Center of input Shape
    CenterPoint lneCenter = position();     //Center of current Line

    double distance = sqrt(pow(lneCenter.X - sCenter.X, 2) + pow(lneCenter.Y - sCenter.Y, 2));
    return distance;
}

Line& Line::operator=(const Line &a) {
    this->a.X = a.a.X;
    this->a.Y = a.a.Y;
    this->b.X = a.b.X;
    this->b.Y = a.b.Y;

    return *this;
}

std::ostream &Line::operator<<(std::ostream &os) {
    os << type << std::endl;
    os << "Vertices:" << std::endl;
    os << " (" << a.X << ", " << a.Y << ") " << std::endl;
    os << " (" << b.X << ", " << b.Y << ") " << std::endl;

    return os;
}