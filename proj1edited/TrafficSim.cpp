/*****************************************
** File: TrafficSim.cpp
** Project: CMSC 341 Project 1, Fall 2015
** Author: Justin French
** Date: 9/17/15
** Section: 05
** E-mail: jfrench2@umbc.edu
**
** This file contains the TrafficSim class implementation for Project 1.

** This program ....
**
**
***********************************************/

#include <fstream>
#include "TrafficSim.h"

TrafficSim::TrafficSim()
{
	Vehicle item(CAR, m_clock);
	
	m_traffic[N].push(item);
	m_traffic[N].push(item);
	m_traffic[S].push(item);
	m_traffic[S].push(item);
	m_traffic[E].push(item);
	m_traffic[E].push(item);
	m_traffic[W].push(item);
	m_traffic[W].push(item);
	
	ReadFromFile("input1.txt");

	PrintFlowRate();

	PrintBoard();
}

TrafficSim::TrafficSim(const char* input)
{
	Vehicle item(CAR, m_clock);

	m_traffic[N].push(item);
	m_traffic[N].push(item);
	m_traffic[S].push(item);
	m_traffic[S].push(item);
	m_traffic[E].push(item);
	m_traffic[E].push(item);
	m_traffic[W].push(item);
	m_traffic[W].push(item);

	ReadFromFile(input);

	PrintFlowRate();

	PrintBoard();
}

void TrafficSim::ReadFromFile(const char* input)
{
	char dir1, dir2, dir3, dir4;
	int flowRate1, flowRate2, flowRate3;
	ifstream inputFile;
	inputFile.open(input, ios_base::in);
	if (inputFile.fail())
	{
		cout << "The File was not successfully opened." << endl;
		exit(1);
	}

	inputFile.get(dir1);
	inputFile.ignore(2);
	inputFile >> flowRate1 >> flowRate2 >> flowRate3;
	m_flowRate.set_m_flowRateMotorcyle(charToInt(dir1), flowRate1);
	m_flowRate.set_m_flowRateCar(charToInt(dir1), flowRate2);
	m_flowRate.set_m_flowRateTruck(charToInt(dir1), flowRate3);
	inputFile.ignore(1);
  	
	inputFile.get(dir2);
	inputFile.ignore(2);
	inputFile >> flowRate1 >> flowRate2 >> flowRate3;
	m_flowRate.set_m_flowRateMotorcyle(charToInt(dir2), flowRate1);
	m_flowRate.set_m_flowRateCar(charToInt(dir2), flowRate2);
	m_flowRate.set_m_flowRateTruck(charToInt(dir2), flowRate3);
	inputFile.ignore(1);

	inputFile.get(dir3);
	inputFile.ignore(2);
	inputFile >> flowRate1 >> flowRate2 >> flowRate3;
	m_flowRate.set_m_flowRateMotorcyle(charToInt(dir3), flowRate1);
	m_flowRate.set_m_flowRateCar(charToInt(dir3), flowRate2);
	m_flowRate.set_m_flowRateTruck(charToInt(dir3), flowRate3);
	inputFile.ignore(1);

	inputFile.get(dir4);
	inputFile.ignore(2);
	inputFile >> flowRate1 >> flowRate2 >> flowRate3;
	m_flowRate.set_m_flowRateMotorcyle(charToInt(dir4), flowRate1);
	m_flowRate.set_m_flowRateCar(charToInt(dir4), flowRate2);
	m_flowRate.set_m_flowRateTruck(charToInt(dir4), flowRate3);
	inputFile.ignore(1);

	inputFile.close();
}

