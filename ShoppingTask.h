/***************************************************************************
Title:		ShoppingTask.h
Author:		Jose Luis Rojas-Salazar
Date Created:	3/30/2017
Class:		Spring 2017, CSCI 235-03, Mon & Wed 7:00pm-8:15pm
Professor:	Aarsh Vora
Purpose:	Assigment #2
Description:	Interface for ShoppingTask (ShoppingTask.h)
****************************************************************************/


//HomeworkTask inherits Task class and added a list of elements type string
//must type DONE to end input.The public members functions are virtual because  
//they also will use the the public member functions from Task class.


#ifndef SHOPING_TASK_H
#define SHOPING_TASK_H

#include "Task.h"
class ShoppingTask :
	public Task
{
	std::string products;//| separated items
public:
	ShoppingTask();
	~ShoppingTask();

	virtual std::string typeStr();
	virtual char type();
	virtual void read(std::istream & str);
	virtual void write(std::ostream & str);

	virtual void input();
	virtual void output(bool detailed);
};

#endif
