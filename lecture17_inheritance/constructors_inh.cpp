#include <iostream>
using namespace std;

class B {
protected:
	int i;
public:
	B(int x) { i = x; cout << " Constuctor B" << endl; }
	~B() { cout << " Destructor B" << endl; }
};

class D : public B {
	int j;
public:
	D(int x, int y) : B(y) {
		j = x; cout << " Constuctor D" << endl;
		cout << "i=" << i << " j=" << j << endl;
	}
	~D() { cout << " Destructor D" << endl; }
};
int main()
{
	D ob(5, 10);
	system("pause");
	return 0;
}
