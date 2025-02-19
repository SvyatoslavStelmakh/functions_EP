#include "Header1_1b.h"

int main()
{
	const int MAX_SIZE = 100;
	int size = 5;			//размеры массива
	std::cout << "Enter size of array: ";
	std::cin >> size;

	int matrix[MAX_SIZE][MAX_SIZE] = {};		//массив
	int* pmatrix[] = { matrix[0], matrix[1], matrix[2], matrix[3], matrix[4]};

	InitMatrix(pmatrix, size, MAX_SIZE);
	OutputMatrix(pmatrix, size, MAX_SIZE);
	FillSpiralMatrix(pmatrix, size, MAX_SIZE);
	OutputMatrix(pmatrix, size, MAX_SIZE);
}
