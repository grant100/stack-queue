// Project3.cpp : Defines the entry point for the console application.
//
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
#include "Stack.h"
#include "Queue.h"

using namespace std;
typedef int node_entry;

const int ZERO = 0;
const int ONE = 1;
const int TWO = 2;

// Function Name:	void Print(Stack_Node* p)
// Purpose:	 print function
// Parameters:	node*
// Returns:	   void
// Pre-conditions:	
// Post-conditions:
void Print(Stack_Node* p)
{
	cout << "\n" << p->entry;
}

// Function Name:	void Print(Queue_Node* p)
// Purpose:	 print function
// Parameters:	node*
// Returns:	   void
// Pre-conditions:	
// Post-conditions:
void Print(Queue_Node* p)
{
	cout << "\n" << p->entry;
}

// Function Name: continueInput()
// Purpose:	  check that input from user is valid
// Parameters: none
// Returns:	  int
// Pre-conditions: none	
// Post-conditions: none
int continueInput()
{
	int input;
	std::cin >> input;
	while (std::cin.fail() || input > TWO || input < ONE)//if failed, not number
	{
		std::cin.clear();
		std::cin.ignore();
		cout << "\nError... Incorrect input!" << "\nLoad new file? 1 = Yes 2 = No : ";
		std::cin >> input;
	}
	return input;
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	bool isOpen = false;
	bool isContinue = true;
	int continue_in;
	string input, command, data;
	string delimeter = " ";
	node_entry conv_data;
	Stack stack;
	Queue queue;
	fstream iFile;
	
	
	

	std::cout << "Grant Sowards" << "\nCS 2420" << "\nProject 3 Stack/Queue" << endl;
	while (isContinue)
	{
		std::cout << "\nEnter file name (include extension), e.g. numbers.txt: " << endl;
		while (!isOpen)
		{
			string cinName;
			cin >> cinName;
			string fileName = cinName;
			iFile.open(fileName);
			if (iFile.is_open())
			{
				isOpen = true;
				std::cout << "\nOpening File..." << endl;
			}
			else
			{
				cin.clear();
				std::cout << "Could not open file!" << "\n\nTry Again: ";
			}

		}
		std::cout << "\nOperation  Stack  Value  Result" << endl;
		while (!iFile.eof()) //read in file
		{
			int pos = 0;
			getline(iFile, input);
			command = input.substr(ZERO, input.find(delimeter));//store string

			if ((pos = input.find(delimeter) != std::string::npos))
			{
				input.erase(ZERO, input.find(delimeter) + delimeter.length());//erase everything on line up through the delimeter
				data = input;
				conv_data = stoi(data);//convert data type

				if (command == "push")
				{

					cout << "\n" << command << "       " << "Stack   " << conv_data << "    " << stack.push(conv_data);
				}
				else if (command == "append")
				{

					cout << "\n" << command << "     " << "Queue   " << conv_data << "    " << queue.append(conv_data);
				}
				else
				{
					cout << "\nInccorect Command...";
				}

			}
			else
			{
				if (command == "serve")
				{
					string served = queue.getFront();
					cout << "\n" << command << "      " << "Queue" << "   ---" << "   " << queue.serve() << "   Served: " << served;
				}
				else if (command == "pop")
				{
					string popped = stack.getTop();
					cout << "\n" << command << "        " << "Stack " << "  ---" << "   " << stack.pop() << "   Popped: " << popped;
				}
				else
				{
					cout << "\nInccorect Command...";
				}

			}

		}
		iFile.close();
		cout << "\n\n--------------------Traverse Stack----------------------" << endl;
		stack.traversePrint(Print);
		cout << "\n\n---------------------Traverse Queue---------------------" << endl;
		queue.traversePrint(Print);
		stack.clear();//clear stack
		queue.clear();//clear queue
		cout << "\n\nItems Cleared...";
		cout << "\nLoad a new file? 1 = Yes 2 = No: ";
		
		continue_in = continueInput();//check for continuation
		if (continue_in == ONE)
		{
			isContinue = true;
			isOpen = false;
		}
		else if (continue_in == TWO)
		{
			isContinue = false;
		}
	}
	
	
	cout << "\n\nExiting...";
	
	
	std::cin.clear();
	std::cin.ignore();
	std::cin.get();
	return 0;
}

