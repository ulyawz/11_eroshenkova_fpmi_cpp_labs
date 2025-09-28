#include <iostream>;
#include <random>;
int main() {
	setlocale(LC_ALL, "RU");
	int n;
	const int maximum = 1000;
std::cout << "Введите колличество элементов массива: ";
std::cin >> n;
if (n <= 0 || n > maximum) {
	std::cout << "размер массива должен быть от 1 до " << maximum;
}
int mas[maximum];
int choice;
std::cout << "Как заполнять массив:\n" << "1) с клавиатуры\n" << "2) рандомно\n";
std::cin >> choice;
if (choice == 1) {
	std::cout << "Введите " << n << " элементов массива: ";
	for (int i = 0; i < n; i++) {
		std::cin >> mas[i];
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
	mas[i] = dist(gen);
	std::cout << mas[i] << " ";
}
std::cout << "\n";
}
else {
	std::cout << "Введите 1 или 2\n";
}
int summa = 0;
for (int i = 0; i < n; i++) {
	if (mas[i] > 0) summa += mas[i];
} 
std::cout << "Сумма положительных элементов: " << summa<< "\n";
int elmax = 0;
int elmin = 0;
for (int i = 1; i < n; i++) {
	if (mas[i] > mas[elmax]) elmax = i;
	if (mas[i] <= mas[elmin]) elmin = i;
}
if (std::max(elmax, elmin) - std::min(elmax, elmin) == 1) {
	std::cout << "Между максимальным и минимальным элементом нет элементов\n";
}
else {
	int pr = 1;
	for (int i = std::min(elmax, elmin) + 1; i < std::max(elmax, elmin); i++) {
		pr *= mas[i];
	}
	std::cout << "Произведение элементов между первым максимальным и последним минимальным: " << pr << "\n";
}
for (int i = 1; i < n; i += 2) {
	for (int j = i + 2; j < n; j += 2) {
		if (mas[i] < mas[j]) {
			int x = mas[i];
			mas[i] = mas[j];
			mas[j] = x;
		}
	}
}
std::cout << "После сортировки нечетных индексов по убыванию: ";
for (int i = 0; i < n; i++) {
	std::cout << mas[i] << " ";
}
	return 0;
}
