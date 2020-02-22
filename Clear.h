/**************************************************************
* File:    Clear.h
* Project: CMSC 341 - Project 1 - Traffic Light Simulation
* Author : Justin French
* Date   : 9/24/15
* Section: 05
* E-mail:  jfrench2@umbc.edu
*
* Main Program Driver.
*
*************************************************************/

#ifndef CLEAR_H
#define CLEAR_H

#ifdef Clear1
const int CycleClearTime = 1;
const int CarClearTime = 1;
const int TruckClearTime = 2;
#endif

#ifdef Clear2
const int CycleClearTime = 1;
const int CarClearTime = 2;
const int TruckClearTime = 4;
#endif

#ifdef Clear3
const int CycleClearTime = 2;
const int CarClearTime = 4;
const int TruckClearTime = 6;
#endif


#endif
