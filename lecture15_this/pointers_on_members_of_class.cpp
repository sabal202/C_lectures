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
	int myclass::*d;
	int (myclass::*f)();
	myclass ob1(3), ob2(5);
	myclass *p1, *p2;
	
	d = &myclass::j;
	f = &myclass::sq;
	cout << ".*\n";
	cout << "j1=" << ob1.*d << " j2=" << ob2.*d << endl;
	cout << "sq1=" << (ob1.*f)() << " sq2=" << (ob2.*f)() << endl;

	p1 = &ob1;
	p2 = &ob2;
	cout << "->\n";
	cout << "j1=" << p1->*d << " j2=" << p2->*d << endl;
	cout << "sq1=" << (p1->*f)() << " sq2=" << (p2->*f)() << endl;
	return 0;
}
