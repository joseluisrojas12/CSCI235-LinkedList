/***************************************************************************
Title:		Task.h
Author:		Jose Luis Rojas-Salazar
Date Created:	3/30/2017
Class:		Spring 2017, CSCI 235-03, Mon & Wed 7:00pm-8:15pm
Professor:	Aarsh Vora
Purpose:	Assigment #2
Description:	Interface for class Task (Task.h)
****************************************************************************/


//Task class will be the generic task due all the other tasks Shopping,Event, 
//and Homework inherits its members so the object constructed using Task blueprint
//will be like:  /bool(completed?)/string(date)/string(description)/
//and Task class inherits Date class that will be used their members by 
//SortedLinkeList to sort and position the task in the List when it is created.

#ifndef TASK_H
#define TASK_H

#include "Date.h"
#include <string>
#include <iostream>

class Task
{
	bool completed; //completed,date and description will be used also in the
	Date date;      //other tasks so Task class will be inherit in them.
	std::string description;
public:
	Task();
	virtual ~Task();

	virtual std::string typeStr();
	virtual char type();
	virtual void read(std::istream & str);
	virtual void write(std::ostream & str);

	virtual void input();
	virtual void output(bool detailed);

	bool before(const Task & arg); //use Date info to sort task by date in the list
	bool isCompleted();
	void complete();
};

#endif
