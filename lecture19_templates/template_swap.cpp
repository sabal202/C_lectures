#include <iostream>
using namespace std;

template <class X> void swaping(X &a, X &b) {
	X c;

	c = a;
	a = b;
	b = c;
}

int main() {
	double	i = 5.5, j = 7.7;
	char	a = 'a', b = 'z';

	cout << "i = " << i << "\tj = " << j << endl;
	cout << "a = " << a << "\tb = " << b << endl;

	swaping(i, j);
	swaping(a, b);

	cout << "i = " << i << "\tj = " << j << endl;
	cout << "a = " << a << "\tb = " << b << endl;

	return 0;
}
