/***************************************************************************
Title:		ShoppingTask.cpp
Author:		Jose Luis Rojas-Salazar
Date Created:	3/30/2017
Class:		Spring 2017, CSCI 235-03, Mon & Wed 7:00pm-8:15pm
Professor:	Aarsh Vora
Purpose:	Assigment #2
Description:	Implementation of class ShoppingTask (ShoppingTask.cpp)
****************************************************************************/


#include "ShoppingTask.h"

using namespace std;

ShoppingTask::ShoppingTask()
{
}


ShoppingTask::~ShoppingTask()
{
}


//Show between [] the word [Shopping] when use the command PRINT or DETAILED to show
//the tasks on screen.
std::string ShoppingTask::typeStr()
{
	return "Shopping";
}

//Type letter S at the start of the tasks lines on Tasks File Format. 
char ShoppingTask::type()
{
	return 'S';
}

//Used to read the ShoppingTask from a file
void ShoppingTask::read(std::istream & str)
{
	Task::read(str);
	getline(str, products);///read all till end of stream
}

//Used to write to a file the info of ShoppingTask
void ShoppingTask::write(std::ostream & str)
{
	Task::write(str);

	str << "|" << products;
}

//Used to input the data for the node ShoppingTask in the LinkedList. First call the
//input() function from the generic task and after that load the list of products
//until enter DONE.  
void ShoppingTask::input()
{
	Task::input();

	cout << "What items do you need to buy ? [Type your item and press ENTER to add another item.Type DONE to complete the list.]"<<endl;

	while (true)
	{//put all products in a stirng, separated by |
		string product;
		getline(cin,product);

		if (product == "DONE"){///DONE input indicate end of input products
			cout << "Task added successfully." <<endl;
			break;
			}

		if (product == "")//skipe empty products
			continue;

		if (products.size())
			products += "|" + product;
		else
			products = product;

	}
}

//Used to show on screen the data from ShoppingTask, first use the output() function
//to show generic information from Task class, then if is DETAILED will show the list of
//products entered using input() function.
void ShoppingTask::output(bool detailed)
{
	Task::output(detailed);
	
	if (detailed)
	{
		cout << "ITEMS TO PURCHASE:" << endl;

		//we need to separete products for printing on new line each one
		size_t startpos = 0;//trt from startpos
		while (true)
		{//put all products in a string, separated by |

			size_t pos = products.find('|', startpos);
			bool last = false;
			string part;

			if (pos != string::npos)
			{//get substriing from current pos to | character
				size_t len = pos - startpos;
				part = products.substr(startpos, len);
				startpos = pos + 1;//go to next part
			}
			else
			{//no more |, this is last part
				part = products.substr(startpos);
				last = true;
			}

			cout << "    "<<part << endl;

			if (last)
				break;
		}
	}
}
