/***************************************************************************
Title:		EventTask.h
Author:		Jose Luis Rojas-Salazar
Date Created:	3/30/2017
Class:		Spring 2017, CSCI 235-03, Mon & Wed 7:00pm-8:15pm
Professor:	Aarsh Vora
Purpose:	Assigment #2
Description:	Interface for class EventTask (EventTask.h)
****************************************************************************/


//Inherits the generic task and its members (completed?,date,description)
//but added two elements to its object: where and when both type string.
//the virtual functions are inherit from generic task but will be complement
//because there are elements added.


#ifndef EVENT_TASK_H
#define EVENT_TASK_H

#include "Task.h"

class EventTask :
	public Task
{
	std::string where;
	std::string when;
public:
	EventTask();
	~EventTask();


	virtual std::string typeStr();
	virtual char type();
	virtual void read(std::istream & str);
	virtual void write(std::ostream & str);

	virtual void input();
	virtual void output(bool detailed);
};

#endif
