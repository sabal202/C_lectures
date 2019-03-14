#include <iostream>
using namespace std;

template <class X> X myfunc(X &a) {
	return a += a;
}

float myfunc(float &a) {
	return a *= a;
}

template <class X, class Y> X myfunc(X &c, Y &m) {
	return c *= m;
}

int main() {
	int		i = 10;
	double	d = 1.3;
	cout << "i = " << i << "\td = " << d << endl;
	myfunc(i);
	myfunc(d);
	cout << "i = " << i << "\td = " << d << endl;

	float	f = 1.5;
	cout << "f = " << f << endl;

	myfunc(f);
	cout << "f = " << f << endl;

	int		j = 5;
	double	k = 2.5;

	cout << "j = " << j << "\tk = " << k << endl;

	myfunc(k, j);
	cout << "j = " << j << "\tk = " << k << endl;

	return 0;
}