void TrafficSim::PrintBoard()
{
	const int MAX_DISPLAY = 6;
	unsigned int counter = 0;

	//begin inersection map
	//line1
	cout << "   SB    " << m_traffic[S].size() << "\n";
	counter = MAX_DISPLAY;
	//lines 2-5
	while (counter > 2)
	{
		if (m_traffic[S].size() >= counter)
		{
			cout << "      X\n";
		}
		else
		{
			cout << "          \n";
		}
		counter--;
	}
	//line6
	if (m_traffic[S].size() >= MAX_DISPLAY - 4)
	{
		cout << "EB    X\n";
	}
	else
	{
		cout << "EB          \n";
	}
	//line 7
	cout << m_traffic[E].size();
	if (m_traffic[E].size() > 9)
	{
		cout << "    ";
	}
	else
	{
		cout << "     ";
	}
	if (!m_traffic[S].empty())
		cout << intToChar(m_traffic[S].front().get_m_type()) << "\n";
	else
		cout << " \n";
	//line 8
	counter = 6;
	while (counter > 1)
	{
		if (m_traffic[E].size() >= counter)
		{
			cout << "X";
		}
		else
		{
			cout << " ";
		}
		counter--;
	}
	if (!m_traffic[E].empty())
	{
		cout << intToChar(m_traffic[E].front().get_m_type());
	}
	else{ cout << " "; }

	cout << " ";
	if (!m_traffic[W].empty())
	{
		cout << intToChar(m_traffic[W].front().get_m_type());
	}
	else
	{
		cout << " ";
	}
	counter = 2;
	while (counter < 7)
	{
		if (m_traffic[W].size() >= counter)
		{
			cout << "X";
		}
		else
		{
			cout << " ";
		}
		counter++;
	}
	//line 9
	cout << "\n      ";
	if (!m_traffic[N].empty())
	{
		cout << intToChar(m_traffic[N].front().get_m_type()) << "    \n";
	}
	else
		cout << "                             \n";
	//line 10
	if (m_traffic[N].size() >= MAX_DISPLAY - 4)
	{
		cout << "      X    WB\n";
	}
	else
	{
		cout << "           WB\n";
	}
	//line 11
	if (m_traffic[N].size() >= MAX_DISPLAY - 3)
	{
		cout << "      X     " << m_traffic[W].size() << "\n";
	}
	else
	{
		cout << "            " << m_traffic[W].size() << "\n";
	}
	//lines 12-14
	if (m_traffic[N].size() >= 4)
	{ cout << "      X\n"; }
	else
	{ cout << "          \n";	}
	if (m_traffic[N].size() >= 5)
	{
		cout << "      X\n";
	}
	else
	{
		cout << "          \n";
	}if (m_traffic[N].size() >= 6)
	{
		cout << "      X\n";
	}
	else
	{
		cout << "          \n";
	}
	//line 15
	cout << "   NB    " << m_traffic[N].size() << "\n";
	//line 16
	cout << "at clock:  " << m_clock << "\n";
	//line 17
	cout << "------------------------\n\n";

}

void TrafficSim::PrintFlowRate()
{
	cout << "\nNorthbound flow rate is: \n" << m_flowRate.get_m_flowRateMotorcyle(N) << " Motorcycles per minute.\n"
		<< m_flowRate.get_m_flowRateCar(N) << " Cars per minute.\n"
		<< m_flowRate.get_m_flowRateTruck(N) << " Trucks per minute.\n";

	cout << "\nSouthbound flow rate is: \n" << m_flowRate.get_m_flowRateMotorcyle(S) << " Motorcycles per minute.\n"
		<< m_flowRate.get_m_flowRateCar(S) << " Cars per minute.\n"
		<< m_flowRate.get_m_flowRateTruck(S) << " Trucks per minute.\n";

	cout << "\nEastbound flow rate is: \n" << m_flowRate.get_m_flowRateMotorcyle(E) << " Motorcycles per minute.\n"
		<< m_flowRate.get_m_flowRateCar(E) << " Cars per minute.\n"
		<< m_flowRate.get_m_flowRateTruck(E) << " Trucks per minute.\n";

	cout << "\nWestbound flow rate is: \n" << m_flowRate.get_m_flowRateMotorcyle(W) << " Motorcycles per minute.\n"
		<< m_flowRate.get_m_flowRateCar(W) << " Cars per minute.\n"
		<< m_flowRate.get_m_flowRateTruck(W) << " Trucks per minute.\n\n";
}

