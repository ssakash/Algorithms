#include "Common.h"
#include "Sorting.h"


int main()
{
	int x;
	std::cout << "Which sorting do you want to do?" << "\n1/ Insertion Sort\n";
	std::cin >> x;

	Sorting program(static_cast<sorting_method>(x));
	program.Sort();
	program.PrintResult();

	SYSTEM_PAUSE();
	return 0;
}