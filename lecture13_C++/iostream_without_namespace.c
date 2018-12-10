#include <iostream>
#include <cmath>

int main() {
	printf("Hello C++\n");
	int a, b = 10;
	double c;
	scanf("%lf", &c);
	c = sqrt(c);
	std::cout << "a = ";
	std::cin >> a;
	std::cout << "b = " << b << " a = " << a << " c = " << c << std::endl;

	return 0;
}