void TrafficSim::AddVehicle(int direction, Vehicle x)
{
	m_traffic[direction].push(x);
}

void TrafficSim::DoRun()
{
	while (m_clock < 120)
	{
		m_clock++;
		DoOneRun();
		PrintBoard();
	}
	printResults();

}

void TrafficSim::DoOneRun()
{

	//light decision variables
	bool nsGreen = false;
	const int nsMin = 30;
	static int nsLightCounter;
	bool ewTfc = (!m_traffic[E].empty() || !m_traffic[W].empty());
	bool ewGreen = false;
	const int ewMin = 10;
	const int ewMax = 30;
	static int ewLightCounter;
	
	//start light decision logic

	//if time < 30 light stays green
	if (m_clock <= nsMin)
	{
		nsGreen = true;
		ewGreen = false;
		nsLightCounter++;
	}
	
	//if time > 30 and e/w tfc present
	if (m_clock > nsMin && ewTfc)
	{

		if (nsLightCounter == ewLightCounter)
		{
			nsLightCounter = 0;
		}

		//let e/w tfc go until ewMin satisfied
		if (ewLightCounter < ewMin)
		{
			ewGreen = true;
			nsGreen = false;
			ewLightCounter++;
		}
		
		//if e/w tfc still present, let go until ewMax
		else if (ewTfc && ewLightCounter >= ewMin && ewLightCounter < ewMax)
		{
			ewGreen = true;
			nsGreen = false;
			ewLightCounter++;
		}

		//once ewMax reached, let n/s go for nsMin
		else
		{
			nsGreen = true;
			ewGreen = false;
			nsLightCounter++;
			if (nsLightCounter == nsMin)
			{
				ewLightCounter = 0;
			}
			if (nsLightCounter < nsMin)
			{
				nsGreen = true;
				ewGreen = false;
			}
			
		}

	}
	//if ewMin not satisfied increment ewLightCounter
	else if (!ewTfc && ewLightCounter < ewMin)
	{
		ewLightCounter++;
	}
	//once ewMin satisfied, if no traffic, change light
	else if (!ewTfc && ewLightCounter >= ewMin && ewLightCounter < ewMax)
	{
	ewGreen = false;
	nsGreen = true;
	//set counter to max to let n/s tfc go
	ewLightCounter = ewMax;
	nsLightCounter = 0;
	}
	else if (!ewTfc && ewLightCounter == ewMax)
	{
		nsLightCounter++;
	}
	//end light decision logic
	

	
	
	//if n/s light is green, pop tfc 
	if (nsGreen)
	{
		if (!m_traffic[N].empty())
		{
			if (m_traffic[N].front().getOutFlag() && (m_traffic[N].front().getTimeOut() < m_clock))
			{
				m_traffic[N].front().setOutFlag(false);
			}

			if (!m_traffic[N].front().getOutFlag())
			{
				if (m_traffic[N].front().get_m_clearTime() == 1)
				{
					m_traffic[N].front().setTimeOut(m_clock);
					m_traffic[N].front().setOutFlag(true);
				}
				else if (m_traffic[N].front().get_m_clearTime() == 2)
				{
					m_traffic[N].front().setTimeOut(m_clock+1);
					m_traffic[N].front().setOutFlag(true);
				}
				else if (m_traffic[N].front().get_m_clearTime() == 3)
				{
					m_traffic[N].front().setTimeOut(m_clock + 2);
					m_traffic[N].front().setOutFlag(true);
				}
				else if (m_traffic[N].front().get_m_clearTime() == 4)
				{
					m_traffic[N].front().setTimeOut(m_clock + 3);
					m_traffic[N].front().setOutFlag(true);
				}
				else if (m_traffic[N].front().get_m_clearTime() == 5)
				{
					m_traffic[N].front().setTimeOut(m_clock + 4);
					m_traffic[N].front().setOutFlag(true);
				}
				else if (m_traffic[N].front().get_m_clearTime() == 6)
				{
					m_traffic[N].front().setTimeOut(m_clock + 5);
					m_traffic[N].front().setOutFlag(true);
				}
			}

			if (m_traffic[N].front().getTimeOut() == m_clock)
			{
				m_results.appendNode(m_traffic[N].front());
				m_traffic[N].pop();
			}
		}
		if (!m_traffic[S].empty())
		{
			if (m_traffic[S].front().getOutFlag() && (m_traffic[S].front().getTimeOut() < m_clock))
			{
				m_traffic[S].front().setOutFlag(false);
			}

			if (!m_traffic[S].front().getOutFlag())
			{
				if (m_traffic[S].front().get_m_clearTime() == 1)
				{
					m_traffic[S].front().setTimeOut(m_clock);
					m_traffic[S].front().setOutFlag(true);
				}
				else if (m_traffic[S].front().get_m_clearTime() == 2)
				{
					m_traffic[S].front().setTimeOut(m_clock + 1);
					m_traffic[S].front().setOutFlag(true);
				}
				else if (m_traffic[S].front().get_m_clearTime() == 3)
				{
					m_traffic[S].front().setTimeOut(m_clock + 2);
					m_traffic[S].front().setOutFlag(true);
				}
				else if (m_traffic[S].front().get_m_clearTime() == 4)
				{
					m_traffic[S].front().setTimeOut(m_clock + 3);
					m_traffic[S].front().setOutFlag(true);
				}
				else if (m_traffic[S].front().get_m_clearTime() == 5)
				{
					m_traffic[S].front().setTimeOut(m_clock + 4);
					m_traffic[S].front().setOutFlag(true);
				}
				else if (m_traffic[S].front().get_m_clearTime() == 6)
				{
					m_traffic[S].front().setTimeOut(m_clock + 5);
					m_traffic[S].front().setOutFlag(true);
				}
			}
			
			if (m_traffic[S].front().getTimeOut() == m_clock)
			{
				m_results.appendNode(m_traffic[S].front());
				m_traffic[S].pop();
			}
		}

	}
	//if e/w light is green, pop tfc
	if (ewGreen)
	{
		if (!m_traffic[E].empty())
		{
			if (m_traffic[E].front().getOutFlag() && (m_traffic[E].front().getTimeOut() < m_clock))
			{
				m_traffic[E].front().setOutFlag(false);
			}

			if (!m_traffic[E].front().getOutFlag())
			{
				if (m_traffic[E].front().get_m_clearTime() == 1)
				{
					m_traffic[E].front().setTimeOut(m_clock);
					m_traffic[E].front().setOutFlag(true);
				}
				else if (m_traffic[E].front().get_m_clearTime() == 2)
				{
					m_traffic[E].front().setTimeOut(m_clock + 1);
					m_traffic[E].front().setOutFlag(true);
				}
				else if (m_traffic[E].front().get_m_clearTime() == 3)
				{
					m_traffic[E].front().setTimeOut(m_clock + 2);
					m_traffic[E].front().setOutFlag(true);
				}
				else if (m_traffic[E].front().get_m_clearTime() == 4)
				{
					m_traffic[E].front().setTimeOut(m_clock + 3);
					m_traffic[E].front().setOutFlag(true);
				}
				else if (m_traffic[E].front().get_m_clearTime() == 5)
				{
					m_traffic[E].front().setTimeOut(m_clock + 4);
					m_traffic[E].front().setOutFlag(true);
				}
				else if (m_traffic[E].front().get_m_clearTime() == 6)
				{
					m_traffic[E].front().setTimeOut(m_clock + 5);
					m_traffic[E].front().setOutFlag(true);
				}
			}

			if (m_traffic[E].front().getOutFlag() && (m_traffic[E].front().getTimeOut() < m_clock))
			{
				m_traffic[E].front().setTimeOut(m_clock + (m_traffic[E].front().getTimeOut() - m_traffic[E].front().getTimeEntered()));
			}

			if (m_traffic[E].front().getTimeOut() == m_clock)
			{
				m_results.appendNode(m_traffic[E].front());
				m_traffic[E].pop();
			}
		}
		if (!m_traffic[W].empty())
		{
			if (m_traffic[W].front().getOutFlag() && (m_traffic[W].front().getTimeOut() < m_clock))
			{
				m_traffic[W].front().setOutFlag(false);
			}

			if (!m_traffic[W].front().getOutFlag())
			{
				if (m_traffic[W].front().get_m_clearTime() == 1)
				{
					m_traffic[W].front().setTimeOut(m_clock);
					m_traffic[W].front().setOutFlag(true);
				}
				else if (m_traffic[W].front().get_m_clearTime() == 2)
				{
					m_traffic[W].front().setTimeOut(m_clock + 1);
					m_traffic[W].front().setOutFlag(true);
				}
				else if (m_traffic[W].front().get_m_clearTime() == 3)
				{
					m_traffic[W].front().setTimeOut(m_clock + 2);
					m_traffic[W].front().setOutFlag(true);
				}
				else if (m_traffic[W].front().get_m_clearTime() == 4)
				{
					m_traffic[W].front().setTimeOut(m_clock + 3);
					m_traffic[W].front().setOutFlag(true);
				}
				else if (m_traffic[W].front().get_m_clearTime() == 5)
				{
					m_traffic[W].front().setTimeOut(m_clock + 4);
					m_traffic[W].front().setOutFlag(true);
				}
				else if (m_traffic[W].front().get_m_clearTime() == 6)
				{
					m_traffic[W].front().setTimeOut(m_clock + 5);
					m_traffic[W].front().setOutFlag(true);
				}
			}

			if (m_traffic[W].front().getOutFlag() && (m_traffic[W].front().getTimeOut() < m_clock))
			{
				m_traffic[W].front().setTimeOut(m_clock + (m_traffic[W].front().getTimeOut() - m_traffic[W].front().getTimeEntered()));
			}

			if (m_traffic[W].front().getTimeOut() == m_clock)
			{
				m_results.appendNode(m_traffic[W].front());
				m_traffic[W].pop();
			}
		}

	}

	//Add vehicles to queues
	addVehicles();
	
}

