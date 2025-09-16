#include <iostream>
int main() {
	setlocale(LC_ALL, "RU");
	int n;
	std::cout << "Введите четырехзначное число: ";
	std::cin >> n;
	if (n < 1000 || n>9999) 
	std::cout << "Надо ввести четырехзначное число!";

	int a = n / 1000;
	int b = (n / 100) % 10;
	int c = (n / 10) % 10;
	int d = n % 10;
	if (a == d || b == c) std::cout << "Число является палиндромом" ;
	else std::cout << "Число не палиндром";

}