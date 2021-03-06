// ClassTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "Pragmahead.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	char input = ' ';
	PragmaClass *testClass = new PragmaClass();

	while (input != 'q')
	{
		cout << "Press a or s" << "\n";

		cin >> input;

		if (input == 'a')
		{
			string number;
			try
			{
				cout << "Enter a number " << "\n";
				cin >> number;
				auto const temp = stoi(number);
				testClass->addItem(temp);
			}
			catch(const std::exception &e)
			{
				cout << e.what() << "\n";
				system("pause");
				return 1;
				
			}
		}

		if (input == 's')
		{
			testClass->print();
		}
	}
	delete testClass;

	system("pause");
	return 0;
}

int error()
{
	cout << "Error occurred" << "\n";
	system("pause");
	return 1;
}

void PragmaClass::addItem(int i)
{

	if (addedNumbers >= 10)
	{
		cout << "ARRAY IS FULL " << "\n";
		error();
		return;
	}
	
	for (int i = 0; i < addedNumbers; i++)
	{
		C_array++;
	}

	*C_array = i;

	for (int i = 0; i < addedNumbers; i++)
	{
		C_array--;
	}

	addedNumbers++;
}

PragmaClass::PragmaClass()
{ 
	// C implementation
	//C_array = (int *)malloc(10 * sizeof(int));

	//C++ implementation
	C_array = new int[10];
}

PragmaClass::~PragmaClass()
{
	cout << "Pragmaclass reference has been deconstructed" << "\n";
}

void PragmaClass::print()
{
	for (int i = 0; i < addedNumbers; i++)
	{
		cout << *(C_array + i) << "\n";
	}

	system("pause");
}

