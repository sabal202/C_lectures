#include <iostream>

using namespace std;

class myclass {
	double a;
public:
	void set_a(double num);
	double get_a();
};

void myclass::set_a(double num) {
	a = num;
}

double myclass::get_a() {
	return a;
}

int main() {
	double a;
	cout << "Enter num: ";
	cin >> a;
	myclass obj;
	obj.set_a(a);
	cout << "a = " << obj.get_a() << endl;
	return 0;
}