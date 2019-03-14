#include <iostream>
using namespace std;

int main() {
	double a = 1, b;
	while (a != 0)
	{
		cout << "Input a, b (a=0 ->exit)" << endl;
		cin >> a >> b;
		try {
			if (!b) throw b;
			cout << "rez=" << a / b << endl;
		}
		catch (...) {
			cout << "ZERO!!!" << endl;
		}
	}

	return 0;
}
