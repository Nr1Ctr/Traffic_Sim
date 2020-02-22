/*****************************************
** File: IntersectionFlowRate.h
** Project: CMSC 341 Project 1, Fall 2015
** Author: Justin French
** Date: 9/17/15
** Section: 05
** E-mail: jfrench2@umbc.edu
**
** This file contains the IntersectionFlowRate class definition for Project 1.

** This program controls the flow rate for the traffic light.
**
**
***********************************************/

#ifndef INTERSECTIONFLOWRATE_H
#define INTERSECTIONFLOWRATE_H

const int ARRAYSIZE = 4;

class IntersectionFlowRate
{


public:
	void set_m_flowRateMotorcyle(int, int);
	int get_m_flowRateMotorcyle(int);
	void set_m_flowRateCar(int, int);
	int get_m_flowRateCar(int);
	void set_m_flowRateTruck(int, int);
	int get_m_flowRateTruck(int);

private:
	
	int m_flowRateMotorcyle[ARRAYSIZE];
	int m_flowRateCar[ARRAYSIZE];
	int m_flowRateTruck[ARRAYSIZE];
};

#endif
