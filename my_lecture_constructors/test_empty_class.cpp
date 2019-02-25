#include<iostream>
using namespace std;

class myclass {
    int *p;
    int a;
public:
    myclass(int a);
    ~myclass() { 
        delete p; 
    }
};
myclass::myclass(int a) {
    this->a = a;
    //a = a; - ни к чему не приведет 
    p = &a;
    cout << "a = " << a << endl << "p = " << p << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	myclass ob(5);
	cout << &ob;
	return 0;
}