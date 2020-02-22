/*****************************************
** File: Linked_List.cpp
** Project: CMSC 341 Project 1, Fall 2015
** Author: Justin French
** Date: 9/17/15
** Section: 05
** E-mail: jfrench2@umbc.edu
**
** This file contains the Linked_List class for Project 1.

** This program implements a Singly Linked List container.
**
**
***********************************************/

#include "LinkedList.h"

LinkedList::LinkedList()
{ head = NULL; }

void LinkedList::appendNode(Vehicle x)
{
	ListNode *newNode; // To point to a new node
	ListNode *nodePtr; // To move through the list

	// make a new node and store vehicle there.
	newNode = new ListNode;
	newNode->passed = x;
	newNode->next = NULL;

	// If there are no nodes in the list
	// make newNode the first node.
	if (!head)
		head = newNode;
	else // Otherwise, insert newNode at end.
	{
		// Initialize nodePtr to head of list.
		nodePtr = head;

		// Find the last node in the list.
		while (nodePtr->next)
		nodePtr = nodePtr->next;

		// Insert newNode as the last node.
		nodePtr->next = newNode;
	}

}

int LinkedList::getLength() const
{
	return listSize(head);
}
int LinkedList::getCycles() const
{
	return listCycles(head);
}
int LinkedList::getCars() const
{
	return listCars(head);
}
int LinkedList::getTrucks() const
{
	return listTrucks(head);
}
double LinkedList::getAvgTime() const
{
	return listAvgTime(head);
}

int LinkedList::listSize(ListNode * x) const 
{
	if (x != NULL)
	{
		return 1 + listSize(x->next);
	}
	else
	{
		return 0;
	}
}

int LinkedList::listCycles(ListNode * x) const
{
	if (x != NULL)
	{
		if (x->passed.get_m_type() == 1)
			return 1 + listCycles(x->next);
		else
			return 0 + listCycles(x->next);
	}
	else
		return 0;
}

int LinkedList::listCars(ListNode * x) const
{
	if (x != NULL)
	{
		if (x->passed.get_m_type() == 2)
			return 1 + listCars(x->next);
		else
			return 0 + listCars(x->next);
	}
	else
		return 0;
}

int LinkedList::listTrucks(ListNode * x) const
{
	if (x != NULL)
	{
		if (x->passed.get_m_type() == 3)
			return 1 + listTrucks(x->next);
		else
			return 0 + listTrucks(x->next);
	}
	else
		return 0;
}

double LinkedList::listAvgTime(ListNode * x) const
{
	if (x != NULL)
	{
		double waitTime = 0;
		waitTime += ((x->passed.getTimeOut() - x->passed.getTimeEntered()) + listAvgTime(x->next));
		return waitTime;
	}
	else
		return 0;
}

LinkedList::~LinkedList()
{
	ListNode *nodePtr; // To traverse the list
	ListNode *nextNode; // To point to the next node
	
	// Position nodePtr at the head of the list.
	nodePtr = head;
	
	// While nodePtr is not at the end of the list...
	while (nodePtr != NULL)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;
		
		// Delete the current node.
		delete nodePtr;
		
		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}

