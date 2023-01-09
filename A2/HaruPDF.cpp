#include "HaruPDF.h"

/*
    Charly Bueno
    CS-3505
    01/31/2022
*/

HaruPDF::HaruPDF(char filename[]){

    // argv are the command line arguments
    // argv[0] is the name of the executable program
    // This makes an output pdf named after the program's name
    strcpy (fname, filename);
    strcat (fname, ".pdf");

    //this segment of code takes a character pointer and assigns it to a character array
    //then we appned the pdf extension

    pdf = HPDF_New (NULL, NULL);
    /* add a new page object. */
    page = HPDF_AddPage (pdf);
    HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
    //  print_grid  (pdf, page);
   //font = HPDF_GetFont (pdf, "Helvetica", NULL);
    HPDF_Page_SetTextLeading (page, 20);
    HPDF_Page_SetGrayStroke (page, 0);
     // Their example sets font twice. Probably some kind of mistake. Fix it or do what they do.
    font = HPDF_GetFont (pdf, "Courier-Bold", NULL);
    HPDF_Page_SetFontAndSize (page, font, 20);
    HPDF_Page_BeginText (page);
}


/**
 * this method places a character on the pdf page at a given location
 * 
 * @param l 
 * @param letterAngle 
 * @param x 
 * @param y 
 */
void HaruPDF::placeLetter(char l, float letterAngle, float x, float y){
    
    HPDF_Page_SetTextMatrix(page, cos(letterAngle), sin(letterAngle), -sin(letterAngle), cos(letterAngle), x, y);
    char buf[2];
    buf[0] = l;
    buf[1] = 0;

    HPDF_Page_ShowText (page, buf);

}

/**
 * this ends the text being written to the page
 * 
 */
void HaruPDF::endText(){
    HPDF_Page_EndText(page);
}

/**
 * this method save the pdf with a given file name
 * 
 */
void HaruPDF::savePDF(){
/* save the document to a file */
    HPDF_SaveToFile (pdf, fname);
}

/**
 * this method closed the pdf
 * 
 */
void HaruPDF::closePDF(){
    /* clean up */
    HPDF_Free (pdf);
}

/**
 * this method handles all the saving and closing for the user.
 * 
 */
void HaruPDF::saveAndClose(){
    endText();
    savePDF();
    closePDF();
}