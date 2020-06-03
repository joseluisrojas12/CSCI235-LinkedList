/***************************************************************************
Title:		Date.cpp
Author:		Jose Luis Rojas-Salazar
Date Created:	3/30/2017
Class:		Spring 2017, CSCI 235-03, Mon & Wed 7:00pm-8:15pm
Professor:	Aarsh Vora
Purpose:	Assigment #2
Description:	Implementation for class Date (Date.cpp)
****************************************************************************/


#include "Date.h"
#include <sstream>
using namespace std;


Date::Date()
{
}


Date::~Date()
{
}


std::string Date::Get()
{
	return m+"/"+d+"/"+y;
}

//To set the date for each task use string stream to manipulate m, d and y with
//overloaded operators <,>,==.

void Date::Set(std::string & arg)
{
	stringstream str(arg);
	//parse string go parts
	getline(str, m, '/');
	getline(str, d, '/');
	getline(str, y);
}

//Overloaded comparative operators to check task date at the moment to add and
//sorting the new task by the SortedLinkedList class that inherits Task and Date class

bool Date::operator <(const Date & arg)
{

	return (
		(y < arg.y) ||
		((y == arg.y) && (m < arg.m)) ||
		((y == arg.y) && (m == arg.m) && (d < arg.d))
		);
}

bool Date::operator ==(const Date & arg)
{
	return 		(y == arg.y) && (m == arg.m) && (d == arg.d);
}


bool Date::operator >(const Date & arg)
{
	return (
		(y > arg.y) ||
		((y == arg.y) && (m > arg.m)) ||
		((y == arg.y) && (m == arg.m) && (d > arg.d))
		);
}

