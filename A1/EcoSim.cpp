#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
using std::cin;


/**
 * This program simulates population growth between predators and prey
 * and graphs 500 iterations of the function with a given population.
 * 
 * @author Charly Bueno
 * @version 1/20/2022
 */

//headers - didn't add a header file as I wasn't sure if I was allowed to implement it.
void RunSimulation(int iterations, double numOfRabbits, double numOfFoxes);
void updatePopulations(double g, double p, double c, double m, double K, 
double& numRabbits, double& numFoxes);
void plotCharacter(int num, char character);
void plotPopulations(double rabbits, double foxes, double scaleFactor);
void incrementCounter(int* num);

/**
 * A main function that that asks the user for initial rabbit and fox populations, 
 * stored as doubles to smooth the simulation, then calls runSimulation with a value of 
 * 500 iterations and the initial rabbit and fox populations. If the user enters anything that 
 * cannot be converted to a double for an initial population, give a warning message and terminate 
 * the program. Use cin as the mechanism for capturing input.
 * 
 * @return int 
 */

int main(){
    int iterations;
    double rabbits;
    double foxes;

    cout << "**Ecology Simulator**" << endl;

    cout << "Enter number of rabbits" << endl;
    cin >> rabbits;

    cout << "Enter number of foxes" << endl;
    cin >> foxes;

    if(cin.good()){
        if(rabbits < 1 || foxes < 1){
            plotPopulations(rabbits, foxes, 0.1);
        }
        else{
            RunSimulation(500, rabbits, foxes);
        }
    }
    else{
        cout << "error please enter integer values for both rabbits and foxes" << endl;
    }
}

/**
 * A runSimulation function that has parameters for iterations, 
 * number of rabbits, and number of foxes in that order. Rabbits and foxes 
 * This function should set the parameters needed for the update equation 
 * and run the simulation for iterations steps or until the predator or prey population goes 
 * below 1. If the populations don't go below 1, a call to runSimulation with 100 
 * iterations should produce 101 lines - the initial population line and then 100 updated values. 
 * If the initial populations are below one, it should still print the initial populations 
 * 
 * @param iterations - number of iterations
 * @param numOfRabbits - population of rabbits
 * @param numOfFoxes - population of foxes
 */
void RunSimulation(int iterations, double numOfRabbits, double numOfFoxes){
    
    /*
    rabbitGrowth (g): 0.2
    predationRate (p): 0.0022
    foxPreyConversion (c): 0.6
    foxMortalityRate (m): 0.2
    carryCapacity (K): 1000.0
    */
    
    double g = 0.2;
    double p = 0.0022;
    double c = 0.6;
    double m = 0.2;
    double k = 1000.0;
    // creates a pointer variable for the iteration counter
    int i = 0;
    int* ptr = &i;

    // starts the simulator for the given number of iterations
    while(i <= iterations){
        //stops simulation if population drops below 1
        if(numOfFoxes < 1 || numOfRabbits < 1){
            break;
        }
        else{
            plotPopulations(numOfRabbits,numOfFoxes, 0.1);
            updatePopulations(g,p,c,m,k, numOfRabbits, numOfFoxes);
        }
        cout << endl;
        incrementCounter(ptr);
    }


}
/*
    this function takes in the variables needed to simulate the change
    in populations between the foxes and rabbits
*/

/**
 * this function takes in the variables needed to simulate the change
 * in populations between the foxes and rabbits
 * @param g - rabbitGrowth
 * @param p - predationRate
 * @param c - foxPreyConversion
 * @param m - foxMortalityRate
 * @param K - carryCapacity
 * @param numRabbits - population of rabbits
 * @param numFoxes - population of foxes
 */

void updatePopulations(double g, double p, double c, double m, double K, 
double& numRabbits, double& numFoxes){

    /*
        The change in populations (deltaRabbit and deltaFoxes) for a given population of 
        rabbits and foxes numRabbits (R) and numFoxes (F) is then:

        deltaRabbit = gR(1-R/K) - pRF
        deltaFoxes = cpRF - mF
    */


    double deltaRabbits, deltaFoxes;  

    //equations to be modeling
    deltaRabbits = (g*numRabbits)*(1.0 - (numRabbits/K)) - (p*numRabbits*numFoxes);
    deltaFoxes = (c*p*numRabbits*numFoxes) - (m * numFoxes);
    
    //updating populations
    numRabbits += deltaRabbits;
    numFoxes += deltaFoxes;

}


/**
 * helper method takes in an int number and a character and sends to std::cout 
 * number spaces followed by the character. If the number parameter is less than 1, 
 * just output the character.
 * 
 * @param population - population of animal
 * @param character - letter identifier of animal
 */
void plotCharacter(int population, char character){

    for(int i = 0; i < population; i++){
        cout <<" ";
    }
    cout << character;
}

/**
 * charting function that has parameters for the number of rabbits, 
 * the number of foxes, and a fractional scale factor in that order. 
 * Using the plotCharacter function as a helper, it should draw a row of 
 * a text chart with an 'F' for foxes and 'r' for rabbits and '*' if the drawing 
 * of each would overlap.
 * 
 * @param rabbits - population of rabbits
 * @param foxes - population of foxes
 * @param scaleFactor - fractional factor for graphing
 */
void plotPopulations(double rabbits, double foxes, double scaleFactor){

    /*
        calls plot char
        find spaces for r & f
        scale with scale factor
        print lower first and other after
    */
        int difference;
        int scaledRabbit = floor(rabbits * scaleFactor);
        int scaledFox = floor(foxes * scaleFactor);

        if(scaledRabbit < scaledFox){
            // print rabbits
            difference = scaledFox - scaledRabbit - 1;
            plotCharacter(scaledRabbit, 'r');
            plotCharacter(difference, 'F');

        }
        else if(scaledRabbit > scaledFox){
            //print foxes
            difference = scaledRabbit - scaledFox - 1;
            plotCharacter(scaledFox, 'F');
            plotCharacter(difference, 'r');
        }
        else{
            // print star
            plotCharacter(scaledRabbit, '*');
        }


}

/**
 * A helper function incrementCounter that returns void and has a pointer to 
 * an integer parameter. The function should add 1 to the value pointed to by the pointer.
 * 
 * @param num - pointer to value to be incremented
 */
void incrementCounter(int* num){
    *num += 1;
}