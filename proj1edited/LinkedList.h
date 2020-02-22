/*****************************************
** File: Linked_List.h
** Project: CMSC 341 Project 1, Fall 2015
** Author: Justin French
** Date: 9/17/15
** Section: 05
** E-mail: jfrench2@umbc.edu
**
** This file contains the Linked_List class definition for Project 1.

** This program defines a Singly Linked List container.
**
**
***********************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Vehicle.h"
#include <iostream>

class LinkedList
{
public:
	// Constructor
	LinkedList();
		
	// Destructor
	~LinkedList();
	
	// Linked list operations
	void appendNode(Vehicle);
	void insertNode(Vehicle);
	void deleteNode(Vehicle);
	void displayList() const;
	int getLength() const;
	int getCycles() const;
	int getCars() const;
	int getTrucks() const;
	double getAvgTime() const;
		
private:
	struct ListNode
	{
	Vehicle passed; 
	ListNode *next; // next node pointer
	};
	
	ListNode *head; // head pointer

	int listSize(ListNode *) const;
	int listCycles(ListNode *) const;
	int listCars(ListNode *) const;
	int listTrucks(ListNode *) const;
	double listAvgTime(ListNode *) const;
};



#endif
