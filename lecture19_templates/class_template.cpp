#include <iostream>

using namespace std;

template <class X, class Y> class myclass {
	X x;
	Y y;
public:
	myclass(X a, Y b): x(a), y(b) {}
	void show() {
		cout << x << ' ' << y << endl;
	}
};

template <> class myclass <float, float> {
	float x;
	float y;
public:
	myclass(float a, float b): x(a), y(b) {}
	void show() {
		cout << x * y << endl;
	}
};

int main() {
	myclass<int, double> ob1(10, 0.23);
	myclass<char, const char *> ob2('X', "Template");
	myclass<float, float> ob3(5.2, 1.1);

	ob1.show();
	ob2.show();
	ob3.show();

	return 0;
}