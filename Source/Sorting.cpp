#pragma once
#include "Sorting.h"

void Sorting::Sort()
{
	int n;
	std::vector<int> input;

	std::cout << "How much numbers do you want to sort? ";
	std::cin >> n;

	std::cout << "\n\nPlease provide all the numbers which need to be sorted:\n";
	while (n--)
	{
		int x;
		std::cin >> x;
		input.push_back(x);
	}
	m_storage = input;

	switch (m_method)
	{
	case sorting_method::InsertionSort:
		m_monitor.StartProfiling();
		InsertionSort(m_storage);
		break;
	default:
		std::cout << "Unknown input recieved";
	}
	m_monitor.StopProfiling();
}

void Sorting::PrintResult()
{
	std::cout << "\nThe sorted values are,\n";
	for (const int& i : m_storage)
		std::cout << i << " ";
}