#include "Header1.3b.h"

void InitArrayWithRand(double array[], int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; ++i)
	{
		array[i] = rand() % 1000 + 1;
	}
}

void InitArrayByUser(double array[], int size)
{
	for (int index = 0; index < size; index++)
	{
		std::cout << "enter " << index << " element ";
		std::cin >> array[index];
	}
}

void OutputArray(double array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << " " << array[i];
	}

	std::cout << std::endl;
}

double& FindMaxFib(double array[], int size, bool& is_fib)
{
	is_fib = 0;
	int fib_max = 0;
	int max = array[0];
	int a = 0, b = 1;
	for (int i = 0; i < size; i++)
	{
		while (b < array[i])
		{
			int temp = b;
			b = a + b;
			a = temp;
		}
		is_fib = b == array[i] ? 1 : 0;
		if (is_fib)
		{
			if (array[i] >= array[fib_max])
			{
				fib_max = i;
			}
		}

		if (array[i] > array[max])
			max = i;
		a = 0, b = 1;
	}
	
	if (fib_max == 0)
		return array[max];
	else
	{
		is_fib = 1;
		return array[fib_max];
	}
		
	
}
