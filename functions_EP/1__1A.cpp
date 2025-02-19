#include <iostream>
#include <climits> 
#include <cmath>

int main()
{
	/*double number = 100, highest_degree = 0;

	highest_degree = (0.5 * log10(INT_MAX));

	std::cout << "Highest degree = " << highest_degree << std::endl;*/

	unsigned long long factorial = 1;
	int number = 0;
		
	do
	{
		if (factorial * (number + 1) > UINT_MAX)
			break;
		number++;
		factorial = 1;
		for (int i = 1; i <= number; ++i)
		{
			factorial *= i;
		}
		
	} while (factorial < UINT_MAX);
	
	std::cout << factorial << std::endl;
	std::cout << number;
}
