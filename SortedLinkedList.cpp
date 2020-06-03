/***************************************************************************
Title:		SortedLinkedList.cpp
Author:		Jose Luis Rojas-Salazar
Date Created:	3/30/2017
Class:		Spring 2017, CSCI 235-03, Mon & Wed 7:00pm-8:15pm
Professor:	Aarsh Vora
Purpose:	Assigment #2
Description:	Implementation of class SortedLinkedList (SortedLinkedList.cpp)
****************************************************************************/


//SortedLinkedList will locate the new task in the list using its member date, 
//also will be used to get information from the list remove nodes and return the
//memory used to the system when program exit. 


#include "SortedLinkedList.h"

//Pointers prev and next are initialized to NULL, will be used to insert the new
//task in the list.
SortedLinkedListItem::SortedLinkedListItem(Task * t)
{
	task = t;
	next = 0;
	prev = 0;
}

//To eliminate a single node or task from the linked list
SortedLinkedListItem::~SortedLinkedListItem()
{
	delete task;
}


//Add the new task is practically Insert a new node in the linked list.
//Remember that will use Date member function before() that use the 
//overloaded comparator < to check the dat from the task object. 
void SortedLinkedList::Add(Task * task)
{
	SortedLinkedListItem * item = new SortedLinkedListItem(task);

	SortedLinkedListItem * pos = root;

	//Try insert new task at first position
	if (!root || task->before(*root->task))
	{
		item->next = root;
		if (root)root->prev = item;
		root = item;
		return;
	}


	while (true)
	{
		///now try insert task after current element
		if (!pos->next || task->before(*pos->next->task))
		{
			item->next = pos->next;
			item->prev = pos;

			if (pos->next)pos->next->prev = item;
			pos->next = item;

			return;
		}

		pos = pos->next;
	}



}

//Remove the task by delete pointer and redirect prev and next pointers to
//close the linked list.
void SortedLinkedList::Remove(SortedLinkedListItem * itr)
{

	if (itr->prev)
		itr->prev->next = itr->next;
	else
		root = itr->next;

	if (itr->next)
		itr->next->prev = itr->prev;

	delete itr;
}

//To get the info from the task pointed by itr at that moment.
Task *SortedLinkedList::Get(SortedLinkedListItem * itr)
{
	if (itr)
		return itr->task;
	else
		return 0;
}

//To traverse trought the linked list
SortedLinkedListItem *SortedLinkedList::Next(SortedLinkedListItem * itr)
{
	if (itr)
		return itr->next;
	else
		return root;
}

//Constructor for the class put the root pointer (like head pointer in linked list)
//in 0 or NULL
SortedLinkedList::SortedLinkedList()
{
	root = 0;
}

//The destructor will call the function Free() that will be used to return the memory
//to the system.
SortedLinkedList::~SortedLinkedList()
{
	Free();
}


//To return the memory used during the life time of the program to the PC at the
//moment to end the program.
void SortedLinkedList::Free()
{
	while (root)
	{
		SortedLinkedListItem * next = root->next;

		delete root;

		root = next;
	}
	root = 0;
}

