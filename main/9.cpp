#include <iostream>
int main() {
	setlocale(LC_ALL, "RU");
	int n;
	std::cout << "������� �������������� �����: ";
	std::cin >> n;
	if (n < 1000 || n>9999) 
	std::cout << "���� ������ �������������� �����!";

	int a = n / 1000;
	int b = (n / 100) % 10;
	int c = (n / 10) % 10;
	int d = n % 10;
	if (a == d || b == c) std::cout << "����� �������� �����������" ;
	else std::cout << "����� �� ���������";

}