#include <iostream>
#include <array>
#include "TemplateStruct.h"
int main()
{
	Templates a;
	Stack<int> *arr = new Stack<int>(5);

	for (int i = 0; i < 7; i++)
	{
		arr->push(i);
	}
	for (int i = 0; i < 8; i++)
	{
	  std::cout <<  arr->pop() << std::endl;
	}

	system("pause");
	delete arr;
	return 0;
}

