#include <iostream>
using namespace std;

class B {
protected:
	int x, y;
public:
	void set_xy(int n, int m) { x = n; y = m; }
};

class D : public B {
	int z;
public:
	void set_z(int n) { z = n; }

	// эта функция имеет доступ к переменным x, y класса base
	void mul() {
		cout << "mul=" << x * y * z << endl;
	}
};

int main()
{
	D ob;

	ob.set_xy(2, 3);
	ob.set_z(5);

	ob.mul();
	system("pause");
	return 0;
}
