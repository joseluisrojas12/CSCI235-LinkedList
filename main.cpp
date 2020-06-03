/***************************************************************************
Title:		main.cpp
Author:		Jose Luis Rojas-Salazar
Date Created:	3/30/2017
Class:		Spring 2017, CSCI 235-03, Mon & Wed 7:00pm-8:15pm
Professor:	Aarsh Vora
Purpose:	Assigment #2
Description:	Implementation of class main (main.cpp)
****************************************************************************/

//The implementation for main() will inherits all the four classes to construct the 
//tasks, SortedLinkedList inherits generic task due date is one of their member and
//is used to sort the task in the linked list when a task is added. 

#include  <iostream>
#include  <fstream>
#include  <sstream>
#include  <string>
#include  <cctype>
#include  "SortedLinkedList.h"
#include  "HomeworkTask.h"
#include  "EventTask.h"
#include  "ShoppingTask.h"

using namespace std;

//Create task from given type, returns null on unknown type
//Will be used to construct tasks objects
Task * taskFromType(string type)
{
	Task * t = 0;

	if (type == "G")
	{
	t = new Task(); //Separate memory space for construct Task 
	}
	else
	if (type == "H")
	{
	t = new HomeworkTask();  //Separate memory for construct HomeworkTask
	}
	else
	if (type == "S")
	{
	t = new ShoppingTask(); //Separate memory for construct ShoppingTask
	}
	else
	if (type == "E")
	{
	t = new EventTask(); //Separate memory for construct EventTask
	}

	return t;
}

//Used to pass word from lowercase to uppercase
void toUpper(string & str)
{
	for(unsigned int i=0;i<str.size();i++)
		str[i] = toupper(str[i]);
}

//Used to return count of objets of specific state (completed or not)
//Will be used also to locate and REMOVE tasks by its number position.
unsigned int getCount(SortedLinkedList & lst, bool completed)
{
	SortedLinkedListItem * ptr = lst.Next(0);

	unsigned int count = 0;

	while (ptr)
	{
		if (lst.Get(ptr)->isCompleted() == completed)
		{
			count++;
		}

		ptr = lst.Next(ptr);
	}

	return count;
}

//Used to get object by its index (of specified type)
SortedLinkedListItem * getByIndex(SortedLinkedList & lst, bool completed, unsigned int index)
{
	SortedLinkedListItem * ptr = lst.Next(0);

	while (ptr)
	{
		if (lst.Get(ptr)->isCompleted() == completed)
		{
			if (!index)
				return ptr;
			index--;
		}

		ptr = lst.Next(ptr);
	}

	return 0;
}

//Used to load linked list tasks from a file
void load(SortedLinkedList & lst)
{
	lst.Free();
	string filename;
	cout << "What file would you like to load outstanding tasks from ? (Note: All existing tasks will be deleted)" << endl;
	getline(cin, filename);  //filename will be the file name to be search

	fstream fp(filename.c_str(), ios::in);  //use c_str() to look for filename

	if (fp.good())  //if filename is found it proceed to load all task by its type
	{

		while (true)
		{
			string row;
			getline(fp, row);
			if (fp.fail())break;//end of file

			stringstream str(row);
			string type;

			getline(str, type,'|');///use | as separator

			Task * t = taskFromType(type);
			if (!t)
				continue;//bad line

			t->read(str);

			lst.Add(t);
		}

		cout << "Tasks loaded successfully!" << endl;
	}
	else
		cout << "Tasks not loaded!" << endl;
}


//Used to save linked list to a file
void save(SortedLinkedList & lst)
{
	int count = getCount(lst, false);

	if (count == 0)
	{
		cout << "You have no outstanding tasks!" << endl;
		return;
	}

	string filename;
	cout << "Where would you like to save your outstanding tasks?" << endl;
	getline(cin, filename); //filename will be now the name chosen for the file

	fstream fp(filename.c_str(),ios::out); //use c_str() to name the file

	if(fp.good()) //if no problems with the filename chosen proceed to save tasks
	{
		SortedLinkedListItem * ptr = lst.Next(0);

		while (ptr) //ptr will traverse all the linked list
		{
			if (lst.Get(ptr)->isCompleted() == false)
			{
				lst.Get(ptr)->write(fp); //get the info to be save
				fp << endl;
			}

			ptr = lst.Next(ptr);
		}
		cout << "Tasks saved successfully!" << endl;
	}
	else
	cout << "Tasks not saved!" << endl;

}


