# CSCI235-LinkedList
/***************************************************************************
Title:		README.txt
Author:		Jose Luis Rojas-Salazar
Date Created:	4/3/2017
Class:		Spring 2017, CSCI 235-03, Mon & Wed 7:00pm-8:15pm
Professor:	Aarsh Vora
Purpose:	Assigment #2
Description:	Detail about
		-Built instructions for your makefile.
		-Parts complete and parts incomplete.
		-Description of known bugs.
		-Report on how youir project works, and explanations of your
		 algorithms and class structure. 
****************************************************************************/

CSCI235-Software Analysis & Design II
Assigment #2

-Built instructions for your makefile.

1. Compile with make
$ make

g++ -Wall -g -c main.cpp
g++ -Wall -g -c Date.cpp
g++ -Wall -g -c Task.cpp
g++ -Wall -g -c SortedLinkedList.cpp
g++ -Wall -g -c HomeworkTask.cpp
g++ -Wall -g -c EventTask.cpp
g++ -Wall -g -c ShoppingTask.cpp

g++ -Wall -g main.o Date.o Task.o SortedLinkedList.o HomeworkTask.o EventTask.o ShoppingTask.o   -o main

2. Run
To run it, use the main program.
$ ./main

NOTE: During the testings I used the following command to compile:
g++ *.cpp -o test

To run use:
./test


- Parts complete and parts incomplete:

	The tasks generic, homework, event and shopping were coded to be objects so were implemented using classes that inherit another class like Date that will be used to sort or order the list of tasks by date at the moment that they are added to the list.The classes mentioned were finished and tested.

	The commands ADD, PRINT, DETAILED, REMOVE, COMPLETE, COMPLETED, SAVE, LOAD, SAVE, LOAD AND EXIT can be call and executed from main.cpp file all of them were tested and work. 

- Description of known bugs:

	Try to use templates at first instance with the classes Task and Date but start to giving a lot of errors at the time to complile the first test. The list of errors are so large to be copy and paste, similar case when I tried to use templates with the Vector-Set first assigment extention and post it on piazza, so I decided to not use for the moment templates due the time to finish the project.

	At the first moment use integers to set the elements day, month and year drom Date class but in the format must appear '/' as separator between day, month and year. So a better idea to input and display the date is as a string and to manipulate each element, to do that I use stringstream or <sstream>, the idea was taken from stackoverflow.com. Sometimes is very convenient to use stringstream to convert between strings and other numerical types.The usage of stringstream are much the same with iostream.

str() returns the contents of its buffer in string type.
str(string) set the contents of the buffer with the string argument.

Using this way I can input day, month and year as strings, use char '/' as separator when display it and use overload operators <, = to sort tasks by date.


- Report on how your project works, explanations of your algorithms and class structure

The main idea or the big picture to built the project 2 was this:

	The project start from 0, there are no tasks in the list, they must be created or loaded from a file.

	There are 4 different types of tasks: One generic and 3 with specifications added to the kind generic. The Homework, Shopping and Event tasks inherits the Generic task that inherits the Date class to be used to sort the tasks so they are objects that have the following structure or class blueprint:

                 string  string  string
Date           /  d    /  m    /  y    /

                  bool     Date     string   
Generic task   /complete?/ date / description /

                Generic  string
Homework task  /generic/subject/

                Generic  string string 
Event task     /generic/ where / when /

                Generic  string
Shopping task  /generic/products/

                  Generic 
SortedLinkedList /generic*/

	Homework, Event and Shopping task append another elements to the generic task:
Homework task appends the string subject.
Event task appends the string where and the string when.
Shoping task appends the strings products, one string product per line.

	At the moment to call each of these classes by defect first construct the object task assembly the generic task and then call the constructor for the unique elements for each one.

	For example for Homework task:

