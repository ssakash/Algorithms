#include "../Sorting.h"

//                 //
//  INSERTION SORT //
//                 //

/*
Insertion sort always takes 'n - 1' number of passes to complete a sorting operation.
Let's see how it works with an example,

	Let's assume a series of 5 numbers { 2, 4, 1, 5, 3}
	First pass:  2 4 1 5 3  ( No change to 4 is it's greater than 2)
	second pass: 1 2 4 5 3  ( 1 has been moved to left as it's lower than 2 and 4)
	third pass:  1 2 4 5 3  ( No change sa 5 is greater than 1, 2 and 4) 
	fourth pass: 1 2 3 4 5  ( 3 has been moved to left of 4 and 5)

	Hence, insertion sort is done.
*/
void Sorting::InsertionSort(std::vector<int>& input)
{
	int key;
	for (int j = 1; j < input.size(); j++)
	{
		int i = j - 1;
		key = input[j];

		while (i >= 0 && input[i] > key)
		{
			input[i + 1] = input[i];
			i--;
		}
		input[i + 1] = key;
	}
}