#include <iostream>
#include <random>
#include <cmath>

int main() {
    setlocale(LC_ALL, "RU");
    int n;
    std::cout << "Введите количество элементов массива: ";
    std::cin >> n;
    if (n <= 0) {
        std::cout << "Размер массива должен быть положительным!\n";
        return 0;
    }
    double* arr = new double[n];
    int choice;
    std::cout << "Как заполнять массив:\n" << "1) с клавиатуры\n" << "2) рандомно\n";
    std::cin >> choice;
    if (choice == 1) {
        std::cout << "Введите " << n << " элементов массива: ";
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
    }
    else if (choice == 2) {
        int a, b;
        std::cout << "Введите границы интервала: ";
        std::cin >> a >> b;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dist(a, b);
        std::cout << "Рандом массив: ";
        for (int i = 0; i < n; i++) {
            arr[i] = dist(gen);
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
    else {
        std::cout << "Введите 1 или 2\n";
        delete[] arr;
        return 0;                       
    }
    int elmax = 0, elmin = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[elmax]) elmax = i;
        if (arr[i] < arr[elmin]) elmin = i;
    }
     if (std::abs(elmax - elmin) == 1) {
        std::cout << "Между максимальным и минимальным элементом нет элементов\n";
    }
    else {
        double pr = 1.0;               
        for (int i = std::min(elmax, elmin) + 1; i < std::max(elmax, elmin); i++)
            pr *= arr[i];
        std::cout << "Произведение элементов между max и min = " << pr << "\n";
    }

    int N;
    std::cout << "Введите количество минимальных элементов для удаления: ";
    std::cin >> N;

    if (N < 0 || N > n) {
        std::cout << "Невозможно удалить " << N << " элементов!\n";
    }
    else {
        for (int k = 0; k < N; k++) {
            int minIndex = n - 1;
            for (int i = n - 2; i >= 0; i--) {
                if (arr[i] < arr[minIndex]) minIndex = i;
            }
            for (int i = minIndex; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }
            n--;
        }

        std::cout << "Массив после удаления " << N << " минимальных элементов:\n";
        for (int i = 0; i < n; i++)
            std::cout << arr[i] << " ";
        std::cout << "\n";
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (std::abs(arr[j]) > std::abs(arr[j + 1])) {
                double tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    std::cout << "Массив, упорядоченный по возрастанию модулей:\n";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    delete[] arr;
    return 0;
}
