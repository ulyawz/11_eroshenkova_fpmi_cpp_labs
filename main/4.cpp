#include <iostream>
int main() {
	setlocale(LC_ALL, "RU");
	int k;
	std::cout << "������� �������� k: ";
	std::cin >> k;
	int a = 1;
	for (int x = k; x > 1; x -= 2) {
		a = a * x;
	}
	std::cout << k << "!!= " << a;
	if (k < 0) {
		std::cout << "������� ��������������� �����!";
	}
	return 0;

}