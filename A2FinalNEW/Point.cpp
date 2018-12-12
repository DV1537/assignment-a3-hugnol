//
// Created by hugon on 03/12/2018.
//

#include "Point.h"

CenterPoint Point::position() {
    CenterPoint pCenter(X, Y);
    return pCenter;
}

double Point::distance(Shape *s) {
    CenterPoint sCenter = s->position();
    double distance = sqrt(
            pow(X - sCenter.X, 2) + pow(Y - sCenter.Y, 2));    //Distance formula sqrt((X2 - X1)^2 + (Y2 - Y1)^2))
    return distance;
}

Point &Point::operator=(const Point &p) {
    auto *q = new Point;
    q->X = p.X;
    q->Y = p.Y;
    X = q->X;
    Y = q->Y;

    delete q;
    return *this;
}

std::ostream &Point::operator<<(std::ostream &os) {
    os << type << std::endl;
    os << "Vertices: (" << X << ", " << Y << ") " << std::endl;
    return os;
}




