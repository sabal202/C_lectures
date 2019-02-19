#include <iostream>
using namespace std;

class omega;
int key[4];
class alpha {
	int first[2];
public:
	alpha() {
		cout << "Input first 2 numbers:" << endl;
		for (int i = 0; i < 2; i++) {
			cout << "i=" << i + 1 << "\t  ";
			cin >> first[i];
			cout << endl;
		}
	}
	int *concat(omega);
};

class omega {
	int second[2];
public:
	omega() {
		cout << "Input second 2 numbers:" << endl;
		for (int i = 0; i < 2; i++) {
			cout << "i=" << i + 1 << "\t  ";
			cin >> second[i];
			cout << endl;
		}
	}
	friend int* alpha::concat(omega);
};

int* alpha::concat(omega b) {
	for (int i = 0; i < 4; i += 2) {
		key[i] = first[i / 2];
		key[i + 1] = b.second[i / 2];
	}
	return key;
}

int main() {
	alpha ob1;
	omega ob2;
	ob1.concat(ob2);
	for (int i = 0; i < 4; i++)
		cout << "i = " << i + 1 << "\t  " << key[i] << endl;
	return 0;
}
