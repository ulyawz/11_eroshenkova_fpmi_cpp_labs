#include <iostream>
int main() {
	setlocale(LC_ALL, "RU");
	int a, b;
	std::cout << "¬ведите значени€ a и b: ";
	std::cin >> a >> b;
	for (int divisible = a; divisible <= b; divisible++) {
		if (divisible > 1) {
			int divider;
			for (divider = 2; divider < divisible && divisible % divider != 0; divider++);
				if (divider == divisible) 
					std::cout << divisible << " ";
		}

	}
}
  