void HomeworkTask::input()
{
	Task::input();
	cout << "What subject is this homework task for ?" << endl;
	getline(cin, subject);
	cout << "Task added successfully" << endl;

	The line Task::input(); refers that first call the input for the elements of the generic task then after that cout to input the unique element or string member for the Homework task that is the subject.

	The first thing to input when create or add a task to the list is indicate what kind of task or object will be created, inherit to the task is the Date class, the object date following the Date class blueprint. So separate a dinamically allocated space in memory for the task depending of which task is. Not all must have the same number and size of elements, the size of strings elements are different and in Shopping task it is needed dynamic allocation of memory also for the list.

	The idea to hierarchy clases Date, Generic, Homework, Event, Shopping and SortedLinkedList was taken from the book 
"Introduction to Object Oriented Programing & C++"  
-Yashavant Kanethar
Page 248

	The task object created inherits Date class that have 3 string elements to manipulate to compare date starting with the year, following the month and finally the day, to do that I use stringstream and overload the operators <, =, > but in practice is more used the overloaded operator < because when sort the tasks by its date is only necessary to compare if is more recent or "before" that the other Task date pointed at the moment of sort by the SortedLinkedList class, thats the reason why is a function named before() that use the comparator < for date input in the Task class that will be used by SortedLinkedList that inherits Task class, at the moment of add a new Task. In other words when add a new Task the function Add() in the SortedLinkedList class will check the date input in the new task and compare with the dates of other task in the linked list that are traverse using a pointer until the date position based in its date is found and then is added.

	In the Date class:

bool Date::operator<(const Date& arg){
	return(
		(y<arg.y)||
		((y==arg.y)&&(m<arg.m))||
		((y==arg.y)&&(m==arg.m)&&(d<arg.d))
	      );
}

	... in the Task class: (Generic task)
 
bool Task::before(const Task& arg){
	return date<arg.date;
}

	For the SortedLinkedList class it is not necessary add, remove or modify information or elements of the task so it is basically a class to order the tasks nodes using pointers and evaluating if the date is before to the pointed task in the list:

void SortedLinkedList::Add(Task* task){
...
  if(!root||task->before(*root->task)) //using before() to check if must be located at first
...
  while(true){
	if(!pos->next||task->before(*pos->next->task)) //using before() to check if must
...                                                    //be located after current element  
}                                                      //pointed in the list.

	The idea how to use pointers to traverse, check and locate the place to insert the task during the sort each new node or task added to the list was taken from

"Starting out with C++"   Fifth Edition
-Tony Gaddis
Page 1007

"Data Abstraction and problem solving with C++"   Fourth Edition
-Frank M. Carrano
Page 184

	Once sorted, each task have functions that inherits from the Generic task so these functions must be virtual so can be used also by Homework, Event and Shopping classes:

virtual std::string typestr(); //to show if is Generic or special task on screen
virtual char type(); // Return the letter identifier for the task G,S,E,H
virtual void read(std::istream& str); //to read from a file
virtual void write(std::ostream& str); // to write or save to a file
virtual void input(); //to input the string detailing the task and the special details if is not a generic task.

	The idea to read and write a linked list by using a file was taken from
"Data Abstraction and problem solving with C++"   Fourth Edition
-Frank M. Carrano
Page 198

stackoverflow.com (Internet resource)
Reading data in from file and inserting into Linked List C++

	The functions to call and execute for the commands ADD, PRINT, DETAILED, REMOVE, COMPLETE, COMPLETED, SAVE, LOAD, and EXIT are implemented in the main.cpp file so this one must call the following classes in its header:

"SortedlinkedList.h" //due this one contains Generic task that contains Date class.
"HomeworkTask.h" // due this one contains the functions to Homework Task
"EventTask.h" // due this one contains the functions to Event Task
"ShoppingTask" // due this one contains the functions to Shopping Task

	Also will have functions to execute the commands mentioned above, create the tasks from given type, count and get object by its index.

	The function TaskFromType return a pointer Task that point to the space of memory separated to assembly the object of the class indicated by the letter used to be call:
G for Task (generic that include Date class)
H for HomeworkTask
S for ShoppingTask
E for EventTask
 
	The function getCount return count of objects (tasks) of specific state (completed or not) will be used to check if all tasks are saved to a file when use command SAVE.

	The function getByIndex will return a pointer SortedLinkedListItem will be used to remove a completed task and modify the number or index in the rest of tasks in the list.

	The function load will be used to load the list of tasks from a file. All undaved tasks will be deleted if LOAD is used.

	The function save will be used to save the list of tasks in a file, first check getCount if there is a task in the list if not will display "You have no outstanding tasks!" otherwise will start to traverse from the linked list saving the data from each object into the designed file checking with the count to ensure all were saved.

	The function erase will be used to remove an uncomplete task from the list, again will use the getCount function to check with the taskNo to locate the task by its index and once removed modify using a while loop the rest of the index in the next tasks decreasing their index number by 1.

	The function complete will be used to manually complete a not completed task by its index number. We use getCount function again to check if there are tasks in the list or if the index number entered (TaskNo) is a positive number less than the count value. Once found the task will be marked as complete using function complete().

	The function print will be used to display all outstanding task in order by its date so it will have a reference to SortedLinkedList as one of its parameter, an indication if is completed or if is a detailed task as Shopping.

	The function add will be used to insert a new task depending of its type, will use again a reference to SortedLinkedList class as it parameter due at the moment to add a new task the first thing to enter after select the type of task is its date so SortedLinkedList will use it to locate the task in the list at that moment and call the functions to construct it first the part as generic task and after that append the detailed parts if is a non generic task as Homework.
