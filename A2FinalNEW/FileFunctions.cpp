//
// Created by hugon on 2018-12-08.
//

#include "FileFunctions.h"

bool InputErrorHandling(const std::string &line) {

    double digit;
    int digitCount(0);
    bool inputStatus(true);

    std::stringstream ss(line);
    while (ss >> digit) {
        digitCount++;
        if (ss.fail()) { //If stringstream fails to read into double data type.
            inputStatus = false;
            return inputStatus;
        }
    }
    if (digitCount % 2 != 0) {
        inputStatus = false;
    }
    return inputStatus;
}

Shape *createShape(const int &digitCount, const std::string &line) {
    Shape *shape = nullptr;
    switch(digitCount/2) {
        case 1: {
            std::cout << "Creating Point." << std::endl;
            shape = new Point(CreatePoint(line));
            break;
        }
        case 2: {
            std::cout << "Creating Line." << std::endl;
            shape = new Line(CreateLine(line));
            break;
        }
        case 3: {
            std::cout << "Creating Triangle." << std::endl;
            shape = new Triangle(CreateTriangle(line));
            break;
        }
        default: {
            std::cout << "Creating Polygon." << std::endl;
            shape = new Polygon(CreatePolygon(line, digitCount));
            break;
        }
    }
    return shape;
}

Point CreatePoint(const std::string &points) {
    std::stringstream ss(points);
    const int pointDigits(2);
    double xY[pointDigits];
    for (int i = 0; i < pointDigits; i++) {
        ss >> xY[i];
    }
    Point point(xY[0], xY[1]);

    return point;
}

Line CreateLine(const std::string &points) {

    std::stringstream ss(points);
    const int lineDigits(4);
    double xY[lineDigits];
    for (int i = 0; i < lineDigits; i++) {
        ss >> xY[i];
    }
    Point a(xY[0], xY[1]);
    Point b(xY[2], xY[3]);
    Line line(a, b);

    return line;
}

Triangle CreateTriangle(const std::string &points) {
    std::stringstream ss(points);
    const int triangleDigits(6);
    double xY[triangleDigits];
    for (int i = 0; i < triangleDigits; i++) {
        ss >> xY[i];
    }
    Point a(xY[0], xY[1]);
    Point b(xY[2], xY[3]);
    Point c(xY[4], xY[5]);
    Triangle triangle(a, b, c);

    return triangle;
}

Polygon CreatePolygon(const std::string &points, int digitCount) {
    std::stringstream ss(points);
    std::cout << digitCount << std::endl;
    auto *polygonPoints = new Point[digitCount/2];
    for ( int i = 0; i < digitCount/2; i++) {
        ss >> polygonPoints[i].X;
        ss >> polygonPoints[i].Y;
        std::cout << "("<<polygonPoints[i].X << ", " << polygonPoints[i].Y << ")" << std::endl;
    }

    Polygon polygon(polygonPoints, digitCount/2);
    delete [] polygonPoints;
    return polygon;
}
