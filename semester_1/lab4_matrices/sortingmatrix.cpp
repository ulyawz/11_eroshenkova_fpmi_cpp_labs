#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
int** CreateMatrix(int rows, int columns) {
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
    }
    return matrix;
}
void DeleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
void PrintMatrix(int** matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}
bool comp(int a, int b, bool ascending) {
    if (ascending) {
        return a < b;
    }
    else {
        return a > b;
    }
}
void BubbleSort(int* matrix, int size, bool ascending) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (comp(matrix[j + 1], matrix[j], ascending)) {
                std::swap(matrix[j], matrix[j + 1]);
            }
        }
    }
}
void InsertionSort(int* matrix, int size, bool ascending) {
    for (int i = 1; i < size; i++) {
        int key = matrix[i];
        int j = i - 1;

        while (j >= 0 && comp(key, matrix[j], ascending)) {
            matrix[j + 1] = matrix[j];
            j--;
        }
        matrix[j + 1] = key;
    }
}
void Merge(int* matrix, int left, int mid, int right, bool ascending) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; i++)
        L[i] = matrix[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = matrix[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (comp(L[i], R[j], ascending)) {
            matrix[k] = L[i];
            i++;
        }
        else {
            matrix[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        matrix[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        matrix[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}
void MergeSort(int* matrix, int left, int right, bool ascending) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    MergeSort(matrix, left, mid, ascending);
    MergeSort(matrix, mid + 1, right, ascending);
    Merge(matrix, left, mid, right, ascending);
}
void SelectionSort(int* matrix, int size, bool ascending) {
    for (int i = 0; i < size - 1; i++) {
        int extreme_index = i;
        for (int j = i + 1; j < size; j++) {
            if (comp(matrix[j], matrix[extreme_index], ascending)) {
                extreme_index = j;
            }
        }
        std::swap(matrix[i], matrix[extreme_index]);
    }
}
void SortMatrixRows(int** matrix, int rows, int columns, int sortType, bool ascending) {
    for (int i = 0; i < rows; i++) {
        switch (sortType) {
        case 1:
            BubbleSort(matrix[i], columns, ascending);
            break;
        case 2:
            InsertionSort(matrix[i], columns, ascending);
            break;
        case 3:
            MergeSort(matrix[i], 0, columns - 1, ascending);
            break;
        case 4:
            SelectionSort(matrix[i], columns, ascending);
            break;
        }
    }
}

int main() {
    int rows, columns;
    std::cout << "Enter the number of columns: ";
    std::cin >> columns;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;

    int** matrix = CreateMatrix(rows, columns);

    std::cout << "Enter 1 if the elements of array are entered by hand" << std::endl
        << "Enter 2, if the elements of array are entered randomly: ";
    int choice;
    std::cin >> choice;
    srand(time(0));
    if (choice == 1) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                std::cout << "Enter element [" << i << "][" << j << "]: ";
                std::cin >> matrix[i][j];
            }
        }
    }
    else if (choice == 2) {
        int lower_board, upper_board;
        std::cout << "Enter the lower bound of array: ";
        std::cin >> lower_board;
        std::cout << "Enter the upper bound of array: ";
        std::cin >> upper_board;

        if (lower_board > upper_board) {
            std::swap(lower_board, upper_board);
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrix[i][j] = lower_board + rand() % (upper_board - lower_board + 1);
            }
        }
    }
    else {
        std::cout << "ONLY 1 OR 2 ALLOWED!";
        DeleteMatrix(matrix, rows);
        return 0;
    }
    std::cout << "\nOriginal matrix:" << std::endl;
    PrintMatrix(matrix, rows, columns);
    std::cout << "\nChoose sorting algorithm:" << std::endl;
    std::cout << "1 - Bubble Sort" << std::endl;
    std::cout << "2 - Insertion Sort" << std::endl;
    std::cout << "3 - Merge Sort" << std::endl;
    std::cout << "4 - Selection Sort" << std::endl;
    std::cout << "Enter your choice: ";
    int sortChoice;
    std::cin >> sortChoice;
    if (sortChoice < 1 || sortChoice > 5) {
        std::cout << "Invalid sorting choice!" << std::endl;
        DeleteMatrix(matrix, rows);
        return 0;
    }
    std::cout << "Choose sorting order:" << std::endl;
    std::cout << "1 - Ascending" << std::endl;
    std::cout << "2 - Descending" << std::endl;
    std::cout << "Enter your choice: ";
    int orderChoice;
    std::cin >> orderChoice;
    bool ascending = (orderChoice == 1);
    SortMatrixRows(matrix, rows, columns, sortChoice, ascending);
    std::cout << "\nSorted matrix:" << std::endl;
    PrintMatrix(matrix, rows, columns);
    DeleteMatrix(matrix, rows);
    return 0;
}