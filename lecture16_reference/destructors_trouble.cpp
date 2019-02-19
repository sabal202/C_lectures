#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class strtype {
    char *p;
  public:
    strtype(char *s);
    // strtype(const char *s);
    ~strtype() {
        cout << "delete " << p << endl;
        delete[] p;
    }
    char *get() {return p;}
};

strtype::strtype(char *s) {
    // strtype::strtype(const char *) {
    int l;
    l = strlen(s) + 1;
    p = new char[l];
    strcpy(p, s);
}

void show(strtype x) {
    char *s;
    s = x.get();
    cout << s << "\n";
}

int main() {
    strtype a((char *)"First"), b((char *)"Second");
    // strtype a("First"), b("Second");
    show(a);
    show(b);
    return 0;
}
