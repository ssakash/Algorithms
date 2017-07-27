#pragma once
#include "Common.h"

enum class sorting_method : int
{
	InsertionSort = 1
};

class Sorting
{
private:
	sorting_method m_method;
	PerformanceMonitor m_monitor;
	std::vector<int> m_storage;

public:
	Sorting(sorting_method method)
	{
		m_method = method;
	}
	void Sort();
	void PrintResult();


	//                 //
	// SORTING METHODS // 
	//                 //
	static void InsertionSort(std::vector<int>& input);
};