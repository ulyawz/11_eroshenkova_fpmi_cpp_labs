#include <iostream>;
#include <random>;
#include <cmath>;
int main() {
	setlocale(LC_ALL, "RU");
	int n;
	const int MAXIMUM = 1000;
std::cout << "������� ����������� ��������� �������: ";
std::cin >> n;
if (n <= 0 || n > MAXIMUM) {
	std::cout << "������ ������� ������ ���� �� 1 �� " << MAXIMUM;
}
 double mas[MAXIMUM];
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
	double a, b;
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
}
double summa = 0;
for (int i = 0; i < n; i++) {
	if (mas[i] > 0) {
		summa += mas[i];
	}
} 
std::cout << "����� ������������� ���������: " << summa<< "\n";
int elmax = 0;
int elmin = 0;
for (int i = 1; i < n; i++) {
	if (std::abs(mas[i]) > std::abs(mas[elmax])) elmax = i;
	if (std::abs(mas[i]) <= std::abs(mas[elmin])) elmin = i;
}
if (std::max(elmax, elmin) - std::min(elmax, elmin) == 1) {
	std::cout << "����� ������������ � ����������� ��������� ��� ���������\n";
}
else {
	double pr = 1;
	for (int i = std::min(elmax, elmin) + 1; i < std::max(elmax, elmin); i++) {
		pr *= mas[i];
	}
	std::cout << "������������ ��������� ����� ������ ������������ � ��������� �����������: " << pr << "\n";
}
for (int i = 1; i < n; i += 2) {
	for (int j = i; j+2<n; j += 2) {
		if ( mas[j] < mas[j + 2]) {
			std::swap(mas[j], mas[j + 2]);
		}
	}
}
std::cout << "����� ���������� �������� �������� �� ��������: ";
for (int i = 0; i < n; i++) {
	std::cout << mas[i] << " ";
}
	return 0;
}
