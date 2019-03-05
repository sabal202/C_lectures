#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;

class area {
	double a, b;
public:
	void set_a_b(double x, double y) { a = x; b = y; }
	void get_a_b(double &x, double &y) { x = a; y = b; }
	virtual double get_area() = 0;
};

class el : public area {
public:
	double get_area() { double x, y; get_a_b(x, y); return 3.14 * x * y; }
};

class re : public area {
public:
	double get_area() { double x, y; get_a_b(x, y); return x * y; }
};

int main()
{
	area *p;
	el e;
	re r;
	e.set_a_b(4, 5);
	r.set_a_b(2, 3);

	float j;
	srand(time(NULL));
	j = rand() % 100 / 100.0;
	cout << "j=" << j << endl;

	if ((j > 0.5))
	{
		p = &e;  cout << "S (ellipse)=" << p->get_area() << endl;
	}

	else
	{
		p = &r; cout << "S (rectangle)=" << p->get_area() << endl;
	}

	return 0;
}
