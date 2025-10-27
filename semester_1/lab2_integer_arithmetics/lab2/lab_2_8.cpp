#include <iostream>
int main() {
	int n;
	std::cin >> n;
	int x = 1;
	while (n > 1) {
		int d = n / x;
		x++;
		for (int i = 2; i < x && i % x != 0; i++) {
			if (x == i) {
				std::cout << x;
			}
		}
	}


}