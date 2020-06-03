/***************************************************************************
Title:		EventTask.cpp
Author:		Jose Luis Rojas-Salazar
Date Created:	3/30/2017
Class:		Spring 2017, CSCI 235-03, Mon & Wed 7:00pm-8:15pm
Professor:	Aarsh Vora
Purpose:	Assigment #2
Description:	Implementation for class EventTask (EventTask.cpp)
****************************************************************************/


#include "EventTask.h"

using namespace std;

EventTask::EventTask()
{
}


EventTask::~EventTask()
{
}

//Display [EVENT] when use comands PRINT and DETAILED.
std::string EventTask::typeStr()
{
	return "EVENT";
}

//Write E at the start of task line in the Tasks Line Format.
char EventTask::type()
{
	return 'E';
}


//Read the task from the file to be load.
//First read the part to the generic task and then read the part for Event task
void EventTask::read(std::istream & str)
{
	Task::read(str);
	getline(str, where, '|');///use | as separator
	getline(str, when, '|');///use | as separator
}

//Write the task to a file
//First write the part to the generic task and then write the part of Evebnt task
void EventTask::write(std::ostream & str)
{
	Task::write(str);

	str << "|" << where<<"|"<<when;
}

//Once is called to construct the Event object use first task generic class and then
//adding the other string members to the object Event using getline.  
void EventTask::input()
{
	Task::input();

	cout << "Where is this event taking place ?" << endl;
	getline(cin, where);
	cout << "When is this event taking place ?" << endl;
	getline(cin, when);
	cout << "Task added successfully." << endl;
}

//Display the Event task detailed if command DETAILED is used
//Again generic task is called first to be displayed and then the part for Event task.
void EventTask::output(bool detailed)
{
	Task::output(detailed);

	if (detailed)
	{
		cout << "    WHERE: " << where << endl;
		cout << "    WHEN: " << when << endl;
	}

}
