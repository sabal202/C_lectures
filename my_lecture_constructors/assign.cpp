//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
using namespace std;

class myclass {
public:
    int size;
    int* data;
    myclass(int size);
    myclass(const myclass &other);
    ~myclass() {
        cout << " Destructor " << this << endl;
        delete[] data;
    }
};

myclass::myclass(int size) {
    this->size = size;
    this->data = new int[size];

    for (int i = 0; i < size; i++) {
        data[i] = i;
    }
    cout << " Constructor " << this << endl;
}

myclass::myclass(const myclass &other) {
    this->size = other.size;
    this->data = new int[other.size];

    for (int i = 0; i < other.size; i++) {
        this->data[i] = other.data[i];
    }
    cout << " Constructor copy " << this << endl;
}

myclass func(int size) {
    cout << "   myclass temp(size);" << endl;
    myclass temp(size + 1);
    cout << "   return temp;" << endl;
    return temp;
}

int main() {
    cout << "myclass a(5);" << endl;
    myclass a(5);
    cout << "myclass b(5);" << endl;
    myclass b(5);

    a = b;


    return 0;
}