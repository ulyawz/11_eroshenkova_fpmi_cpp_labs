#include <iostream>
#include <random>
#include <cmath>
#include <algorithm>
int main() {
	setlocale(LC_ALL, "RU");
	int n;
	const int MAXIMUM = 1000;
std::cout << "Введите колличество элементов массива: ";
std::cin >> n;
if (n <= 0 || n > MAXIMUM) {
	std::cout << "размер массива должен быть от 1 до " << MAXIMUM;
}
 double arr[MAXIMUM];
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
	double a, b;
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
}
double summa = 0;
for (int i = 0; i < n; i++) {
	if (arr[i] > 0) {
		summa += arr[i];
	}
} 
std::cout << "Сумма положительных элементов: " << summa<< "\n";
int elmax = 0;
int elmin = 0;
for (int i = 1; i < n; i++) {
	if (std::abs(arr[i]) > std::abs(arr[elmax])) elmax = i;
	if (std::abs(arr[i]) <= std::abs(arr[elmin])) elmin = i;
}
if (std::max(elmax, elmin) - std::min(elmax, elmin) == 1) {
	std::cout << "Между максимальным и минимальным элементом нет элементов\n";
}
else {
	double pr = 1;
	for (int i = std::min(elmax, elmin) + 1; i < std::max(elmax, elmin); i++) {
		pr *= arr[i];
	}
	std::cout << "Произведение элементов между первым максимальным и последним минимальным: " << pr << "\n";
}
for (int i = 1; i < n; i += 2) {
	for (int j = i; j<n-i-1; j += 2) {
		if ( arr[j] < arr[j + 2]) {
			std::swap(arr[j], arr[j + 2]);
		}
	}
}
std::cout << "После сортировки нечетных индексов по убыванию: ";
for (int i = 0; i < n; i++) {
	std::cout << arr[i] << " ";
}
	return 0;
}
