#include <iostream>
int main() {
	setlocale(LC_ALL, "RU");
	int n;
	std::cout << "������� ����� n: ";
	std::cin >> n;
	int sum;
	sum = 0;
	int pr;
	pr = 1;
	for (int x = 1; x <= n; x++) {
		if (x % 2 == 0) sum = sum + x;
		else pr = pr * x;
	}
	std::cout << "����� ������: " << sum << std::endl;
	std::cout << "������������ ��������: " << pr << std::endl;
	return 0;
}