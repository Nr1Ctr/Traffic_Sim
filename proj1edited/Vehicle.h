/*****************************************
** File: Vehicle.h
** Project: CMSC 341 Project 1, Fall 2015
** Author: Justin French
** Date: 9/17/15
** Section: 05
** E-mail: jfrench2@umbc.edu
**
** This file contains the Vehicle class definition for Project 1.

** This program simulates a vehicle traveling to, and through,
** a traffic light.
**
**
***********************************************/

#ifndef VEHICLE_H
#define VEHICLE_H

#include "Clear.h"

class Vehicle
{
	public:
		Vehicle();
		Vehicle(int, int);
		void set_m_type(int);
		int get_m_type();
		void setTimeEntered(int);
		int getTimeEntered();
		void set_m_clearTime(int);
		int get_m_clearTime();
		void setTimeOut(int);
		int getTimeOut();
		bool getOutFlag();
		void setOutFlag(bool);
		
	private:
		int m_type;
		int timeEntered;
 		int m_clearTime;
		int timeOut;
		bool outFlag;
};



#endif
