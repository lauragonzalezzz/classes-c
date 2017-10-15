// ClassesHomeworkC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ListOfInt.h"


int main()
{
	ListOfInt myList;
	myList.Add(1);
	myList.Clear();
	myList.Add(2);
	myList.Add(17);
	myList.Add(1);
	myList.Sort();
	unsigned int test = myList.GetAtPosition(0);
	myList.Add(4);
	test = myList.GetAtPosition(2);
	myList.Remove(2);
	test = myList.GetAtPosition(2);
	myList.Clear();
	return 0;
}