int TrafficSim::charToInt(char x)
{
	if (x == 'N') { return 0; }
	else if (x == 'S') { return 1; }
	else if (x == 'E') { return 2; }
	else if (x == 'W') { return 3; }
	else { return -1; }
}

char TrafficSim::intToChar(int x)
{
	if (x == 1) { return 'M'; }
	else if (x == 2) { return 'C'; }
	else if (x == 3) { return 'T'; }
	else { return 'E'; }
}

void TrafficSim::addVehicles()
{
	int index = 0;
	//add vehicles to intersections 
	while (index < 4)
	{
		if (m_flowRate.get_m_flowRateMotorcyle(index) != 0)
		{
			if (m_clock > 0 && (m_clock % (60 / m_flowRate.get_m_flowRateMotorcyle(index)) == 0))
				AddVehicle(index, Vehicle(CYCLE, m_clock));
		}
		if (m_flowRate.get_m_flowRateCar(index) != 0)
		{
			if (m_clock > 0 && (m_clock % (60 / m_flowRate.get_m_flowRateCar(index)) == 0))
				AddVehicle(index, Vehicle(CAR, m_clock));
		}
		if (m_flowRate.get_m_flowRateTruck(index) != 0)
		{
			if (m_clock > 0 && (m_clock % (60 / m_flowRate.get_m_flowRateTruck(index)) == 0))
				AddVehicle(index, Vehicle(TRUCK, m_clock));
		}
		index++;
	}
}
void TrafficSim::printResults()
{
	cout << "The final results are: \n";
	cout << "The number of vehicle that passed through the intersection is: " << m_results.getLength() << "\n";
	cout << "The number of Motorcycles that passed through the instersection is: " << m_results.getCycles() << "\n";
	cout << "The number of Cars that passed through the instersection is: " << m_results.getCars() << "\n";
	cout << "The number of Trucks that passed through the instersection is: " << m_results.getTrucks() << "\n";
	cout << "The average wait time for this intersection is: " << m_results.getAvgTime() / m_results.getLength() << "\n";

}
