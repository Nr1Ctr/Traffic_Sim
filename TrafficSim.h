/*****************************************
** File: TrafficSim.h
** Project: CMSC 341 Project 1, Fall 2015
** Author: Justin French
** Date: 9/17/15
** Section: 05
** E-mail: jfrench2@umbc.edu
**
** This file contains the TrafficSim class definition for Project 1.

** This program ....
**
**
***********************************************/

#ifndef TRAFFICSIM_H
#define TRAFFICSIM_H

#include <queue>
#include <iostream>
#include "Vehicle.h"
#include "LinkedList.h"
#include "IntersectionFlowRate.h"
using namespace std;

class TrafficSim
{
public:
	TrafficSim();
	TrafficSim(const char*);
	void DoRun();	

private:
	queue<Vehicle> m_traffic[4];
	LinkedList m_results;
	IntersectionFlowRate m_flowRate;
	int m_clock;
	static const int N = 0;
	static const int S = 1;
	static const int E = 2;
	static const int W = 3;
	static const int CYCLE = 1;
	static const int CAR = 2;
	static const int TRUCK = 3;
	static const int MAX_CLEAR_TIME = 6;


	void ReadFromFile(const char*);
	void PrintBoard();
	void PrintFlowRate();
	void AddVehicle(int, Vehicle);
	void DoOneRun();
	int charToInt(char);
	char intToChar(int);
	void addVehicles();
	void printResults();
};



#endif
