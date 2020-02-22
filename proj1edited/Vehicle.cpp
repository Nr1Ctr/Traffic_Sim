/*****************************************
** File: Vehicle.cpp
** Project: CMSC 341 Project 1, Fall 2015
** Author: Justin French
** Date: 9/17/15
** Section: 05
** E-mail: jfrench2@umbc.edu
**
** This file contains the Vehicle class implementation for Project 1.

** This program simulates a vehicle traveling to, and through, 
** a traffic light.
**
**
***********************************************/

#include "Clear.h"
#include "Vehicle.h"
#include <stdio.h>

Vehicle::Vehicle()
{
	m_type = 0;
	timeEntered = 0;
	outFlag = false;

	if (m_type == 1)
	{
		m_clearTime = 1;
	}
	else if (m_type == 2)
	{
		m_clearTime = 1;
	}
	else if (m_type == 3)
	{
		m_clearTime = 2;
	}

	timeOut = 0;
}
Vehicle::Vehicle(int x, int y)
{
	m_type = x;
	timeEntered = y;
	outFlag = false;

	if (m_type == 1)
	{
		m_clearTime = 1;
	}
	else if (m_type == 2)
	{
		m_clearTime = 2;
	}
	else if (m_type == 3)
	{
		m_clearTime = 4;
	}
	timeOut = 0;
}
void Vehicle::set_m_type(int type)			
{ m_type = type; };

int Vehicle::get_m_type()					
{ return m_type; };

void Vehicle::setTimeEntered(int time1)		
{ timeEntered = time1; };

int Vehicle::getTimeEntered()				
{ return timeEntered; };

void Vehicle::set_m_clearTime(int time2)	
{ m_clearTime = time2; };

int Vehicle::get_m_clearTime()				
{ return m_clearTime; };

void Vehicle::setTimeOut(int time3)
{ timeOut = time3; }

int Vehicle::getTimeOut()
{ return timeOut; }

bool Vehicle::getOutFlag()
{ return outFlag; }

void Vehicle::setOutFlag(bool x)
{ outFlag = x; }
