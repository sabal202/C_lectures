#include <iostream>
using namespace std;

class B {
	int x;
public:
	void set_x(int n) { x = n; }
	int get_x() { return x; }
	void show_x() { cout << "x=" << x << endl; }
};

// Класс наследуется как закрытый
class D : private B {
	int y;
public:
	//   void set_y(int n) { y = n; }
	void set_xy(int n, int m) { set_x(n); y = m; }
	void show_xy() { show_x(); cout << "y=" << y << endl; }
	void mul() { cout << "mul=" << get_x() * y << endl; }
};

int main()
{
	B ob;
	D ob1;

	ob.set_x(5);
	ob.show_x();

	ob1.set_xy(15, 20);

	ob1.show_xy();
	ob1.mul();
	system("pause");
	return 0;
}
