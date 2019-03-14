#include <cstdlib>
#include <iostream>

template <class X>
class matrix {
    X **mat;
    int n, m;
public:
    matrix(int n, int m);
    matrix(const matrix<X> & other);
    ~matrix() {
        for (int i = 0; i < this->n; i++)
            delete[] mat[i];

        delete[] mat;
    }

    void to_triag();
    X det(); 

    matrix<X>& operator = (const matrix<X> &other);
    // matrix<X> operator + (const matrix<X> &other);
    // matrix<X> operator - (const matrix<X> &other);
    // matrix<X> operator * (const matrix<X> &other);
    // matrix<X> operator / (const matrix<X> &other);

    X* &operator[](int ind) { return this->mat[ind]; }
    const X* &operator[](int ind) const { return this->mat[ind]; }
    template <class I> matrix<X> operator *= (I l);
    template <class I> matrix<X> operator /= (I l);

    friend std::ostream & operator<< (std::ostream &os, const matrix<X> &M) {
        for (int i = 0; i < M.n; ++i) {
            for (int j = 0; j < M.m; ++j)
                os << M.mat[i][j] << " ";

            os << std::endl;
        }

        return os;
    }
};

template <class X>
matrix<X>::matrix(int n, int m) {
    this->n = n;
    this->m = m;
    this->mat = (X **) calloc(n, sizeof(X*));

    for (int i = 0; i < n; ++i)
        this->mat[i] = (X*) calloc(m, sizeof(X));
}

template <class X>
matrix<X>::matrix(const matrix<X> & other) {
    for (int i = 0; i < this->n; ++i) {
        for (int j = 0; j < this->m; ++j)
            this->mat[i][j] = other[i][j];
    }
}

template <class X>
matrix<X>& matrix<X>::operator = (const matrix<X> &other) {
    this->n = other.n;
    this->m = other.m;

    if (this->mat != nullptr) {
        for (int i = 0; i < this->n; i++)
            delete[] mat[i];

        delete[] mat;
    }

    this->mat = (X **) calloc(other.n, sizeof(X*));

    for (int i = 0; i < other.n; ++i)
        this->mat[i] = (X*) calloc(other.m, sizeof(X));

    return *this;
}

template <class X>
void matrix<X>::to_triag() {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            X k = this->mat[j][i] / this->mat[i][i];
            for (int l = 0; l < m; ++l) 
                this->mat[j][l] -= k * this->mat[i][l];
        }
    }
}

template <class X>
X matrix<X>::det() {
    to_triag();
    X res = 1;
    for (int i = 0; i < this->n; i++) {
        res *= this->mat[i][i];
    }
    return res;
}
