#include <iostream>
#include <random>
#include <cmath>
int main() {
    setlocale(LC_ALL, "RU");
    int n;
    std::cout << "������� ���������� ��������� �������: ";
    std::cin >> n;
    if (n <= 0) {
        std::cout << "������ ������� ������ ���� �������������!\n";
        return 0;
    }
    int* mas = new int[n]; 
    int choice;
    std::cout << "��� ��������� ������:\n" << "1) � ����������\n" << "2) ��������\n";
    std::cin >> choice;
    if (choice == 1) {
        std::cout << "������� " << n << " ��������� �������: ";
        for (int i = 0; i < n; i++) {
            std::cin >> mas[i];
        }
    }
    else if (choice == 2) {
        int a, b;
        std::cout << "������� ������� ���������: ";
        std::cin >> a >> b;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dist(a, b);
        std::cout << "������ ������: ";
        for (int i = 0; i < n; i++) {
            mas[i] = dist(gen);
            std::cout << mas[i] << " ";
        }
        std::cout << "\n";
    }
    else {
        std::cout << "������� 1 ��� 2\n";
        delete[] mas;
    }
    int elmax = 0, elmin = 0;
    for (int i = 1; i < n; i++) {
        if (mas[i] > mas[elmax]) elmax = i;
        if (mas[i] < mas[elmin]) elmin = i;
    }
    if (std::max(elmax, elmin) - std::min(elmax, elmin) == 1) {
        std::cout << "����� ������������ � ����������� ��������� ��� ���������\n";
    }
    else {
        int pr = 1;
        for (int i = std::min(elmax, elmin) + 1; i < std::max(elmax, elmin); i++)
            pr *= mas[i];
        std::cout << "������������ ��������� ����� max � min = " << pr << "\n";
    }
    int N;
    std::cout << "������� ���������� ��������� ��� �������� � �����: ";
    std::cin >> N;

    if (N < 0 || N > n) {
        std::cout << "���������� ������� " << N << " ���������!\n";
    }
    else {
        n -= N;
        std::cout << "������ ����� �������� ��������� " << N << " ���������:\n";
        for (int i = 0; i < n; i++)
            std::cout << mas[i] << " ";
        std::cout << "\n";
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (std::abs(mas[j]) > std::abs(mas[j + 1])) {
                double tmp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = tmp;
            }
        }
    }
    std::cout << "������, ������������� �� ����������� �������:\n";
    for (int i = 0; i < n; i++)
        std::cout << mas[i] << " ";

    std::cout << "\n";

    delete[] mas;
    return 0;
}
