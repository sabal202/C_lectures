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
    cout << "myclass b(a);" << endl;
    myclass b(a);
    cout << "myclass c = b;" << endl;
    myclass c = b;
    cout << "c = func(5);" << endl;
    myclass d = func(5);
    cout << "End" << endl;
    return 0;
}

/* For MinGW and CLang
myclass a(5);
 Constructor 0x61fe30
myclass b(a);
 Constructor copy 0x61fe20
myclass c = b;
 Constructor copy 0x61fe10
c = func(5);
   myclass temp(size);
    Constructor 0x61fe00
   return temp;
End
 Destructor 0x61fe00
 Destructor 0x61fe10
 Destructor 0x61fe20
 Destructor 0x61fe30
 */

/* For Microsoft vc++
myclass a(5);
 Constructor 008FFA04
myclass b(a);
 Constructor copy 008FF9F4
myclass c = b;
 Constructor copy 008FF9E4
c = func(5);
   myclass temp(size);
 Constructor 008FF8C8
   return temp;
 Constructor copy 008FF9D4
 Destructor 008FF8C8
End
 Destructor 008FF9D4
 Destructor 008FF9E4
 Destructor 008FF9F4
 Destructor 008FFA04
 */