//
// Created by hugon on 03/12/2018.
//

#include <iostream>
#include "Polygon.h"

Polygon::Polygon(Point *ps, int pA) : pointsAmount(pA) {
    points = new Point[pointsAmount + wrapAround];

    for (int index = 0; index < pointsAmount + 2; index++) {
        if (index < pointsAmount) {
            points[index] = ps[index];
            //std::cout << "("<<points[index].X << ", " << points[index].Y << ")" << std::endl;

        } else if (index >= pointsAmount) {
            if (index == pointsAmount) {
                points[index] = points[0];
               // std::cout << "("<<points[index].X << ", " << points[index].Y << ")" << std::endl;

            } else if (index == pointsAmount + 1) {
                points[index] = points[1];
                //std::cout << "("<<points[index].X << ", " << points[index].Y << ")" << std::endl;

            }
        }
    }
}

Polygon::Polygon() {
    pointsAmount = 4;
    points = new Point[pointsAmount + wrapAround];
    for (int i = 0; i < pointsAmount; i++) {
        points[i].X = i;
        points[i].Y = i;
    }
    points[pointsAmount] = points[0];
    points[pointsAmount + 1] = points[1];
}

double Polygon::area() {
    double area(-1.0);
    if (this->isConvex()) {
        area = 0.0;
        for (int index = 0; index < pointsAmount; index++) {
            area += (points[index].X * points[index + 1].Y - points[index].Y * points[index + 1].X) / 2.0;
        }
        if (area < 0) { //The absolute..
            area *= -1;
        }
    }
    return area;
}

double
Polygon::circumference() {       //Length accepts the inputs from calculations, acting like a buffer for perimeter.
    double currentLength(0), perimeter(0);
    for (int index = 0; index < pointsAmount; index++) {
        currentLength = sqrt(
                pow(points[index].X - points[index + 1].X, 2) + pow(points[index].Y - points[index + 1].Y, 2));
        perimeter += currentLength;
    }
    return perimeter;
}

CenterPoint Polygon::position() {
    CenterPoint Centroid(0.0, 0.0);
    double a, signedArea(0.0), x0, y0, x1, y1;
    int i(0);
    for (i = 0; i < pointsAmount - 1; ++i) {
        x0 = points[i].X;
        y0 = points[i].Y;
        x1 = points[i + 1].X;
        y1 = points[i + 1].Y;

        a = x0 * y1 - x1 * y0;
        signedArea += a;
        Centroid.X += (x0 + x1) * a;
        Centroid.Y += (y0 + y1) * a;
    }
    x0 = points[i].X;
    y0 = points[i].Y;
    x1 = points[0].X;
    y1 = points[0].Y;

    a = x0 * y1 - x1 * y0;
    signedArea = a;
    Centroid.X += (x0 + x1) * a;
    Centroid.Y += (y0 + y1) * a;

    signedArea *= 0.5;
    Centroid.X /= (6.0 * signedArea);
    Centroid.Y /= (6.0 * signedArea);

    return Centroid;
}

bool Polygon::isConvex() {
    bool isConvex = false;
    double crossProdX1(0), crossProdX2(0), crossProdY1(0), crossProdY2(0), zProd(0), checkCounterT(0), X(0), K(0);


    for (int i = 0; i < pointsAmount; i++) {

        crossProdX1 = points[i].X - points[i + 1].X;
        crossProdY1 = points[i].Y - points[i + 1].Y;
        crossProdX2 = points[i + 2].X - points[i + 1].X;
        crossProdY2 = points[i + 2].Y - points[i + 1].Y;

        zProd = crossProdX1 * crossProdY2 - crossProdY1 * crossProdX2;
        if (zProd >= 0) {
            checkCounterT++;
        } else {
            checkCounterT--;
        }
    }

    if (fabs(checkCounterT) == pointsAmount) {
        isConvex = true;
    };

    return isConvex;
}

double Polygon::distance(Shape *s) {
    double reach;

    CenterPoint polyCenter = position();
    CenterPoint sCenter = s->position();
    reach = sqrt(pow(polyCenter.X - sCenter.X, 2) + pow(polyCenter.Y - sCenter.Y, 2));

    return reach;
}

Polygon &Polygon::operator=(const Polygon &p) {
    if (this != &p) {
        if (pointsAmount > 0) {
            delete[] points;
        }
        pointsAmount = p.pointsAmount;
        points = new Point[pointsAmount + wrapAround];
        for (int i = 0; i < pointsAmount + wrapAround; i++) {
            points[i] = p.points[i];

        }
    }
    return *this;
}

Polygon &Polygon::operator+(const Point &a) {
    pointsAmount += 1;
    auto *tempPoints = new Point[pointsAmount];
    for (int i = 0; i < pointsAmount; i++) {
        tempPoints[i] = points[i];
    }
    delete[] points;
    tempPoints[pointsAmount - 1] = a;
    std::cout << "Added a to temp: (" << a.X << ", " << a.Y << "). " << std::endl;
    points = new Point[pointsAmount + wrapAround];
    for (int i = 0; i < pointsAmount; i++) {
        points[i] = tempPoints[i];
        std::cout << "(" << points[i].X << ", " << points[i].Y << "). " << std::endl;
    }
    for (int i = 0; i < wrapAround; i++) {  //Adding Wraparound
        points[pointsAmount + i] = points[i];
    }
    return *this;
}

std::ostream &Polygon::operator<<(std::ostream &os) {
    os << type << std::endl;
    for (int i = 0; i < pointsAmount; i++) {
        os << " (" << points[i].X << ", " << points[i].Y << ") " << std::endl;
    }
    return os;
}


