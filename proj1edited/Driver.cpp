/**************************************************************
 * File:    driver.cpp
 * Project: CMSC 341 - Project 1 - Traffic Light Simulation
 * Author : Justin French
 * Date   : 9/24/15
 * Section: 05
 * E-mail:  jfrench2@umbc.edu
 *
 * Main Program Driver.
 *
 *************************************************************/

#include "TrafficSim.h"

int main(int argc, char *argv[]) {

    //If there is an input file listed
    if (argc > 1) {
        TrafficSim *Sim = new TrafficSim(argv[1]);
        Sim->DoRun();
        delete Sim;
        Sim = NULL;

        //If no input file is specified.
    } else {
        TrafficSim *Sim = new TrafficSim();
        Sim->DoRun();
        delete Sim;
        Sim = NULL;
    }
    
    // endl(cout << clock() / (float)CLOCKS_PER_SEC);
	system("pause");
    return 0;
}
