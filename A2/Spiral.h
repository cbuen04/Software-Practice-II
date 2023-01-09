/*
    Charly Bueno
    CS-3505
    01/31/2022
*/

#ifndef SPIRAL_H
#define SPIRAL_H

#include <math.h>

class Spiral{

private:
    double x;
    double y;
    double varX;
    double varY;
    double angle;
    double letterAngle;
    double spiralPos;
    double radius;

public:

Spiral(double centerX, double centerY, double startAngle, double startRadius);

Spiral& operator++();

Spiral operator++(int x);

void calculate();

double getTextX();

double getTextY();

double getLetterAngle();
};
#endif