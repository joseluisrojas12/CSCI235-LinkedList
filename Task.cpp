/***************************************************************************
Title:		Task.cpp
Author:		Jose Luis Rojas-Salazar
Date Created:	3/30/2017
Class:		Spring 2017, CSCI 235-03, Mon & Wed 7:00pm-8:15pm
Professor:	Aarsh Vora
Purpose:	Assigment #2
Description:	Implementation for class Task (Task.cpp)
****************************************************************************/


#include "Task.h"

using namespace std;

//All task start as not completed so completed must be by defect false.
Task::Task()
{
	completed = false;
}


Task::~Task()
{
}

bool Task::isCompleted()
{
	return completed;
}

//In case task is marked as completed function complete() set completed as true.
void Task::complete()
{
	completed = true;
}

//In this case Task is generic so not display GENERIC only its description.
string Task::typeStr()
{
	return ""; //Displays nothing
}

//Letter G is at the start of the line that describes it is a generic task in the 
//Task File Format.
char Task::type()
{
	return 'G';
}


//If command DETAILED is used the display or output will have two formats: the first
//one is for special event (Shopping,Event or Homework) and the second one for generic task
void Task::output(bool detailed)
{
	if (typeStr().size())
		cout << date.Get() + " - [" + typeStr() + "] " + description << endl;
	else
		cout << date.Get() + " - " + description << endl;
}

//Start to input the elements for the object Task like date and description
void Task::input()
{
	string datestr;

	cout << "When is this task due?" << endl;
	getline(cin, datestr);

	date.Set(datestr);

	cout << "How would you describe this task?" << endl;
	getline(cin, description);

	//if (type == "G")// Giving problems
		cout << "Task added successfully" <<endl;
}


//Used to write the task list to a file
void Task::write(std::ostream & str)
{
	str << type() << "|" << date.Get()<<"|"<<description;
}

//Used to read the task list from a file
void Task::read(std::istream & str)
{
	string datestr;
	getline(str, datestr, '|');///use | as separator
	date.Set(datestr);//read and set date string

	getline(str, description, '|');///use | as separator
}

//Used to sort the task using the overloaded operator < in Date class, when will be
//called by SortedLinkedList at the moment to create the task and added to the list.
bool Task::before(const Task & arg)
{
	return date < arg.date;
}

