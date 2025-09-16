#include <iostream>
int main() {
	setlocale(LC_ALL, "RU");
	int a, b;
	std::cout << "¬ведите значени€ a и b: ";
	std::cin >> a >> b;
	for (int x = a; x <= b; x++) {
		if (x > 1) {
			int c;
			for (c = 2; c < x && x % c != 0; c++);
				if (c == x) 
					std::cout << x << " ";
		}
		

	}
}
  