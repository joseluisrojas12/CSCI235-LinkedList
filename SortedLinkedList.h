/***************************************************************************
Title:		SortedLinkedList.h
Author:		Jose Luis Rojas-Salazar
Date Created:	3/30/2017
Class:		Spring 2017, CSCI 235-03, Mon & Wed 7:00pm-8:15pm
Professor:	Aarsh Vora
Purpose:	Assigment #2
Description:	Interface for class SortedLinkedList (SortedLinkedList.h)
****************************************************************************/


//SortedLinkedList inherits Task class to use its member date to sort or locate the
//task in the list.

#ifndef SORDTEDLINKEDLIST_H
#define SORDTEDLINKEDLIST_H

#include "Task.h"


class SortedLinkedListItem
{
public:
	SortedLinkedListItem * next; //Use of pointers next and prev to locate
	SortedLinkedListItem * prev; //the correct position where put the new task
	Task * task;
	SortedLinkedListItem(Task * task);
	~SortedLinkedListItem();


	friend class SortedLinkedList;
};

class SortedLinkedList
{
	SortedLinkedListItem * root;
public:

	void Free();
	void Add(Task * task);
	Task *Get(SortedLinkedListItem * itr);
	void Remove(SortedLinkedListItem * itr);
	SortedLinkedListItem *Next(SortedLinkedListItem * itr);

	SortedLinkedList();
	~SortedLinkedList();
};

#endif
