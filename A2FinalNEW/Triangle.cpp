//
// Created by hugon on 03/12/2018.
//

#include "Triangle.h"

double Triangle::area() {   //Heron's Formula
    double lengthAB, lengthBC, lengthCA;
    lengthAB = a.distance(&b);
    lengthBC = b.distance(&c);
    lengthCA = c.distance(&a);

    double s = (lengthAB + lengthBC + lengthCA) / 2;
    double area = sqrt(s * (s - lengthAB) * (s - lengthBC) * (s - lengthCA));
    return area;
}

double Triangle::circumference() {
    double lengthAB, lengthBC, lengthCA;
    lengthAB = a.distance(&b);
    lengthBC = b.distance(&c);
    lengthCA = c.distance(&a);

    double cF = lengthAB + lengthBC + lengthCA;    //c = circumference
    return cF;
}

CenterPoint Triangle::position() {          //Triangle centroid(O) equation
    double Ox, Oy;
    Ox = (a.X + b.X + c.X) / 3;
    Oy = (a.Y + b.Y + c.Y) / 3;
    CenterPoint triCenter = CenterPoint(Ox, Oy);
    return triCenter;
}

double Triangle::distance(Shape *s) {
    CenterPoint triCenter = position();
    CenterPoint sCenter = s->position();

    double distance = sqrt(pow(triCenter.X - sCenter.X, 2) + pow(triCenter.Y - sCenter.Y, 2));
    return distance;
}

Triangle &Triangle::operator=(const Triangle &t) {
    a.X = t.a.X;
    a.Y = t.a.Y;
    b.X = t.b.X;
    b.Y = t.b.Y;
    c.X = t.c.X;
    c.Y = t.c.Y;

    return *this;
}

std::ostream &Triangle::operator<<(std::ostream &os) {
    os << type << std::endl;
    os << " (" << a.X << ", " << a.Y << ") " << std::endl;
    os << " (" << b.X << ", " << b.Y << ") " << std::endl;
    os << " (" << c.X << ", " << c.Y << ") " << std::endl;

    return os;
}

