/*
    Charly Bueno
    CS-3505
    01/31/2022
*/

#ifndef HARUPDF_H
#define HARUPDF_H

#include "hpdf.h"
#include <string.h>
#include <math.h>
class HaruPDF{

private:
    int argc;
    char **argv;
    HPDF_Doc  pdf;
    HPDF_Page page;
    char fname[256];
    HPDF_Font font;
    unsigned int i;


public:

HaruPDF(char filename[]);

void placeLetter(char l, float letterAngle, float x, float y);

void endText();

void savePDF();

void closePDF();

void saveAndClose();

};

#endif