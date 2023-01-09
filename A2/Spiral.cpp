#include "Spiral.h"

/*
    Charly Bueno
    CS-3505
    01/31/2022
*/

/**
 * this is the constructor to the spiral class. this class generates
 * points in which the letters should be placed on a pdf
 * 
 * @param centerX 
 * @param centerY 
 * @param startAngle 
 * @param startRadius 
 */
Spiral::Spiral(double centerX, double centerY, double startAngle, double startRadius) : 
x(centerX), y(centerY), angle(startAngle), radius(startRadius){
    calculate();
}

/**
 * this method calculates any changes to the spiral points.
 * 
 */
void Spiral::calculate(){

    double spiralPos;

    /* text along a circle */
    
        // letterAngle determines the angle of the letter on the page. spiralPos is how far
        // around the circle you are. Notice that they are perpendicular and
        // thus not independent.
        //
        // Pay careful attention to what wants radians and what is degrees
        // between haru and spiral and math functions.
        letterAngle = (-angle - 90) / 180 * M_PI;
        spiralPos = -angle / 180 * M_PI;

        // The position of the character depends on the center point
        // plus the angle and the radius.
        varX = x + cos(spiralPos) * radius;
        varY = y + sin(spiralPos) * radius;
}

/**
 * this method is a pre fix operator overload
 * changes the radius and angle my fixed amount
 * and returns the address of the object
 * 
 * @return Spiral& 
 */
Spiral& Spiral::operator++(){

    //work to increment
    radius += 1;
    angle += (1/radius) + 10;
    calculate();

    return *this;
}

/**
 * this is a post fix increment, this passes a copy of the values of the object
 * and returns a new object with the given increment.
 * 
 * @param x 
 * @return Spiral 
 */
Spiral Spiral::operator++(int x){
    Spiral temp(*this);
    //work to increment
    ++*this;
    return temp;
}

/**
 * returns x point
 * 
 * @return double 
 */
double Spiral::getTextX(){
    return varX;
}

/**
 * returns y point
 * 
 * @return double 
 */
double Spiral::getTextY(){
    return varY;
}

/**
 * returns the letter angle
 * 
 * @return double 
 */
double Spiral::getLetterAngle(){
    return letterAngle;
}

