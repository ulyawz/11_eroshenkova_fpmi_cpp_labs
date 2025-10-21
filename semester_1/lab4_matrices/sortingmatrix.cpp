#include <iostream>
#include<iomanip>
void SortBubble(int** arr, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns - 1; j++) {
            for (int k = 0; k < columns - j - 1; k++) {
                if (arr[i][k] > arr[i][k + 1]) {
                    std::swap(arr[i][k], arr[i][k + 1]);
                }
            }
        }
    }
}
void SortInsert(int** arr, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 1; j < columns; j++) {
            int key = arr[i][j];
            int k = j - 1;
            while (k >= 0 && arr[i][k] > key) {
                arr[i][k + 1] = arr[i][k];
                k--;
            }
            arr[i][k + 1] = key;
        }
    }
}
void merge(int** arr, int rows, int columns, int k, int** temp) {
    int t = rows;
    int i = columns;
    int j = rows;
    for (int g = 0; g < rows; g++)
    {
        int t = rows;
        int i = columns;
        int j = rows;
        while ((t < columns) && (i < k))
            if (arr[g][t] <= arr[g][i])
            {
                temp[g][k] = arr[g][t];
                t++;
            }
            else {
                temp[g][k] = arr[g][i];
                i++;
            }
        while (t < columns)
            temp[g][k] = arr[g][t];
        t++; k++;
        while (i < k)
            temp[g][k] = arr[g][i];
        i++; k++;
    }

}
void SortMerge(int** arr, int left, int right, int** temp)
{
    if (right - left <= 1) return;
    int mid = (left + right) / 2;
    SortMerge(arr, left, mid, temp);
    SortMerge(arr, mid, right, temp);
    merge(arr, left, mid, right, temp);
}

int main()
{
    int** arr;
    int rows, columns;
    int lower_board, upper_board, change, choice;

    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> columns;

    if (rows <= 0 || rows > 1000 || columns <= 0 || columns > 1000) return 0;
    arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[columns];
    }
    std::cout << "Enter 1 if the elements of array are entered randomly" << std::endl
        << "Enter 2 if the elements of array are entered by hand: ";
    std::cin >> choice;

    if (choice == 2) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                std::cout << "enter the element arr[" << i << "][" << j << "]: ";
                std::cin >> arr[i][j];
            }
        }
    }
    else if (choice == 1) {
        std::cout << "Enter the lower bound of array: ";
        std::cin >> lower_board;
        std::cout << "Enter the upper bound of array: ";
        std::cin >> upper_board;
        if (lower_board > upper_board) {
            change = lower_board;
            lower_board = upper_board;
            upper_board = change;
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                arr[i][j] = lower_board + rand() % (upper_board - lower_board + 1);
            }
        }
    }
    else {
        std::cout << "ONLY 1 OR 0";
        for (int i = 0; i < rows; i++) {
            delete[] arr[i];
        }
        delete[] arr;
        return 0;
    }
    std::cout << "Original array:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << std::setw(3) << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Choose type of sort:" << std::endl;
    std::cout << "1) bubble\n" << "2) insert\n" << "3) merge\n";
    int choicesort;
    std::cin >> choicesort;
    switch (choicesort) {
    case 1:
        SortBubble(arr, rows, columns);
        break;
    case 2:
        SortInsert(arr, rows, columns);
        break;
    }
    std::cout << "Sorted array:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << std::setw(3) << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
