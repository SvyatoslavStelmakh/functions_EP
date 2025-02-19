//#include <iostream>
//using namespace std;
//
//void fillSpiralMatrix(int n, int matrix[][100]) {
//    int value = 1;
//    int left = 0, right = n - 1, top = 0, bottom = n - 1;
//
//    while (value <= n * n) {
//        for (int i = left; i <= right; i++) matrix[bottom][i] = value++;
//        bottom--;
//
//        for (int i = bottom; i >= top; i--) matrix[i][right] = value++;
//        right--;
//
//        for (int i = right; i >= left; i--) matrix[top][i] = value++;
//        top++;
//
//        for (int i = top; i <= bottom; i++) matrix[i][left] = value++;
//        left++;
//    }
//}
//
//void printMatrix(int n, int matrix[][100]) {
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << matrix[i][j] << "\t";
//        }
//        cout << endl;
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "RU");
//    int n;
//    cout << "¬ведите размер матрицы: ";
//    cin >> n;
//
//    int matrix[100][100]; // ќграничение на 100x100
//    fillSpiralMatrix(n, matrix);
//    printMatrix(n, matrix);
//
//    return 0;
//}
#include <iostream>
using namespace std;

void fillSpiralMatrix(int n, int matrix[][100]) {
    int value = 1;
    int* ptr;
    int left = 0, right = n - 1, top = 0, bottom = n - 1;

    while (value <= n * n) 
    {
        ptr = &matrix[top][left];
        for (int i = left; i <= right; i++) 
            *(ptr + i - left) = value++;
        top++;

        ptr = &matrix[top][right];
        for (int i = top; i <= bottom; i++) 
            *(ptr + (i - top) * 100) = value++;
        right--;

        ptr = &matrix[bottom][right];
        for (int i = right; i >= left; i--) 
            *(ptr - (right - i)) = value++;
        bottom--;

        ptr = &matrix[bottom][left];
        for (int i = bottom; i >= top; i--) *(ptr - (bottom - i) * 100) = value++;
        left++;
    }
}

void printMatrix(int n, int matrix[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << *(&matrix[i][j]) << "\t";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RU");

    int n;
    cout << "¬ведите размер матрицы: ";
    cin >> n;

    int matrix[100][100]; // ќграничение на 100x100
    fillSpiralMatrix(n, matrix);
    printMatrix(n, matrix);

    return 0;
}


