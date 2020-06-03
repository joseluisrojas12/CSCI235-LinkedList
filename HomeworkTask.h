/***************************************************************************
Title:		HomeworkTask.h
Author:		Jose Luis Rojas-Salazar
Date Created:	3/30/2017
Class:		Spring 2017, CSCI 235-03, Mon & Wed 7:00pm-8:15pm
Professor:	Aarsh Vora
Purpose:	Assigment #2
Description:	Interface for class HomeworkTask (HomeworkTask.h)
****************************************************************************/

//HomeworkTask inherits Task class and added one element type string to its
//object (subject). The public members functions are virtual because they also  
//will use the the public member functions from Task class.


#ifndef HOMEWORK_TASK_H
#define HOMEWORK_TASK_H

#include "Task.h"
#include <string>

class HomeworkTask :
	public Task
{
std::string subject;
public:
	HomeworkTask();
	~HomeworkTask();



	virtual std::string typeStr();
	virtual char type();
	virtual void read(std::istream & str);
	virtual void write(std::ostream & str);

	virtual void input();
	virtual void output(bool detailed);
};


#endif
