#include<iostream>
using namespace std;
void swap(int, int);
void swap1(int*, int*);
void swap2(int&, int&);
// reference = hidden pointer
int main() {
	int a = 10, b = 20;
	cout << "a=" << a << " b=" << b << endl << endl;
	swap(a, b);
	cout << "a=" << a << " b=" << b << endl;
	a = 10, b = 20;
	swap1(&a, &b);
	cout << "a1=" << a << " b1=" << b << endl;
	a = 10, b = 20;
	swap2(a, b);
	cout << "a2=" << a << " b2=" << b << endl;
	return 0;
}

void swap(int c, int d) {
	int t = c;
	c = d;
	d = t;
	cout << "c=" << c << " d=" << d << endl;
}
void swap1(int *c, int *d) {
	int t = *c;
	*c = *d;
	*d = t;
	cout << "c1=" << *c << " d1=" << *d << endl;
}



void swap2(int &c, int &d) {
	int t = c;
	c = d;
	d = t;
	cout << "c2=" << c << " d2=" << d << endl;
}
