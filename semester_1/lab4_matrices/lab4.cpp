#include <iostream>
#include <cstdlib>
#include <ctime>

int** CreateMatrix(int rows, int columns) {
    if (rows <= 0 || columns <= 0) {
        throw "Rows and columns must be positive numbers";
    }

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns];
    }
    return matrix;
}

void DeleteMatrix(int** matrix, int rows) {
    if (matrix == nullptr) {
        throw "Matrix pointer is null";
    }

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void PrintMatrix(int** matrix, int rows, int columns) {
    if (matrix == nullptr) {
        throw "Matrix pointer is null";
    }
    if (rows <= 0 || columns <= 0) {
        throw "Rows and columns must be positive numbers";
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int ColumnsWithoutFirst(int** matrix, int rows, int columns) {
    if (matrix == nullptr) {
        throw "Matrix pointer is null";
    }
    int first = matrix[0][0];
    int count = 0;
    for (int j = 0; j < columns; j++) {
        int found = 0;
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] == first) {
                found = 1;
            }
        }
        if (found == 0) count++;
    }
    return count;
}

int FindRowWithLongestSeries(int** matrix, int rows, int columns) {
    if (matrix == nullptr) {
        throw "Matrix pointer is null";
    }
    int maxSeries = 0;
    int rowIndexWithMaxSeries = 0;
    for (int i = 0; i < rows; i++) {
        int currentSeries = 1;
        int rowMaxCurrentSeries = 1;
        for (int j = 1; j < columns; j++) {
            if (matrix[i][j] == matrix[i][j - 1]) {
                currentSeries++;
            }
            else {
                if (currentSeries > rowMaxCurrentSeries)
                    rowMaxCurrentSeries = currentSeries;
                currentSeries = 1;
            }
        }
        if (currentSeries > rowMaxCurrentSeries)
            rowMaxCurrentSeries = currentSeries;
        if (rowMaxCurrentSeries > maxSeries) {
            maxSeries = rowMaxCurrentSeries;
            rowIndexWithMaxSeries = i;
        }
    }
    return rowIndexWithMaxSeries;
}

int main()
{
    try {
        int rows, columns;
        std::cout << "Enter the number of columns" << " ";
        std::cin >> columns;
        std::cout << "Enter the number of rows" << " ";
        std::cin >> rows;

        if (rows <= 0 || columns <= 0) {
            throw "Rows and columns must be positive numbers";
        }

        int** matrix = CreateMatrix(rows, columns);
        std::cout << "Enter 1 if the elements of array are entered by hand " << std::endl << "Enter 2, if the elements of array are entered randomly";
        int choice;
        srand(time(0));
        std::cin >> choice;

        if (choice == 1)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++) {
                    std::cout << "Enter element [" << (i + 1) << "," << (j + 1) << "]: ";
                    std::cin >> matrix[i][j];
                }
            }
            PrintMatrix(matrix, rows, columns);
        }
        else if (choice == 2)
        {
            int lower_board, upper_board;
            std::cout << "Enter the lower board of array";
            std::cin >> lower_board;
            std::cout << "Enter the upper board of array";
            std::cin >> upper_board;

            if (lower_board > upper_board)
            {
                int temp;
                temp = lower_board;
                lower_board = upper_board;
                upper_board = temp;
            }

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < columns; j++) {
                    matrix[i][j] = lower_board + rand() % (upper_board - lower_board + 1);
                }
            }
            PrintMatrix(matrix, rows, columns);
        }
        else
        {
            std::cout << "ONLY 1 OR 2";
            DeleteMatrix(matrix, rows);
            return 0;
        }

        std::cout << "The element of the first column and the first row: " << matrix[0][0] << std::endl;
        int count = ColumnsWithoutFirst(matrix, rows, columns);
        std::cout << "Number of columns without " << matrix[0][0] << ": " << count << std::endl;
        int row = FindRowWithLongestSeries(matrix, rows, columns);
        std::cout << "The row number with the longest series of identical elements: " << row + 1 << std::endl;
        DeleteMatrix(matrix, rows);
    }
    catch (const char* errorMessage) {
        std::cerr << "Error: " << errorMessage << std::endl;
        return 1;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
        return 1;
    }

    return 0;
}