#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class strtype {
    char *p;
public:
    strtype(const char *s);
    strtype(const strtype &o);
    ~strtype() {
        cout << "delete " << p << endl;
        delete[] p;
    }
    char *get() { return p; }
};

strtype::strtype(const char *s) {
    int r;
    r = strlen(s) + 1;
    p = new char[r];
    strcpy(p, s);
}

strtype::strtype(const strtype &o) {
    int r;
    r = strlen(o.p) + 1;
    p = new char[r];
    strcpy(p, o.p);
    p[strlen(o.p) - 1] = '0';
}

void show(strtype x) {
    char *s;
    s = x.get();
    cout << s << "\n";
}

int main() {
    strtype a("First"), b("Second");
    show(a);
    show(b);
    return 0;
}

/*
Firs0
delete Firs0
Secon0
delete Secon0
delete Second
delete First
*/