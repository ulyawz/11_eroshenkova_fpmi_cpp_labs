#include <iostream>
int main() {
	setlocale(LC_ALL, "RU");
	int n;
	std::cout << "¬ведите количество n: ";
	std::cin >> n;

	int a = 1;
	int sum = 0;
	for (int x = 0; x < n; x++) {
		sum = sum + a;
		a = a + 2;
	}
	std::cout << "—умма первых n нечетных чисел: " << sum;
}