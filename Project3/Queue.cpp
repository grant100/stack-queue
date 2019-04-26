// Author:	   Grant Sowards
// Assignment:	   project 3
// File:	   project3.cpp, stack.cpp, queue.cpp
// Instructor:	   Reza Sonati
// Class:	   CS 2420  Section: 001 
// Date Written:   5/24/2015 
// Description:  Stack and Queue

// I declare that the source code contained in this assignment was written solely by me.
// I understand that copying any source code, in whole or in part,
// constitutes cheating, and that I will receive a zero on this project
// if I am found in violation of this policy.

#include "Queue.h"
#include "stdafx.h"

//Constructor definition for Queue 
Queue::Queue()
{
	front = NULL;
	rear = NULL;
}

// Function Name:	string Queue::serve()
// Purpose:	  remove item from front of queue
// Parameters:	
// Returns:	   string
// Pre-conditions:	
// Post-conditions: 
string Queue::serve()
{
	if (front == NULL)
	{
		return "underflow";
	}
	else
	{
		Queue_Node *p;
		p = front;
		if (front->nlink == NULL)
		{
			front = NULL;
		}
		else
		{
			front = front->nlink;
		}

		delete p;
		return "success";
		que_count--;
	}
}

// Function Name:	string Queue::append(node_entry item)
// Purpose:	  add item to end of queue
// Parameters:	node_entry
// Returns:	   string
// Pre-conditions:	
// Post-conditions: 
string Queue::append(node_entry item)
{
	Queue_Node *p = new Queue_Node(item);
	if (front == NULL)
	{
		front = p;
		rear = p;
	}
	else
	{
		rear->nlink = p;
		rear = p;
	}
	return "success";
	que_count++;

}

// Function Name:	void Queue::traversePrint(void(*visit)(Queue_Node *p))
// Purpose:	  traverse and print out items in queue
// Parameters:	Print function
// Returns:	   void
// Pre-conditions:	
// Post-conditions: 
void Queue::traversePrint(void(*visit)(Queue_Node *p))
{
	Queue_Node *p;
	p = front;
	if (front == NULL)
	{
		cout << "\nNo items in Queue!";
	}
	else
	{
		while (p != NULL)
		{

			(*visit)(p);
			p = p->nlink;
		}
	}

}

// Function Name:	void Queue::clear()
// Purpose:	  clear all items in queue
// Parameters:	
// Returns:	   void
// Pre-conditions:	
// Post-conditions: 
void Queue::clear()
{
	Queue_Node *p, *q;
	while (front != NULL)
	{
		p = front;
		q = NULL;
		while (p->nlink != NULL)
		{
			q = p;
			p = p->nlink;
		}
		if (q == NULL)
		{
			delete p;
			front = NULL;
		}
		else
		{
			q->nlink = NULL;
			delete p;
		}
		delete_count++;
	}
}
//node constructor
Queue_Node::Queue_Node(node_entry item)
{
	entry = item;
}