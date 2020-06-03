/***************************************************************************
Title:		HomeworkTask.cpp
Author:		Jose Luis Rojas-Salazar
Date Created:	3/30/2017
Class:		Spring 2017, CSCI 235-03, Mon & Wed 7:00pm-8:15pm
Professor:	Aarsh Vora
Purpose:	Assigment #2
Description:	Implementation of class HomeworkTask (HomeworkTask.cpp)
****************************************************************************/


#include "HomeworkTask.h"

using namespace std;


HomeworkTask::HomeworkTask()
{
}


HomeworkTask::~HomeworkTask()
{
}

//Will show between [] word [Homework] when the task is displayed on screen when
//call command PRINT
string HomeworkTask::typeStr()
{
	return "Homework";
}


//Will put letter H at start of the line in the Task File Format
char HomeworkTask::type()
{
	return 'H';
}


//Will show detail on screen of the Homework task, first call generic Task part
//and then will complement with name of SUBJECT if DETAILED command is used.
void HomeworkTask::output(bool detailed)
{
	Task::output(detailed);

	if (detailed)
	{
		cout << "    SUBJECT: "<<subject << endl;
	}

}

//To input data in the Homework node, first input the data about generic Task, after
//that prompt to enter the subject string.
void HomeworkTask::input()
{
	Task::input();
	cout << "What subject is this homework task for ?" << endl;
	getline(cin, subject);
	cout << "Task added successfully" << endl;

}

//Used to write the HomeworkTask in a file.
void HomeworkTask::write(std::ostream & str)
{
	Task::write(str);

	str << "|" << subject;
}

//Used to read the HomeworkTask from a file.
void HomeworkTask::read(std::istream & str)
{
	Task::read(str);
	getline(str, subject, '|');///use | as separator

}

