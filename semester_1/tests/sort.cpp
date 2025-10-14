#include <iostream>
int main() {
	int n;
	const int MAXIMUM = 100;
	int a[MAXIMUM];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		for (i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; ++j) {
				if (std::abs(a[j]) > std::abs(a[j + 1])) {
					int tmp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = tmp;
				}

			}
		}
	}
		for (int i = 0; i < n; i++) {
			std::cout << a[i];
	}
}