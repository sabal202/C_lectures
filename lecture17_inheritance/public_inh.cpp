#include <iostream>
#include <windows.h>
using namespace std;

class B {
	int x;
public:
	int y;
	void set_xy(int n, int m) { x = n; y = m; }
	void mul_B_xy() { cout << "mul_B_xy=" << x * y << endl; }
};

class D : public B {
	int z;
public:
	void set_z(int n) { z = n; }
	//	void mul_D_xy(){cout<<"mul_D_xy="<<x*y<<endl;}	// ошибка
	void mul_yz() { cout << "mul_yz=" << y * z << endl; }

};


int main()
{
	B ob;
	D ob1;
	ob.set_xy(5, 7);
	ob1.set_xy(10,
	           15); // инициализация членов базового класса в D
	ob1.set_z(
	    20);        // инициализация члена производного класса D

	ob.mul_B_xy();
	ob1.mul_B_xy();
	//		ob1.mul_D_xy();	// ошибка
	ob1.mul_yz();
	system("pause");
	return 0;
}

/*
class name_child : spec base_class {
// body
}
*/