#pragma once
//#ifndef Stack_H
//#define Stack_H

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
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
typedef int node_entry;
//Struct to define node properties
struct Stack_Node
{
	Stack_Node();
	Stack_Node(int);
	node_entry entry;
	Stack_Node *nlink = NULL;

};
//Class Definition for Stack
class Stack
{
public:
	Stack();
	string push(node_entry);
	string pop();
	void traversePrint(void(*visit)(Stack_Node *p));
	node_entry getCount(){ return stack_count; };
	string getTop(){ if (top == NULL){ return "NULL"; } else { return to_string(top->entry); } };
	void clear();
protected:
	Stack_Node *top;
	node_entry stack_count = 0;
	node_entry delete_count = 0;
};
//#endif
