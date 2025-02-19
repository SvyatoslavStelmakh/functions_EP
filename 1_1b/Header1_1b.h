#pragma once
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

void InitMatrix(int* matrix[], int size_matrix, int max_size);
void OutputMatrix(int* matrix[], int size_matrix, int max_size);
void FillSpiralMatrix(int* matrix[], int size, int max_size);