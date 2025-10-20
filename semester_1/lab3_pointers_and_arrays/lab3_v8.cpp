#include <iostream>
#include <random>
#include <cmath>
#include <algorithm>
int main() {
	setlocale(LC_ALL, "RU");
	int n;
	const int MAXIMUM = 1000;
std::cout << "������� ����������� ��������� �������: ";
std::cin >> n;
if (n <= 0 || n > MAXIMUM) {
	std::cout << "������ ������� ������ ���� �� 1 �� " << MAXIMUM;
}
 double arr[MAXIMUM];
int choice;
std::cout << "��� ��������� ������:\n" << "1) � ����������\n" << "2) ��������\n";
std::cin >> choice;
if (choice == 1) {
	std::cout << "������� " << n << " ��������� �������: ";
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
}
else if (choice == 2) {
	double a, b;
	std::cout << "������� ������� ���������: ";
std::cin >> a >> b;
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> dist(a, b);
std::cout << "������ ������: ";
for (int i = 0; i < n; i++) {
	arr[i] = dist(gen);
	std::cout << arr[i] << " ";
}
std::cout << "\n";
}
else {
	std::cout << "������� 1 ��� 2\n";
}
double summa = 0;
for (int i = 0; i < n; i++) {
	if (arr[i] > 0) {
		summa += arr[i];
	}
} 
std::cout << "����� ������������� ���������: " << summa<< "\n";
int elmax = 0;
int elmin = 0;
for (int i = 1; i < n; i++) {
	if (std::abs(arr[i]) > std::abs(arr[elmax])) elmax = i;
	if (std::abs(arr[i]) <= std::abs(arr[elmin])) elmin = i;
}
if (std::max(elmax, elmin) - std::min(elmax, elmin) == 1) {
	std::cout << "����� ������������ � ����������� ��������� ��� ���������\n";
}
else {
	double pr = 1;
	for (int i = std::min(elmax, elmin) + 1; i < std::max(elmax, elmin); i++) {
		pr *= arr[i];
	}
	std::cout << "������������ ��������� ����� ������ ������������ � ��������� �����������: " << pr << "\n";
}
for (int i = 1; i < n; i += 2) {
	for (int j = i; j<n-i-1; j += 2) {
		if ( arr[j] < arr[j + 2]) {
			std::swap(arr[j], arr[j + 2]);
		}
	}
}
std::cout << "����� ���������� �������� �������� �� ��������: ";
for (int i = 0; i < n; i++) {
	std::cout << arr[i] << " ";
}
	return 0;
}
