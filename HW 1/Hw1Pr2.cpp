/* Arnaldo A Villarral
	CSCE 221-510
	HW 1 #2 code
	01-26-13
*/

#include <iostream>

int main()
{
	int size;
	int operations = 0;
	int total = 0;

	std::cout << "Please specify the size of the n x n array you wish to create: " << '\n';
	std::cin >> size;

	int Matrix[size][size];

	std::cout << "Now computing # of operations for sum of all elements " << '\n';

	for(int i = 0; i < size - 1; i++)
	{
		for(int j = 0; j < size - 1; j++)
		{
				total+= Matrix[i][j];
				operations = operations + 1;
		}

	}

	std::cout << "Total number of operations: " << operations - 1<< '\n';
}