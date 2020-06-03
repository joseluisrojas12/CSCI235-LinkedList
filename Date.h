/***************************************************************************
Title:		Date.h
Author:		Jose Luis Rojas-Salazar
Date Created:	3/30/2017
Class:		Spring 2017, CSCI 235-03, Mon & Wed 7:00pm-8:15pm
Professor:	Aarsh Vora
Purpose:	Assigment #2
Description:	Interface for class Date (Date.h)
****************************************************************************/

//The members for class Date will be used to sort the tasks.
//Use string stream to manipulate d, m and y at the moment to compare
//The class Date will be called by Task class so at the moment to be added
//SortedLinkedList class use the info fron Date class to sort the task in
//the list. 

#ifndef DATE_H
#define DATE_H

#include <string>

class Date
{
	std::string d;
	std::string m;
	std::string y;
public:

	std::string Get();
	void Set(std::string & arg);
	Date();
	virtual ~Date();

	bool operator <(const Date & arg);
	bool operator ==(const Date & arg);
	bool operator >(const Date & arg);

};

#endif
