#include "Main.h"
#include <iostream>

void ExecuteProgram(Programs program)
{
	switch (program)
	{
	case Programs::LinkedList:
		LinkedList();
	default:
		std::cout << "Unknown program requested!";
	}
}

int main()
{
	std::cout << "Which program do you want to execute?\n";
	std::cout << "1. Linked List\n";

	int choice;
	std::cin >> choice;

	ExecuteProgram(static_cast<Programs>(choice));
	return 0;
}