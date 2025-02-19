#include "Header1.1b.h"

void InitMatrix(int* matrix[], int size_matrix, int max_size)
{
	int value = 1;
	int* piBegin = &matrix[0][0];
	int* piEnd = piBegin + max_size * size_matrix;

	for (int* piLine = piBegin; piLine < piEnd; piLine += max_size)
	{
		for (int* piI = piLine; piI < piLine + size_matrix; piI++)
			*piI = value++;
		std::cout << std::endl;
	}

}

void OutputMatrix(int* matrix[], int size_matrix, int max_size)
{
	int* piBegin = &matrix[0][0];
	int* piEnd = piBegin + max_size * size_matrix;

	for (int* piLine = piBegin; piLine < piEnd; piLine += max_size)
	{
		for (int* piI = piLine; piI < piLine + size_matrix; piI++)
			std::cout << std::setw(5) << *piI;
		std::cout << std::endl;
	}
	std::cout << "\n";
}

void FillSpiralMatrix(int* matrix[], int size, int MAX_SIZE)
{
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
}

//int value = 1;
//int* ptr;
//int left = 0, right = size - 1, top = 0, bottom = size - 1;
//
//while (value <= size * size)
//{
//	ptr = &matrix[bottom][left];
//	for (int i = left; i <= right; i++)
//		*(ptr + i - left) = value++;
//	bottom--;
//
//	ptr = &matrix[bottom][right];
//	for (int i = bottom; i >= top; i--)
//		*(ptr - (bottom - i) * max_size) = value++;
//	right--;
//
//	ptr = &matrix[top][right];
//	for (int i = right; i >= left; i--)
//		*(ptr - (right - i)) = value++;
//	top++;
//
//	ptr = &matrix[top][left];
//	for (int i = top; i <= bottom; i++)
//		*(ptr + (i - top) * max_size) = value++;
//	left++;
//}