//Used to erase (REMOVE) a not completed task by its number
void erase(SortedLinkedList & lst)
{
	unsigned int count = getCount(lst, false);

	if (count == 0)
	{
		cout << "You have no outstanding tasks!" << endl;
		return;
	}

	while (true)
	{
		unsigned int taskNo;
		cout << "Which task would you like to remove?" << endl;
		cin >> taskNo;
		if (cin.fail())
		{
			cin.ignore(80, '\n');
			cout << "Enter a positive integer 1 to " << count << endl;
			continue;
		}
		if (taskNo == 0 || taskNo > count) //Must be in range of counted tasks
		{
			cout << "Enter a positive integer 1 to " << count << endl;
			continue;
		}

		unsigned int index = taskNo - 1; //The rest of index must decrease by 1
		SortedLinkedListItem * ptr = getByIndex(lst, false, index);

		lst.Remove(ptr);

		cout << "Task removed successfully." << endl;

		break;
	}
}


///Used to indicate complete a not completed task by number
void complete(SortedLinkedList & lst)
{
	unsigned int count = getCount(lst, false);

	if (count == 0)
	{
		cout << "You have no outstanding tasks!" << endl;
		return;
	}


        //Loop while used to locate, mark as completed the task and rename the
        //rest of index in the linked list
	while (true)
	{
		unsigned int taskNo;
		cout << "Which task would you like to complete??" << endl;
		cin >> taskNo;
		if (cin.fail())
		{
			cin.ignore(80, '\n');
			cout << "Enter a positive integer 1 to " << count << endl;
			continue;
		}
		if (taskNo == 0 || taskNo > count) //Must be in range of counted tasks
		{
			cout << "Enter a positive integer 1 to " << count << endl;
			continue;
		}

		unsigned int index = taskNo - 1;
		SortedLinkedListItem * ptr = getByIndex(lst, false, index);

		lst.Get(ptr)->complete();

		cout << "Task marked complete successfully." << endl;

		break;
	}
}


//Used to print tasks (completed or not, detialed or not )
void print(SortedLinkedList & lst, bool completed, bool detailed)
{
	SortedLinkedListItem * ptr = lst.Next(0);

	unsigned int index = 1;

	while (ptr)
	{
		//cout  <<ptr->prev <<" "<< ptr<<" "<<ptr->next<<" | " ;
		if (lst.Get(ptr)->isCompleted() == completed)
		{
			cout << index << ". ";  // 1. (Get(ptr)) will complete info
			lst.Get(ptr)->output(detailed); //to display as not detailed 
			index++;
		}

		ptr = lst.Next(ptr);
	}

	if (index==1)
	{
		if (completed)
			cout << "You have no completed tasks!" << endl;
		else
			cout << "You have no outstanding tasks!" << endl;

	}

}


///Used to add task, SortedLinkedList class inherits Task and this one inherits Date
void add(SortedLinkedList & lst)
{

	while (true)
	{
		cout << "What type of task is this ? [G:Generic, S : Shopping, E : Event, H : Homework]" << endl;
		string type;
		getline(cin, type);
		toUpper(type);

		Task * t = taskFromType(type);

		if(!t) //type must be G, S, E or H, toUpper(type) guarantee uppercase
		{
			cout << "Bad type" << endl; //Case not enter the correct letter
			continue;                   //while loop restart asking What type
		}                                   //of task is this?[G:Generic.....

		t->input(); //Start input information about the task, add and exit 
                            //the while loop
		lst.Add(t);

		break;
	}

}

int main( int angc , const char *argv[])
{
	SortedLinkedList tasks;


	//Main loop, read in out, execute commands...
	while (1)
	{
		string action;
		getline(cin,action);
		toUpper(action);

		if (action == "EXIT") //Only typing EXIT let us exit the loop
		{
			break;
		}
		else
		if (action == "ADD")
		{
			add(tasks);
		}
		else
		if (action == "PRINT")
		{
			print(tasks, false, false);  //print(tasks,complete?,detailed?)
		}
		else
		if (action == "DETAILED")
		{
			print(tasks, false, true);
		}
		else
		if (action == "COMPLETED")
		{
			print(tasks, true, false);
		}
		else
		if (action == "SAVE")
		{
			save(tasks);
		}
		else
		if (action == "LOAD")
		{
			load(tasks);
		}
		else
		if (action == "COMPLETE")
		{
			complete(tasks);
		}
		else
		if (action == "REMOVE")//ERASE")
		{
			erase(tasks);
		}

	}

	cout << "Thank you for using To-Do List!" << endl; //...after type EXIT

	return 0;
}
