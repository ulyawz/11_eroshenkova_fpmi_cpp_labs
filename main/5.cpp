#include <iostream>
int main() {
	setlocale(LC_ALL, "RU");
	int n, m;
	std::cout << "Введите числа n и m: ";
	std::cin >> n >> m;
	std::cout << "Общие делители: ";
	for (int x = 1; x <= std::min(n, m); x++) {
		if (n % x == 0 && m % x == 0) {
			std::cout << x << " ";
	}
	}
	return 0;
}