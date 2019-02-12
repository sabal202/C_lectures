#include<iostream>
using namespace std;

class myclass {
public:
	int j;
	myclass(int i) : j(i) {}
	int sq() { return j * j; }
};

int main()
{
	myclass ob1(3), ob2(5);
	myclass *p1, *p2;

	p1 = &ob1;
	p2 = &ob2;

	cout << "j1=" << p1->j << " j2=" << p2->j << endl;
	cout << "sq1=" << p1->sq() << " sq2=" << p2->sq() << endl;
	return 0;
}
