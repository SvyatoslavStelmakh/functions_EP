#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	const int MAX_SIZE = 100;
	int size = 0;			//размеры массива
	std::cout << "Enter size of array: ";
	std::cin >> size;

	int matrix[MAX_SIZE][MAX_SIZE] = {};		//массив

	int value = 1;
	int* pLeftBottom = &matrix[size - 1][0];
	int* pRightBottom = &matrix[size - 1][size - 1];
	int* pRightTop = &matrix[0][size - 1];
	int* pLeftTop = &matrix[0][0];

	while (value <= size * size)
	{
		for (int* pI = pLeftBottom; pI <= pRightBottom; pI++)
			*pI = value++;
		pRightBottom -= MAX_SIZE;
		pLeftBottom -= MAX_SIZE;
		for (int* pI = pRightBottom; pI >= pRightTop; pI -= MAX_SIZE)
			*pI = value++;
		pRightTop--;
		pRightBottom--;
		for (int* pI = pRightTop; pI >= pLeftTop; pI--)
			*pI = value++;
		pLeftTop += MAX_SIZE;
		pRightTop += MAX_SIZE;
		for (int* pI = pLeftTop; pI <= pLeftBottom; pI += MAX_SIZE)
			*pI = value++;
		pLeftBottom++;
		pLeftTop++;
	}

	int* piBegin = &matrix[0][0];
	int* piEnd = piBegin + MAX_SIZE * size;

	for (int* piLine = piBegin; piLine < piEnd; piLine += MAX_SIZE)
	{
		for (int* piI = piLine; piI < piLine + size; piI++)
			std::cout << std::setw(5) << *piI;
		std::cout << std::endl;
	}
	std::cout << "\n";
}