// INSERTION SORT:
//
// Insertion sort is a simple sorting algorithm that builds the final sorted array (or list) one item at a time.
// It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.
// 
//  At this example, we'll be using insertion sort on an array.
// I know the max limit and stupid array sucks, I'll try to make it better when I get more free time.


#include <iostream>
#include "Common.h"
#include "PerformanceMonitor.h"

enum class operation : int
{
	AscendingSortion =1,
	DescendingSortion,
	Print,
	Exit
};

int InsertionSort()
{
	PerformanceMonitor monitor;
	int a[25];
	int elements;
	int op;
	CLEAR_SCREEN();
	std::cout << "\n\nProvide the number of elements of the array (Maximum:25): ";
	std::cin >> elements;

	std::cout << "\n";
	for (int i = 0; i < elements; i++)
	{
		std::cout << "\n Provide value of element[" << i+1 << "] :";
		std::cin >> a[i];
	}

	do {
		std::cout << "\n\nWhat operation do you want to perform?";
		std::cout << "\n 1. Ascending sortion";
		std::cout << "\n 2. Descending sortion";
		std::cout << "\n 3. Print Elements";
		std::cout << "\n 4. Exit\n";
		std::cin >> op;

		monitor.StartProfiling();
		switch (static_cast<operation>(op))
		{
			case operation::AscendingSortion:
			{
				int key, index;
				for (int i = 1; i < elements; i++)
				{
					key = a[i];
					index = i - 1;

					while (index >= 0 && a[index] > key)
					{
						a[index + 1] = a[index];
						index--;
					}
					a[index + 1] = key;
				}
			} break;

			case operation::DescendingSortion:
			{
				int key, index;
				for (int i = 1; i < elements; i++)
				{
					key = a[i];
					index = i - 1;

					while (index >= 0 && a[index] < key)
					{
						a[index + 1] = a[index];
						index--;
					}
					a[index + 1] = key;
				}
			} break;

			case operation::Print:
			{
				for (int i = 0; i < elements; i++)
					std::cout << "Element[" << i << "] : " << a[i] <<"\n";
			} break;
			case operation::Exit: break;
			default:
				std::cout << "Unknown command detcted!\n";
		}
		monitor.StopProfiling();
	} while (static_cast<operation>(op) != operation::Exit);
	return 0;
}