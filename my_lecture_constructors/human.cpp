//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
using namespace std;

/*class human {
    int age, weight, name;
public:
    human(int name) {
        this->name = name;
        this->age = 0;
        this->weight = 0;
    }
    human(int name, int age) {
        this->name = name;
        this->age = age;
        this->weight = 0;
    }
    human(int name, int age, int weight) {
        this->name = name;
        this->age = age;
        this->weight = weight;
    }
};*/

class human {
    int age, weight, name;
public:
    human(int name) {
        this->name = name;
        this->age = 0;
        this->weight = 0;
        cout << "1" << endl;
    }
    human(int name, int age) : human(name) {
        this->age = age;
        cout << "2" << endl;
    }
    human(int name, int age, int weight) : human(name, age) {
        this->weight = weight;
        cout << "3" << endl;
    }
};

int main() {
    human h(1, 1, 1);
    return 0;
}