
#include <iostream>
#include <fstream>
#include <sstream>

#include "FileFunctions.h"
#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Polygon.h"


int main(int argc, const char *argv[]) {
    std::ifstream fileInput;
    fileInput.open("numbers.txt");

    if (fileInput.is_open()) {

        std::string line;
        int amountOfShapes(0);
        bool inputStatus(false);


        //Error checking. Counts amount of shapes.
        while (std::getline(fileInput, line)) {
            inputStatus = InputErrorHandling(line);
            amountOfShapes++;
        }
        fileInput.clear();
        fileInput.seekg(0, std::ios::beg);


        if (inputStatus) {
            int digits[amountOfShapes], digitIndex(0), digit;

            //Count digits for each shape and creates the shape.
            while (std::getline(fileInput, line)) {
                std::stringstream ss(line);
                digits[digitIndex] = 0;
                while (ss >> digit) {
                    digits[digitIndex]++;
                }
                Shape *shapes[amountOfShapes];
                shapes[digitIndex] = createShape(digits[digitIndex], line);
                std::cout << shapes[digitIndex]->area() << std::endl;

                if(digitIndex >= 1 && shapes[0]->getType() == sPolygon)
                {
                    auto *polygon = dynamic_cast<Polygon*>(shapes[0]);

                    for(int i = 0; i < amountOfShapes; i++) {
                        if(shapes[i]->getType()==sPoint) {
                            auto *point = dynamic_cast<Point*>(shapes[i]);
                            *polygon + *point;
                        }
                    }
                    std::cout << polygon->area() << std::endl;
                }
                digitIndex++;
                ss.clear();
            }
        } else {
            std::cout << "Error. Wrong File Input." << std::endl;
        }
    } else {
        std::cout << "Error. Unable to open file." <<
                  std::endl;
    }
    return 0;
}


