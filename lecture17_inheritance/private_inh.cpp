#include <iostream>
using namespace std;

class B {
	int x;
public:
	void set_x(int n) { x = n; }
	void show_x() { cout << "x=" << x << endl; }
};

// Класс наследуется как закрытый
class D : private B {
	int y;
public:
	void set_y(int n) { y = n; }
	void show_y() { cout << "y=" << y << endl; }
};

int main()
{
	B ob;
	D ob1;

	ob.set_x(5);
	ob.show_x();

	//  ob1.set_x(10); // ошибка (функция теперь является private)
	ob1.set_y(20);

	//    ob1.show_x(); // ошибка  (функция теперь является private)
	ob1.show_y();
	system("pause");

	return 0;
}
