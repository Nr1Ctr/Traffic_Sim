/*****************************************
** File: IntersectionFlowRate.cpp
** Project: CMSC 341 Project 1, Fall 2015
** Author: Justin French
** Date: 9/17/15
** Section: 05
** E-mail: jfrench2@umbc.edu
**
** This file contains the IntersectionFlowRate class implementation for Project 1.

** This program controls the flow rate for the traffic light.
**
**
***********************************************/

#include "IntersectionFlowRate.h"

void IntersectionFlowRate::set_m_flowRateMotorcyle(int index, int cycle)
	{ m_flowRateMotorcyle[index] = cycle; }

int IntersectionFlowRate::get_m_flowRateMotorcyle(int index)
	{ return m_flowRateMotorcyle[index]; }

void IntersectionFlowRate::set_m_flowRateCar(int index, int car)
	{ m_flowRateCar[index] = car; }

int IntersectionFlowRate::get_m_flowRateCar(int index)
	{ return m_flowRateCar[index]; }

void IntersectionFlowRate::set_m_flowRateTruck(int index, int truck)
	{ m_flowRateTruck[index] = truck; }

int IntersectionFlowRate::get_m_flowRateTruck(int index)
	{ return m_flowRateTruck[index]; }
