#include "Spiral.h"
#include "HaruPDF.h"

/*
    Charly Bueno
    CS-3505
    01/31/2022
*/

/**
 * this is the main file that brings together the harupdf interface and the spiral
 * format. this takes in arguments from the command line and creates a pdf file
 * out of the text passed in by the second argument.
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char **argv){

    char fname[256];

    strcpy (fname, argv[0]);
    
    if(argv[1]){
    char* TXT = argv[1];

    HaruPDF pdf(fname);
    Spiral point(210, 300, 270, 60);

    for (unsigned int i = 0; i < strlen (TXT); i++) {
        
        pdf.placeLetter(TXT[i], point.getLetterAngle(), point.getTextX(), point.getTextY());
        ++point;
    }

    pdf.saveAndClose();
    }
    
    return 0;
}