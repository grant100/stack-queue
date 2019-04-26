#pragma once
//#ifndef Queue_H
//#define Queue_H
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

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
typedef int node_entry;


//Struct to define node properties
struct Queue_Node
{
	Queue_Node();
	Queue_Node(int);
	node_entry entry;
	Queue_Node *nlink = NULL;

};

//Class Definition for Stack
class Queue
{
public:
	Queue();
	string append(node_entry);
	string serve();
	node_entry getCount(){ return que_count; };
	void traversePrint(void(*visit)(Queue_Node *p));
	string getFront(){ if (front == NULL){ return "NULL"; } else return to_string(front->entry); };
	void clear();
protected:
	Queue_Node *front;
	Queue_Node *rear;
	node_entry que_count = 0;
	node_entry delete_count = 0;
};


//#endif