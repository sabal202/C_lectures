#include "matrix.h"

template <class X>
matrix<X>::matrix(int n, int m) {
    this->mat = (X **) calloc(n, sizeof(X*));

    for (int i = 0; i < n; ++i)
        this->mat[i] = (X*) calloc(m, sizeof(X));
}

template <class X>
matrix<X>::matrix(X x) {

}

template <class X>
void matrix<X>::get(X M) {

}

template <class X>
matrix<X>:: operator * (matrix<X> B) {

}


