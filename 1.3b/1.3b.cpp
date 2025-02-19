#include "Header1.3b.h"

int main()
{
	const int SIZE = 10;
	double array[SIZE]{ 0 };
	bool is_fib = 0;
	short choice;

	enum enmArrayInit { WithConst = 1, WithRand, ByUser, };

menu:
	std::cout << "choose the way to initialize the array:" << std::endl;
	std::cout << WithConst << " the elements are initialized with prescribed constants" << std::endl;
	std::cout << WithRand << " the elements are initialized with random numbers" << std::endl;
	std::cout << ByUser << " the elements are initialized by the user" << std::endl;

	std::cin >> choice;

	switch (choice)
	{
	case WithConst:
	{
		break;
	}
	case WithRand:
	{
		InitArrayWithRand(array, SIZE);
		break;
	}
	case ByUser:
	{
		InitArrayByUser(array, SIZE);
		break;
	}
	default:
	{
		std::cout << "invalid value entered, try again" << std::endl;
		goto menu;
	}
	}
	
	OutputArray(array, SIZE);
	double max_num = FindMaxFib(array, SIZE, is_fib);
	
	if (is_fib)
		std::cout << "Max Fibonacci number in the array: " << max_num << std::endl;
	else 
	{
		std::cout << "There are no Fibonacci numbers in array" << std::endl;
		std::cout << "Max number in the array: " << max_num << std::endl;
	}
		
	FindMaxFib(array, SIZE, is_fib) = 0;
	OutputArray(array, SIZE);
}