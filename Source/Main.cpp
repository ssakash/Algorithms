#include "Main.h"
#include <iostream>

int main()
{
	std::cout << "Which program do you want to execute?\n";
	std::cout << "1. Linked List\n";

	int choice;
	std::cin >> choice;

	if (choice == 1)
		LinkedList();

	return 0;
}